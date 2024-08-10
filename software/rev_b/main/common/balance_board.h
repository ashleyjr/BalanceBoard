#ifndef INC_BALANCE_BOARD_H
#define INC_BALANCE_BOARD_H

#define MAX_SIZE                       128
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

// For scaling between uint32_t and float
#define FLOAT_SCALE                    100

// Bits [15:0] used for samples
#define CMD_SAMPLE_ACCEL_X             0x00000001
#define CMD_SAMPLE_ACCEL_Y             0x00000002
#define CMD_SAMPLE_ACCEL_Z             0x00000004
#define CMD_SAMPLE_GYRO_X              0x00000008
#define CMD_SAMPLE_GYRO_Y              0x00000010
#define CMD_SAMPLE_GYRO_Z              0x00000020
#define CMD_SAMPLE_MOTOR_A             0x00000040
#define CMD_SAMPLE_MOTOR_B             0x00000080

// Bits [23:16] used for updates
#define CMD_UPDATE_MOTOR_STBY          0x00010000
#define CMD_UPDATE_MOTOR_A_DIR         0x00020000
#define CMD_UPDATE_MOTOR_A_PWM         0x00030000
#define CMD_UPDATE_MOTOR_B_DIR         0x00040000
#define CMD_UPDATE_MOTOR_B_PWM         0x00050000
#define CMD_UPDATE_LED                 0x00060000
#define CMD_UPDATE_P_CTRL              0x00100000
#define CMD_UPDATE_I_CTRL              0x00200000
#define CMD_UPDATE_D_CTRL              0x00300000

// Bits [31:24] used for control loop
#define CMD_CTRL_MANUAL                0x01000000
#define CMD_CTRL_AUTO                  0x02000000

// Masks
#define CMD_MASK_SAMPLE                0x0000FFFF
#define CMD_MASK_UPDATE                0x00FF0000
#define CMD_MASK_CTRL                  0xFF000000

#endif
