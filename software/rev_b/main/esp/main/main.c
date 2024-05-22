/* BSD Socket API Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <string.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "protocol_examples_common.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#include "driver/i2c.h"
#include "driver/mcpwm_prelude.h"




#define PORT                        CONFIG_EXAMPLE_PORT
#define KEEPALIVE_IDLE              CONFIG_EXAMPLE_KEEPALIVE_IDLE
#define KEEPALIVE_INTERVAL          CONFIG_EXAMPLE_KEEPALIVE_INTERVAL
#define KEEPALIVE_COUNT             CONFIG_EXAMPLE_KEEPALIVE_COUNT

#define MAX_SIZE 1024

static const char *TAG = "i2c";

#define I2C_MASTER_SCL_IO           25          /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           26          /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              0           /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ          400000      /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE   0           /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0           /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS       1000
#define MPU6050_SENSOR_ADDR         0x68        /*!< Slave address of the MPU9250 sensor */
#define MPU6050_PWR_MGMT_1_REG_ADDR 0x6B        /*!< Register addresses of the power managment register */
#define MPU6050_RESET_BIT           7
#define MPU6050_ACCEL_XOUT_H        0x3B
#define MPU6050_ACCEL_XOUT_L        0x3C
#define MPU6050_ACCEL_YOUT_H        0x3D
#define MPU6050_ACCEL_YOUT_L        0x3E
#define MPU6050_ACCEL_ZOUT_H        0x3F
#define MPU6050_ACCEL_ZOUT_L        0x40
#define MPU6050_TEMP_OUT_H          0x41
#define MPU6050_TEMP_OUT_L          0x42
#define MPU6050_GYRO_XOUT_H         0x43
#define MPU6050_GYRO_XOUT_L         0x44
#define MPU6050_GYRO_YOUT_H         0x45
#define MPU6050_GYRO_YOUT_L         0x46
#define MPU6050_GYRO_ZOUT_H         0x47
#define MPU6050_GYRO_ZOUT_L         0x48
#define NUM_REGS                    14

#define SERVO_PULSE_GPIO             32        // GPIO connects to the PWM signal line
#define SERVO_TIMEBASE_RESOLUTION_HZ 1000000  // 1MHz, 1us per tick
#define SERVO_TIMEBASE_PERIOD        255    // 20000 ticks, 20ms

#define CMD_SAMPLE_ACCEL_X '0' 
#define CMD_SAMPLE_ACCEL_Y '1' 
#define CMD_SAMPLE_ACCEL_Z '2' 
#define CMD_SAMPLE_GYRO_X  '3' 
#define CMD_SAMPLE_GYRO_Y  '4' 
#define CMD_SAMPLE_GYRO_Z  '5' 


struct Sensor {
   int16_t accel_x;   
   int16_t accel_y;   
   int16_t accel_z;    
   int16_t gyro_x;   
   int16_t gyro_y;   
   int16_t gyro_z;   
}; 

struct Config {
   uint8_t menu;
   uint8_t motor_stby;
   uint8_t motor_a_dir; 
   uint8_t motor_a_pwm; 
   uint8_t motor_b_dir; 
   uint8_t motor_b_pwm; 
}; 

mcpwm_cmpr_handle_t comparator;

MessageBufferHandle_t buf_sensor;
MessageBufferHandle_t buf_config;

static esp_err_t mpu9250_register_read(uint8_t reg_addr, uint8_t *data, size_t len)
{
    return i2c_master_write_read_device(
      I2C_MASTER_NUM, 
      MPU6050_SENSOR_ADDR, 
      &reg_addr, 
      1, 
      data, 
      len, 
      I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);
}

static esp_err_t mpu9250_register_write_byte(uint8_t reg_addr, uint8_t data)
{
    int ret;
    uint8_t write_buf[2] = {reg_addr, data};

    ret = i2c_master_write_to_device(
      I2C_MASTER_NUM, 
      MPU6050_SENSOR_ADDR,
      write_buf, 
      sizeof(write_buf), 
      I2C_MASTER_TIMEOUT_MS / portTICK_PERIOD_MS);

    return ret;
}

static esp_err_t i2c_master_init(void)
{
    int i2c_master_port = I2C_MASTER_NUM;

    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };

    i2c_param_config(i2c_master_port, &conf);

    return i2c_driver_install(i2c_master_port, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}
