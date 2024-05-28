#ifndef INC_BALANCE_BOARD_H
#define INC_BALANCE_BOARD_H

#define MAX_SIZE                       8

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

#define GPIO_LED                       13
#define GPIO_MOTOR_STBY                27
#define GPIO_MOTOR_AIN1                14
#define GPIO_MOTOR_AIN2                12
#define GPIO_MOTOR_A_PWM               32
#define GPIO_MOTOR_B_PWM               33

// 1MHz, 1us per tick
#define PWM_RESOLUTION_HZ              1000000
#define PWM_PERIOD                     255    

#define CMD_SAMPLE_ACCEL_Y             0
#define CMD_SAMPLE_ACCEL_Y             1 
#define CMD_SAMPLE_ACCEL_Z             2 
#define CMD_SAMPLE_GYRO_X              3 
#define CMD_SAMPLE_GYRO_Y              4 
#define CMD_SAMPLE_GYRO_Z              5 

#endif
