/* esp_timer (high resolution timer) example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "esp_timer.h"
#include "esp_log.h"
#include "esp_sleep.h"
#include "sdkconfig.h"
#include "driver/i2c.h"

static void periodic_timer_callback(void* arg);

static const char* TAG = "example";

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

/**
 * @brief i2c master initialization
 */
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


void app_main(void)
{
   const esp_timer_create_args_t periodic_timer_args = {
            .callback = &periodic_timer_callback,
            /* name is optional, but may help identify the timer when debugging */
            .name = "periodic"
    };

    ESP_ERROR_CHECK(i2c_master_init());
    ESP_LOGI(TAG, "I2C initialized successfully");
    ESP_ERROR_CHECK(mpu9250_register_write_byte(MPU6050_PWR_MGMT_1_REG_ADDR, 0));

    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    

    /* Start the timers */
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 50000)); 
    ESP_LOGI(TAG, "Started timers, time since boot: %lld us", esp_timer_get_time());
 
    /* Let the timer run for a little bit more */
    usleep(20000000);

    /* Clean up and finish the example */
    ESP_ERROR_CHECK(esp_timer_stop(periodic_timer));
    ESP_ERROR_CHECK(esp_timer_delete(periodic_timer));
    ESP_LOGI(TAG, "Stopped and deleted timers");

    ESP_ERROR_CHECK(i2c_driver_delete(I2C_MASTER_NUM));
    ESP_LOGI(TAG, "I2C de-initialized successfully");
}

static void periodic_timer_callback(void* arg)
{ 
    uint8_t raw_data[14];
    int16_t data[7];
    uint8_t i;
    int64_t time_since_boot = esp_timer_get_time();
   
    ESP_ERROR_CHECK(mpu9250_register_read(MPU6050_ACCEL_XOUT_H, raw_data, 14));

    for(i=0;i<14;i+=2){
      data[i/2] = raw_data[i];
      data[i/2] <<= 8;
      data[i/2] |= raw_data[i]; 
    }
    ESP_LOGI(TAG, "%lldus: %d\t%d\t%d\t%d\t%d\t%d\t%d\t", 
      time_since_boot, 
      data[0], 
      data[1], 
      data[2],
      data[3], 
      data[4], 
      data[5], 
      data[6]
   );
}