static void do_retransmit(const int sock){ 
   int len;
   char str[MAX_SIZE]; 
   struct Sensor s;
   struct Config c;

   // Handle socket 
   do {
      len = recv(sock, str, sizeof(str) - 1, 0);
      if (len < 0) {
         ESP_LOGE(TAG, "Error occurred during receiving: errno %d", errno);
      } else if (len == 0) {
         ESP_LOGW(TAG, "Connection closed");
      } else {
         // Push the config to the timer process  
         if(pdFALSE == xMessageBufferIsFull(buf_config)){
            c.menu        = (uint8_t)str[1];
            c.motor_stby  = 0;
            c.motor_a_dir = 0; 
            c.motor_a_pwm = 0; 
            c.motor_b_dir = 0; 
            c.motor_b_pwm = 0; 
            xMessageBufferSend( 
               buf_config,
               &c,
               sizeof(c),
               0 
            );
         }
         // Get the current sensor output from the timer process
         if(pdFALSE == xMessageBufferIsEmpty(buf_sensor)){
            xMessageBufferReceive( 
               buf_sensor,
               &s,
               sizeof(s),
               0 
            );
         }  
         // Use the first char as the comand
         switch(str[0]){
            case CMD_SAMPLE_ACCEL_X: sprintf(str, "%d", s.accel_x); break;
            case CMD_SAMPLE_ACCEL_Y: sprintf(str, "%d", s.accel_y); break;
            case CMD_SAMPLE_ACCEL_Z: sprintf(str, "%d", s.accel_z); break;
            case CMD_SAMPLE_GYRO_X:  sprintf(str, "%d", s.gyro_x);  break;
            case CMD_SAMPLE_GYRO_Y:  sprintf(str, "%d", s.gyro_y);  break;
            case CMD_SAMPLE_GYRO_Z:  sprintf(str, "%d", s.gyro_z);  break;
         }
         // Return the data
         send(sock, str, strlen(str), 0);
      }
   } while (len > 0);
}

static void tcp_server_task(void *pvParameters)
{
    char addr_str[128];
    int addr_family = (int)pvParameters;
    int ip_protocol = 0;
    int keepAlive = 1;
    int keepIdle = KEEPALIVE_IDLE;
    int keepInterval = KEEPALIVE_INTERVAL;
    int keepCount = KEEPALIVE_COUNT;
    struct sockaddr_storage dest_addr;


    if (addr_family == AF_INET) {
        struct sockaddr_in *dest_addr_ip4 = (struct sockaddr_in *)&dest_addr;
        dest_addr_ip4->sin_addr.s_addr = htonl(INADDR_ANY);
        dest_addr_ip4->sin_family = AF_INET;
        dest_addr_ip4->sin_port = htons(PORT);
        ip_protocol = IPPROTO_IP;
    }


    int listen_sock = socket(addr_family, SOCK_STREAM, ip_protocol);
    if (listen_sock < 0) {
        ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
        vTaskDelete(NULL);
        return;
    }
    int opt = 1;
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));


    ESP_LOGI(TAG, "Socket created");

    int err = bind(listen_sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (err != 0) {
        ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
        ESP_LOGE(TAG, "IPPROTO: %d", addr_family);
        goto CLEAN_UP;
    }
    ESP_LOGI(TAG, "Socket bound, port %d", PORT);

    err = listen(listen_sock, 1);
    if (err != 0) {
        ESP_LOGE(TAG, "Error occurred during listen: errno %d", errno);
        goto CLEAN_UP;
    }

    while (1) {

        ESP_LOGI(TAG, "Socket listening");

        struct sockaddr_storage source_addr; // Large enough for both IPv4 or IPv6
        socklen_t addr_len = sizeof(source_addr);
        int sock = accept(listen_sock, (struct sockaddr *)&source_addr, &addr_len);
        if (sock < 0) {
            ESP_LOGE(TAG, "Unable to accept connection: errno %d", errno);
            break;
        }

        // Set tcp keepalive option
        setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &keepAlive, sizeof(int));
        setsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE, &keepIdle, sizeof(int));
        setsockopt(sock, IPPROTO_TCP, TCP_KEEPINTVL, &keepInterval, sizeof(int));
        setsockopt(sock, IPPROTO_TCP, TCP_KEEPCNT, &keepCount, sizeof(int));
        // Convert ip address to string

        if (source_addr.ss_family == PF_INET) {
            inet_ntoa_r(((struct sockaddr_in *)&source_addr)->sin_addr, addr_str, sizeof(addr_str) - 1);
        }


        ESP_LOGI(TAG, "Socket accepted ip address: %s", addr_str);

        do_retransmit(sock);

        shutdown(sock, 0);
        close(sock);
    }
CLEAN_UP:
    close(listen_sock);
    vTaskDelete(NULL);
}

