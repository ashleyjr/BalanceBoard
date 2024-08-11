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

#define PORT                           CONFIG_EXAMPLE_PORT
#define KEEPALIVE_IDLE                 CONFIG_EXAMPLE_KEEPALIVE_IDLE
#define KEEPALIVE_INTERVAL             CONFIG_EXAMPLE_KEEPALIVE_INTERVAL
#define KEEPALIVE_COUNT                CONFIG_EXAMPLE_KEEPALIVE_COUNT

static const char *TAG = "main";

mcpwm_cmpr_handle_t motor_a_comp;
mcpwm_cmpr_handle_t motor_b_comp;

MessageBufferHandle_t buf_sensor;
MessageBufferHandle_t buf_config;

uint32_t sample_time;
struct Config conf;
float err_n0;
float area;

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

uint32_t int_from_rx(char *str){
   uint32_t data;
   uint8_t i,j;
   data = 0;
   for(i=0;i<8;i++){
      j = *(str+i) - 48;
      if(j > 9){
         j -= 7;
      }
      data <<= 4;
      data |= j;
   }
   return data; 
}

static void do_retransmit(const int sock){ 
   int      len;
   char     data[MAX_SIZE];   
   struct   Sensor s;
   struct   Config c; 
   uint32_t rx_data;

   // Handle socket 
   do {
      len = recv(sock, data, sizeof(data) - 1, 0);
      if (len < 0) {
         ESP_LOGE(TAG, "Error occurred during receiving: errno %d", errno);
      } else if (len == 0) {
         ESP_LOGW(TAG, "Connection closed");
      } else { 
         ESP_LOGI(TAG, "%s", data);
     
         // First 8 nibbles is the menu code 
         // Second 8 nibbles is the data
         c = conf;
         c.menu = int_from_rx(&data[0]);
         rx_data = int_from_rx(&data[8]);
         switch(c.menu & CMD_MASK_UPDATE){
            case CMD_UPDATE_LED:          c.led = (0 != rx_data); 
                                          break;
            case CMD_UPDATE_MOTOR_STBY:   c.motor_stby = (0 != rx_data); 
                                          break;
            case CMD_UPDATE_MOTOR_A_DIR:  c.motor_a_dir = (0 != rx_data); 
                                          break;
            case CMD_UPDATE_MOTOR_A_PWM:  c.motor_a_pwm = (uint8_t)rx_data; 
                                          break;
            case CMD_UPDATE_MOTOR_B_DIR:  c.motor_b_dir = (0 != rx_data); 
                                          break;
            case CMD_UPDATE_MOTOR_B_PWM:  c.motor_b_pwm = (uint8_t)rx_data; 
                                          break;
            case CMD_UPDATE_P_CTRL:       c.p = ((float)rx_data)/FLOAT_SCALE; 
                                          break;
            case CMD_UPDATE_I_CTRL:       c.i = ((float)rx_data)/FLOAT_SCALE; 
                                          break;
            case CMD_UPDATE_D_CTRL:       c.d = ((float)rx_data)/FLOAT_SCALE; 
                                          break;
            case CMD_UPDATE_TARGET:       c.target = ((float)rx_data)/FLOAT_SCALE; 
                                          break;

            default:;
         }
     
         // Send over config and wait for it to be updated
         while(pdFALSE == xMessageBufferIsEmpty(buf_config)); 
         xMessageBufferSend( 
            buf_config,
            &c,
            sizeof(c),
            0 
         );
         while(pdFALSE == xMessageBufferIsEmpty(buf_config)); 
        
         // Get the current sensor output from the timer process 
         while(pdTRUE == xMessageBufferIsEmpty(buf_sensor));
         xMessageBufferReceive( 
            buf_sensor,
            &s,
            sizeof(s),
            0 
         );

         // Time is always and anything else is based on the same command
         snprintf(&data[strlen(data)], sizeof(data), "%ld", s.time);
         if(c.menu & CMD_SAMPLE_ACCEL_X)  snprintf(&data[strlen(data)], sizeof(data), ",%d", s.accel_x);
         if(c.menu & CMD_SAMPLE_ACCEL_Y)  snprintf(&data[strlen(data)], sizeof(data), ",%d", s.accel_y);
         if(c.menu & CMD_SAMPLE_ACCEL_Z)  snprintf(&data[strlen(data)], sizeof(data), ",%d", s.accel_z);
         if(c.menu & CMD_SAMPLE_GYRO_X)   snprintf(&data[strlen(data)], sizeof(data), ",%d", s.gyro_x);
         if(c.menu & CMD_SAMPLE_GYRO_Y)   snprintf(&data[strlen(data)], sizeof(data), ",%d", s.gyro_y);
         if(c.menu & CMD_SAMPLE_GYRO_Z)   snprintf(&data[strlen(data)], sizeof(data), ",%d", s.gyro_z);
         if(c.menu & CMD_SAMPLE_MOTOR_A)  snprintf(&data[strlen(data)], sizeof(data), ",%d, %d", s.motor_a_dir, s.motor_a_pwm);
         if(c.menu & CMD_SAMPLE_MOTOR_B)  snprintf(&data[strlen(data)], sizeof(data), ",%d, %d", s.motor_b_dir, s.motor_b_pwm);
         if(c.menu & CMD_SAMPLE_P_DRIVE)  snprintf(&data[strlen(data)], sizeof(data), ",%f", s.p_drive);
         if(c.menu & CMD_SAMPLE_I_DRIVE)  snprintf(&data[strlen(data)], sizeof(data), ",%f", s.i_drive);
         if(c.menu & CMD_SAMPLE_D_DRIVE)  snprintf(&data[strlen(data)], sizeof(data), ",%f", s.d_drive);
         if(c.menu & CMD_SAMPLE_ERROR)    snprintf(&data[strlen(data)], sizeof(data), ",%f", s.error);


         // Return the data
         send(sock, data, strlen(data), 0);
         
         // Print the debug
         ESP_LOGI(TAG, "Config Update (menu=0x%lx)", conf.menu);
         ESP_LOGI(TAG, "");
         ESP_LOGI(TAG, "   target      = %f", conf.target);
         ESP_LOGI(TAG, "   led         = %d", conf.led);
         ESP_LOGI(TAG, "   motor_stby  = %d", conf.motor_stby);
         ESP_LOGI(TAG, "   motor_a_dir = %d", conf.motor_a_dir);
         ESP_LOGI(TAG, "   motor_a_pwm = %d", conf.motor_a_pwm);
         ESP_LOGI(TAG, "   motor_b_dir = %d", conf.motor_b_dir);
         ESP_LOGI(TAG, "   motor_b_pwm = %d", conf.motor_b_pwm);
         ESP_LOGI(TAG, "   p           = %f", conf.p);
         ESP_LOGI(TAG, "   i           = %f", conf.i);
         ESP_LOGI(TAG, "   d           = %f", conf.d);

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
   uint8_t  raw_data[NUM_REGS];  
   struct   Sensor s; 
   float    gradient;
   float    err_n1;
   float    drive;
   bool     motor_a_dir = false;
   uint8_t  motor_a_pwm = 0;
   bool     motor_b_dir = false;
   uint8_t  motor_b_pwm = 0;

   // Read sensor
   ESP_ERROR_CHECK(mpu9250_register_read(MPU6050_ACCEL_XOUT_H, raw_data, NUM_REGS)); 

   // Cast data
   s.time    = sample_time;
   s.accel_x = (raw_data[0] << 8)  | raw_data[1];
   s.accel_y = (raw_data[2] << 8)  | raw_data[3];
   s.accel_z = (raw_data[4] << 8)  | raw_data[5];
   s.gyro_x  = (raw_data[6] << 8)  | raw_data[7];
   s.gyro_y  = (raw_data[8] << 8)  | raw_data[9];
   s.gyro_z  = (raw_data[10] << 8) | raw_data[11];
      
   // Update sample timer
   sample_time += SAMPLE_MS;

   // Update the config if there is a message 
   if(pdFALSE == xMessageBufferIsEmpty(buf_config)){
      xMessageBufferReceive( 
         buf_config,
         &conf,
         sizeof(conf),
         0 
      );
   } 
   
   // Menu of proces options
   switch(conf.menu & CMD_MASK_CTRL){ 
      case CMD_CTRL_MANUAL:   motor_a_dir = conf.motor_a_dir;
                              motor_a_pwm = conf.motor_a_pwm;
                              motor_b_dir = conf.motor_b_dir;
                              motor_a_pwm = conf.motor_a_pwm;
                              ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_STBY, (uint8_t)conf.motor_stby));
                              break;
      case CMD_CTRL_AUTO:     // Calculate Error
                              err_n1 = err_n0;
                              err_n0 = conf.target - (float)s.gyro_y;
                              // Accumulate Area
                              area += (err_n0 + err_n1) / 2;
                              // Calculate Gradient
                              gradient = err_n0 - err_n1;
                              // Sum to drive output
                              s.p_drive = conf.p * err_n0;
                              s.i_drive = conf.i * area;
                              s.d_drive = conf.d * gradient;
                              drive = s.p_drive + s.i_drive + s.d_drive; 
                              // Capture error
                              s.error = err_n0;
                              // Translate to motor driving 
                              if(drive >= 0){
                                 motor_a_dir = true;
                                 motor_a_pwm = (uint8_t)drive;
                              }else{
                                 motor_a_dir = false;
                                 motor_a_pwm = (uint8_t)(drive * -1);
                              }
                              ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_STBY, 1));
                              motor_b_dir = false;
                              motor_b_pwm = 0;
                              break;
      default:                motor_a_dir = false;
                              motor_a_pwm = 0;
                              motor_b_dir = false;
                              motor_b_pwm = 0;
                              break;
   }
    
   // Standard Outputs
   ESP_ERROR_CHECK(gpio_set_level(GPIO_LED, (uint8_t)conf.led));
   
   // Encode direction or stop based on pwm setting
   if(motor_a_pwm == 0){
      ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN1, 0));
      ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN2, 0));
   }else{
      if(motor_a_dir){
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN1, 0));
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN2, 1));
      }else{
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN1, 1));
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_AIN2, 0));
      }
   } 
   if(motor_b_pwm == 0){
      ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN1, 0));
      ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN2, 0));
   }else{
      if(motor_b_dir){
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN1, 0));
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN2, 1));
      }else{
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN1, 1));
         ESP_ERROR_CHECK(gpio_set_level(GPIO_MOTOR_BIN2, 0));
      }
   }

   // Drive PWM outputs
   ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(motor_a_comp, motor_a_pwm));
   ESP_ERROR_CHECK(mcpwm_comparator_set_compare_value(motor_b_comp, motor_b_pwm));
  
   // Add PWM rate back in to sensor data
   s.motor_a_dir = motor_a_dir;
   s.motor_a_pwm = motor_a_pwm;
   s.motor_b_dir = motor_a_dir;
   s.motor_b_pwm = motor_a_pwm;

   // Place sample in buffer if it's empty
   if(pdTRUE == xMessageBufferIsEmpty(buf_sensor)){
      xMessageBufferSend( 
         buf_sensor,
         &s,
         sizeof(s),
         0 
      );
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
       .resolution_hz   = PWM_RESOLUTION,
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
   
   conf.menu = 0;
   sample_time = 0;
   
   xTimer = xTimerCreate("Timer", pdMS_TO_TICKS(SAMPLE_MS), pdTRUE, (void *) 0, timer_expired); 
   
   xTaskCreate(tcp_server_task, "tcp_server", 4096, (void*)AF_INET, 5, NULL);
   
   xTimerStart(xTimer, 0);
}
