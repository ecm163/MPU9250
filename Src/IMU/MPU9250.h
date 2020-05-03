/*
 * MPU9250.h
 *
 *  Created on: 30 thg 4, 2020
 *      Author: PC
 */

#ifndef INC_IMU_MPU9250_H_
#define INC_IMU_MPU9250_H_

#include "stdbool.h"

#define SAMPLE_RATE_1khz     7
#define gyro_sensitivity    16.4   // = 16.4 LSB/degrees/sec
#define  accel_sensitivity  16384.0      // = 16384 LSB/g

float Accel_x,Accel_y,Accel_z,Gyro_x,Gyro_y,Gyro_z;
float Accel_x_bias,Accel_y_bias,Accel_z_bias,Gyro_x_bias,Gyro_y_bias,Gyro_z_bias;
float asax,asay,asaz;

#define MAX_PRECISION	(10)
static const double rounders[MAX_PRECISION + 1] =
{
	0.5,				// 0
	0.05,				// 1
	0.005,				// 2
	0.0005,				// 3
	0.00005,			// 4
	0.000005,			// 5
	0.0000005,			// 6
	0.00000005,			// 7
	0.000000005,		// 8
	0.0000000005,		// 9
	0.00000000005		// 10
};

typedef enum{
	MPU9250_CLOCK_INTERNAL        = 0 <<0 ,
	MPU9250_CLOCK_PLL_XGYRO       = 1 <<0,
	MPU9250_CLOCK_PLL_YGYRO       = 2 <<0,
	MPU9250_CLOCK_PLL_ZGYRO       = 3 <<0,
	MPU9250_CLOCK_PLL_EXT32K      = 4 <<0,
	MPU9250_CLOCK_PLL_EXT19M      = 5 <<0,
	MPU9250_CLOCK_KEEP_RESET      = 7 <<0,
}MPU9250_clock_source_t;

typedef enum{
	MPU9250_GYRO_FS_250       =  0 <<3,  //0x00   // � 250 �/s
	MPU9250_GYRO_FS_500       =  1 << 3,// 0x08   // � 500 �/s
	MPU9250_GYRO_FS_1000      =  2 << 3,// 0x10   // � 1000 �/s
	MPU9250_GYRO_FS_2000      =  3 << 3,// 0x18	  // � 2000 �/s
}MPU9250_GYRO_FULL_SCALE;

typedef enum{
	MPU9250_ACCEL_FS_2        =  0 <<3,//  0x00   // � 2g
	MPU9250_ACCEL_FS_4        =  1 << 3,// 0x08   // � 4g
	MPU9250_ACCEL_FS_8        =  2 << 3,// 0x10   // � 8g
	MPU9250_ACCEL_FS_16       =  3 << 3,// 0x18  // � 16g
}MPU9250_ACCEL_FULL_SCALE;
typedef enum{
	MFS_14BITS	= 0,
	MFS_16BITS	= 1,
}MPU9250_MAG_FULL_SCALE;

typedef enum  {
	Result_Ok = 0x00,          /*!< Everything OK */
	Result_Error,              /*!< Unknown error */
	Result_DeviceNotConnected, /*!< There is no device with valid slave address */
	Result_DeviceInvalid       /*!< Connected device with address is not MPU6050 */
}Result;

void init_IMU();
void init_magnetometer();
void Process_IMU();
void Set_Accel_Range(MPU9250_ACCEL_FULL_SCALE accel_FS);
void Set_Gyro_Range(MPU9250_GYRO_FULL_SCALE gyro_FS);
bool Check_Connection();
void mpu9250_set_clock_source(MPU9250_clock_source_t clock_source);
void Calibration_IMU();
void Reset_MPU();
char * ftoa(double f, char * buf, int precision);
#endif /* INC_IMU_MPU9250_H_ */