static void timer_expired(TimerHandle_t xTimer){
   uint8_t raw_data[NUM_REGS];  
   struct Sensor s;
   struct Config c;

   ESP_ERROR_CHECK(mpu9250_register_read(MPU6050_ACCEL_XOUT_H, raw_data, NUM_REGS)); 

   s.accel_x = (raw_data[0] << 8)  | raw_data[1];
   s.accel_y = (raw_data[2] << 8)  | raw_data[3];
   s.accel_z = (raw_data[4] << 8)  | raw_data[5];
   s.gyro_x  = (raw_data[6] << 8)  | raw_data[7];
   s.gyro_y  = (raw_data[8] << 8)  | raw_data[9];
   s.gyro_z  = (raw_data[10] << 8) | raw_data[11];
      
   // Place sample in buffer if it's empty
   if(pdFALSE == xMessageBufferIsFull(buf_sensor)){
      xMessageBufferSend( 
         buf_sensor,
         &s,
         sizeof(s),
         0 
      );
   }

   // Get the current sensor output from the timer process
   if(pdFALSE == xMessageBufferIsEmpty(buf_config)){
      xMessageBufferReceive( 
         buf_config,
         &c,
         sizeof(c),
         0 
      );
      ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(comparator, c.menu));
   }
}

void app_main(void)
{
    TimerHandle_t xTimer;
   
    buf_config = xMessageBufferCreate(sizeof(struct Config) * 2);
    buf_sensor = xMessageBufferCreate(sizeof(struct Sensor) * 2);


    
    ESP_LOGI(TAG, "Create timer and operator");
    mcpwm_timer_handle_t timer = NULL;
    mcpwm_timer_config_t timer_config = {
        .group_id = 0,
        .clk_src = MCPWM_TIMER_CLK_SRC_DEFAULT,
        .resolution_hz = SERVO_TIMEBASE_RESOLUTION_HZ,
        .period_ticks = SERVO_TIMEBASE_PERIOD,
        .count_mode = MCPWM_TIMER_COUNT_MODE_UP,
    };
    ESP_ERROR_CHECK(mcpwm_new_timer(&timer_config, &timer));

    mcpwm_oper_handle_t oper = NULL;
    mcpwm_operator_config_t operator_config = {
        .group_id = 0, // operator must be in the same group to the timer
    };
    ESP_ERROR_CHECK(mcpwm_new_operator(&operator_config, &oper));

    ESP_LOGI(TAG, "Connect timer and operator");
    ESP_ERROR_CHECK(mcpwm_operator_connect_timer(oper, timer));

    ESP_LOGI(TAG, "Create comparator and generator from the operator");
    //mcpwm_cmpr_handle_t comparator = NULL;
    mcpwm_comparator_config_t comparator_config = {
        .flags.update_cmp_on_tez = true,
    };
    ESP_ERROR_CHECK(mcpwm_new_comparator(oper, &comparator_config, &comparator));

    mcpwm_gen_handle_t generator = NULL;
    mcpwm_generator_config_t generator_config = {
        .gen_gpio_num = SERVO_PULSE_GPIO,
    };
    ESP_ERROR_CHECK(mcpwm_new_generator(oper, &generator_config, &generator));

    // set the initial compare value, so that the servo will spin to the center position
    ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(comparator, 0));

    ESP_LOGI(TAG, "Set generator action on timer and compare event");
    // go high on counter empty
    ESP_ERROR_CHECK(mcpwm_generator_set_action_on_timer_event(generator,
                                                              MCPWM_GEN_TIMER_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, MCPWM_TIMER_EVENT_EMPTY, MCPWM_GEN_ACTION_HIGH)));
    // go low on compare threshold
    ESP_ERROR_CHECK(mcpwm_generator_set_action_on_compare_event(generator,
                                                                MCPWM_GEN_COMPARE_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, comparator, MCPWM_GEN_ACTION_LOW)));

    ESP_LOGI(TAG, "Enable and start timer");
    ESP_ERROR_CHECK(mcpwm_timer_enable(timer));
    ESP_ERROR_CHECK(mcpwm_timer_start_stop(timer, MCPWM_TIMER_START_NO_STOP));


    ESP_ERROR_CHECK(i2c_master_init());
    ESP_LOGI(TAG, "I2C initialized successfully");

    ESP_ERROR_CHECK(mpu9250_register_write_byte(MPU6050_PWR_MGMT_1_REG_ADDR, 0));

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
     * Read "Establishing Wi-Fi or Ethernet Connection" section in
     * examples/protocols/README.md for more information about this function.
     */
    ESP_ERROR_CHECK(example_connect());

    xTimer = xTimerCreate("Timer", pdMS_TO_TICKS(100), pdTRUE, (void *) 0, timer_expired); 
    
    xTaskCreate(tcp_server_task, "tcp_server", 4096, (void*)AF_INET, 5, NULL);

    xTimerStart(xTimer, 0);
}
