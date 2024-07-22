#ifndef INC_BALANCE_BOARD_H
#define INC_BALANCE_BOARD_H

#define MAX_SIZE                       64
#define SAMPLE_MS                      100

#define I2C_MASTER_SCL_IO              25     
#define I2C_MASTER_SDA_IO              26     
#define I2C_MASTER_NUM                 0      
#define I2C_MASTER_FREQ_HZ             400000 
#define I2C_MASTER_TX_BUF_DISABLE      0      
#define I2C_MASTER_RX_BUF_DISABLE      0      
#define I2C_MASTER_TIMEOUT_MS          1000
#define MPU6050_SENSOR_ADDR            0x68   
#define MPU6050_PWR_MGMT_1_REG_ADDR    0x6B   
#define MPU6050_RESET_BIT              7
#define MPU6050_ACCEL_XOUT_H           0x3B
#define MPU6050_ACCEL_XOUT_L           0x3C
#define MPU6050_ACCEL_YOUT_H           0x3D
#define MPU6050_ACCEL_YOUT_L           0x3E
#define MPU6050_ACCEL_ZOUT_H           0x3F
#define MPU6050_ACCEL_ZOUT_L           0x40
#define MPU6050_TEMP_OUT_H             0x41
#define MPU6050_TEMP_OUT_L             0x42
#define MPU6050_GYRO_XOUT_H            0x43
#define MPU6050_GYRO_XOUT_L            0x44
#define MPU6050_GYRO_YOUT_H            0x45
#define MPU6050_GYRO_YOUT_L            0x46
#define MPU6050_GYRO_ZOUT_H            0x47
#define MPU6050_GYRO_ZOUT_L            0x48
#define NUM_REGS                       14

#define GPIO_LED                       22
#define GPIO_MOTOR_STBY                21
#define GPIO_MOTOR_AIN1                19
#define GPIO_MOTOR_AIN2                18
#define GPIO_MOTOR_A_PWM               5
#define GPIO_MOTOR_BIN1                17
#define GPIO_MOTOR_BIN2                16
#define GPIO_MOTOR_B_PWM               4

// 1MHz, 1us per tick
#define PWM_RESOLUTION                 10000000
#define PWM_PERIOD                     255    

#define CMD_UPDATE_MOTOR               0x01
#define CMD_SAMPLE_ACCEL_X             0x02
#define CMD_SAMPLE_ACCEL_Y             0x04
#define CMD_SAMPLE_ACCEL_Z             0x08
#define CMD_SAMPLE_GYRO_X              0x10
#define CMD_SAMPLE_GYRO_Y              0x20
#define CMD_SAMPLE_GYRO_Z              0x40
#define CMD_SAMPLE_MOTOR_A             0x80



#endif
