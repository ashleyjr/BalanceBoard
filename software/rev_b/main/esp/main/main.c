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
#include "driver/gpio.h"

#include "../common/balance_board.h"

static const char *TAG = "main";

#define PORT                        CONFIG_EXAMPLE_PORT
#define KEEPALIVE_IDLE              CONFIG_EXAMPLE_KEEPALIVE_IDLE
#define KEEPALIVE_INTERVAL          CONFIG_EXAMPLE_KEEPALIVE_INTERVAL
#define KEEPALIVE_COUNT             CONFIG_EXAMPLE_KEEPALIVE_COUNT

struct Sensor {
   uint32_t time;
   int16_t  accel_x;   
   int16_t  accel_y;   
   int16_t  accel_z;    
   int16_t  gyro_x;   
   int16_t  gyro_y;   
   int16_t  gyro_z;   
}; 

struct Config {
   uint8_t menu;
   bool    led;
   bool    motor_stby;
   bool    motor_a_dir; 
   uint8_t motor_a_pwm; 
   bool    motor_b_dir; 
   uint8_t motor_b_pwm; 
}; 

uint32_t sample_time;

mcpwm_cmpr_handle_t motor_a_comp;
mcpwm_cmpr_handle_t motor_b_comp;

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
         // Push the config to the timer process when the buffer is empty 
         c.menu        = (uint8_t)str[0];
         c.led         = (uint8_t)str[1];
         c.motor_stby  = (bool)(uint8_t)str[2];
         c.motor_a_dir = (bool)(uint8_t)str[3]; 
         c.motor_a_pwm = (uint8_t)str[4]; 
         c.motor_b_dir = (bool)(uint8_t)str[5]; 
         c.motor_b_pwm = (uint8_t)str[6]; 
         while(pdFALSE == xMessageBufferIsEmpty(buf_config)); 
         xMessageBufferSend( 
            buf_config,
            &c,
            sizeof(c),
            0 
         );
          
         // Get the current sensor output from the timer process 
         while(pdTRUE == xMessageBufferIsEmpty(buf_sensor));
         xMessageBufferReceive( 
            buf_sensor,
            &s,
            sizeof(s),
            0 
         );

         // Use the first char as the comand
         snprintf(str, sizeof(str), "%ld", s.time);
         if(c.menu & CMD_SAMPLE_ACCEL_X)  snprintf(&str[strlen(str)], sizeof(str), ",%d", s.accel_x);
         if(c.menu & CMD_SAMPLE_ACCEL_Y)  snprintf(&str[strlen(str)], sizeof(str), ",%d", s.accel_y);
         if(c.menu & CMD_SAMPLE_ACCEL_Z)  snprintf(&str[strlen(str)], sizeof(str), ",%d", s.accel_z);
         if(c.menu & CMD_SAMPLE_GYRO_X)   snprintf(&str[strlen(str)], sizeof(str), ",%d", s.gyro_x);
         if(c.menu & CMD_SAMPLE_GYRO_Y)   snprintf(&str[strlen(str)], sizeof(str), ",%d", s.gyro_y);
         if(c.menu & CMD_SAMPLE_GYRO_Z)   snprintf(&str[strlen(str)], sizeof(str), ",%d", s.gyro_z);
         
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

   s.time    = sample_time;
   s.accel_x = (raw_data[0] << 8)  | raw_data[1];
   s.accel_y = (raw_data[2] << 8)  | raw_data[3];
   s.accel_z = (raw_data[4] << 8)  | raw_data[5];
   s.gyro_x  = (raw_data[6] << 8)  | raw_data[7];
   s.gyro_y  = (raw_data[8] << 8)  | raw_data[9];
   s.gyro_z  = (raw_data[10] << 8) | raw_data[11];
      
   sample_time += SAMPLE_MS;

   // Place sample in buffer if it's empty
   if(pdTRUE == xMessageBufferIsEmpty(buf_sensor)){
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
      
      // Standard Outputs
      ESP_ERROR_CHECK(gpio_set_level(GPIO_LED, (uint8_t)c.led));
      ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_STBY, (uint8_t)c.motor_stby));
      
      // Encode direction or stop based on pwm setting
      if(c.motor_a_pwm == 0){
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN1, 0));
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN2, 0));
      }else{
         if(c.motor_a_dir){
            ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN1, 0));
            ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN2, 1));
         }else{
            ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN1, 1));
            ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN2, 0));
         }
      } 
      if(c.motor_b_pwm == 0){
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN1, 0));
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN2, 0));
      }else{
         if(c.motor_b_dir){
            ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN1, 0));
            ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN2, 1));
         }else{
            ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN1, 1));
            ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN2, 0));
         }
      }

      // Drive PWM outputs
      ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(motor_a_comp, c.motor_a_pwm));
      ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(motor_b_comp, c.motor_b_pwm));
   }
}

