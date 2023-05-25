/*
 * I2C_Init.h
 *
 *  Created on: Mar 7, 2023
 *      Author: mahmo
 */

#ifndef I2C_INIT_H_
#define I2C_INIT_H_

#define ERR -1

////modes
#define I2C_SLAVE_TRANSMIT_MODE 0
#define I2C_SLAVE_RECEIVE_MODE 1
#define I2C_MASTER_TRANSMIT_MODE 2
#define I2C_MASTER_RECEIVE_MODE 3

//clock
#define I2C_CLOCK_200KHZ 1
#define I2C_CLOCK_100KHZ 0

//CONTROL CODES
#define I2C_BIT_RATE_FOR_200KHZ 0x20
#define I2C_BIT_RATE_FOR_100KHZ 0x0C
#define I2C_PRESCALAR_0 0x03
#define I2C_ENABLE 0x04
#define I2C_ENABLE_ACK 0x40
#define I2C_STATUS_MAP 0xF8
#define I2C_START_CONDITION 0x20
#define I2C_STOP_CONDITION 0x10
#define I2C_INTERRUPT_ENABLE 0x01
#define I2C_READ 0x01
#define I2C_INT_BIT_ENABLE 0x80

//General stats
#define I2C_START_STATUS 0x08
#define I2C_REPEATED_START_STATUS 0x10
#define I2C_SLA_R_RECEIVED_STATUS 0xA8
#define I2C_SLA_W_RECEIVED_STATUS 0x60
//Master Transmitter stats
#define I2C_ACK_SLA_W_STATUS 0x18
#define I2C_NOACK_SLA_W_STATUS 0x20
#define I2C_MASTER_ACK_DATA_STATUS 0x28
#define I2C_MASTER_NOACK_DATA_STATUS 0x30
//Master Receiver stats
#define I2C_ACK_SLA_R_STATUS 0x40
#define I2C_NOACK_SLA_R_STATUS 0x48
#define I2C_MASTER_ACK_DATA_RECEIVED_STATUS 0x50
#define I2C_MASTER_NOACK_DATA_RECEIVED_STATUS 0x58
//Slave Transmitter stats
#define I2C_SLAVE_ACK_SLA_R_STATUS 0xA8
#define I2C_SLAVE_ACK_DATA_STATUS 0xB8
#define I2C_SLAVE_NOACK_DATA_STATUS 0xC0
#define I2C_STOP_RECEIVED_STATUS 0xA0
#define I2C_SLAVE_LAST_BYTE_STATUS 0xC8
//SLAVE RECEIVER stats
#define I2C_SLAVE_ACK_SLA_W_STATUS 0x60
#define I2C_SLAVE_ACK_DATA_RECEIVED_STATUS 0x80
#define I2C_SLAVE_NOACK_DATA_RECEIVED_STATUS 0x88



typedef struct I2C_Handle
{
	u8 *sendBuff;
	u8 sendBuffLen;
	u8 sendBuffCount;
	u8 *receiveBuff;
	u8 receiveBuffLen;
	u8 receiveBuffCount;
	u8 mode;
	u8 address;
	u8 clock;
}I2C_Handle;


void I2C_Init(I2C_Handle *handle);
void I2C_Start(u8 address);
s8 I2C_Slave_Read(I2C_Handle *handle);
s8 I2C_Master_Read(I2C_Handle *handle);
s8 I2C_Slave_Write(I2C_Handle *handle);
s8 I2C_Master_Write(I2C_Handle *handle);
void I2C_End();

#endif /* I2C_INIT_H_ */