void app_main(void){
   TimerHandle_t xTimer;
   buf_config = xMessageBufferCreate(sizeof(struct Config) * 2);
   buf_sensor = xMessageBufferCreate(sizeof(struct Sensor) * 2);   
  
   // Create all output GPIOs
   gpio_config_t io_conf = {};
   io_conf.intr_type = GPIO_INTR_DISABLE; 
   io_conf.mode = GPIO_MODE_OUTPUT;
   io_conf.pin_bit_mask = 
      ((uint64_t)1 << GPIO_LED)|
      ((uint64_t)1 << GPIO_MOTOR_STBY)|
      ((uint64_t)1 << GPIO_MOTOR_AIN1)|
      ((uint64_t)1 << GPIO_MOTOR_AIN2)|
      ((uint64_t)1 << GPIO_MOTOR_BIN1)|
      ((uint64_t)1 << GPIO_MOTOR_BIN2); 
   io_conf.pull_down_en = 0; 
   io_conf.pull_up_en = 1;
   gpio_config(&io_conf);
   ESP_ERROR_CHECK(gpio_set_level(GPIO_LED, 0));
   ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_STBY, 0));
   ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN1, 0));
   ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN2, 0));
   ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN1, 0));
   ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN2, 0));
   
   // Create timer 
   mcpwm_timer_handle_t timer = NULL;
   mcpwm_timer_config_t timer_config = {
       .group_id        = 0,
       .clk_src         = MCPWM_TIMER_CLK_SRC_DEFAULT,
       .resolution_hz   = PWM_RESOLUTION_HZ,
       .period_ticks    = PWM_PERIOD,
       .count_mode      = MCPWM_TIMER_COUNT_MODE_UP,
   };
   ESP_ERROR_CHECK(mcpwm_new_timer(&timer_config, &timer));
   
   // Create operator
   mcpwm_oper_handle_t oper = NULL;
   mcpwm_operator_config_t operator_config = {
       .group_id = 0, 
   };
   ESP_ERROR_CHECK(mcpwm_new_operator(&operator_config, &oper)); 
   ESP_ERROR_CHECK(mcpwm_operator_connect_timer(oper, timer));
   
   // Create comparators 
   mcpwm_comparator_config_t comparator_config = {
       .flags.update_cmp_on_tez = true,
   };
   ESP_ERROR_CHECK(mcpwm_new_comparator(oper, &comparator_config, &motor_a_comp));
   ESP_ERROR_CHECK(mcpwm_new_comparator(oper, &comparator_config, &motor_b_comp));
   
   // Assign GPIO for motor A
   mcpwm_gen_handle_t gen_motor_a = NULL;
   mcpwm_generator_config_t gen_motor_a_config = {
       .gen_gpio_num = GPIO_MOTOR_A_PWM,
   };
   ESP_ERROR_CHECK(mcpwm_new_generator(oper, &gen_motor_a_config, &gen_motor_a));
  
   // Assign GPIO for motor B
   mcpwm_gen_handle_t gen_motor_b = NULL;
   mcpwm_generator_config_t gen_motor_b_config = {
       .gen_gpio_num = GPIO_MOTOR_B_PWM,
   };
   ESP_ERROR_CHECK(mcpwm_new_generator(oper, &gen_motor_b_config, &gen_motor_b));

   // set the initial compare value, so that the servo will spin to the center position
   ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(motor_a_comp, 0));
   ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(motor_b_comp, 0));
   
   // go high on counter empty
   ESP_ERROR_CHECK(mcpwm_generator_set_action_on_timer_event(
      gen_motor_a,
      MCPWM_GEN_TIMER_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, MCPWM_TIMER_EVENT_EMPTY, MCPWM_GEN_ACTION_HIGH))
   );
   ESP_ERROR_CHECK(mcpwm_generator_set_action_on_timer_event(
      gen_motor_b,
      MCPWM_GEN_TIMER_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, MCPWM_TIMER_EVENT_EMPTY, MCPWM_GEN_ACTION_HIGH))
   );

   // go low on compare threshold
   ESP_ERROR_CHECK(mcpwm_generator_set_action_on_compare_event(
      gen_motor_a,
      MCPWM_GEN_COMPARE_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, motor_a_comp, MCPWM_GEN_ACTION_LOW))
   );
   ESP_ERROR_CHECK(mcpwm_generator_set_action_on_compare_event(
      gen_motor_b,
      MCPWM_GEN_COMPARE_EVENT_ACTION(MCPWM_TIMER_DIRECTION_UP, motor_b_comp, MCPWM_GEN_ACTION_LOW))
   );

   // Enable 
   ESP_ERROR_CHECK(mcpwm_timer_enable(timer));
   ESP_ERROR_CHECK(mcpwm_timer_start_stop(timer, MCPWM_TIMER_START_NO_STOP));
   
   // Setup I2C
   ESP_ERROR_CHECK(i2c_master_init()); 
   ESP_ERROR_CHECK(mpu9250_register_write_byte(MPU6050_PWR_MGMT_1_REG_ADDR, 0));
  
   // Init Socket
   ESP_ERROR_CHECK(nvs_flash_init());
   ESP_ERROR_CHECK(esp_netif_init());
   ESP_ERROR_CHECK(esp_event_loop_create_default());
   
   /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
    * Read "Establishing Wi-Fi or Ethernet Connection" section in
    * examples/protocols/README.md for more information about this function.
    */
   ESP_ERROR_CHECK(example_connect());
   
   sample_time = 0;
   xTimer = xTimerCreate("Timer", pdMS_TO_TICKS(SAMPLE_MS), pdTRUE, (void *) 0, timer_expired); 
   
   xTaskCreate(tcp_server_task, "tcp_server", 4096, (void*)AF_INET, 5, NULL);
   
   xTimerStart(xTimer, 0);
}
