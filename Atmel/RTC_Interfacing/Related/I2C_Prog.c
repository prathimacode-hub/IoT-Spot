/*
 * I2C_Prog.c
 *
 *  Created on: Mar 7, 2023
 *      Author: mahmo
 */

#include "STD_Types.h"
//#include "I2C_Register.h"
#include "I2C_Init.h"
#include <avr/io.h>
#include <avr/delay.h>

void I2C_Init(I2C_Handle *handle)
{
	//init clock
	TWBR = (handle->clock == I2C_CLOCK_200KHZ) ? I2C_BIT_RATE_FOR_200KHZ : I2C_BIT_RATE_FOR_100KHZ;
	//init sender address
	TWAR = handle->address;
	//clear buff counts
	handle->receiveBuffCount = handle->sendBuffCount = 0;
}



void I2C_Start(u8 address)						/* I2C start wait function */
{
	uint8_t status;											/* Declare variable */
	while (1)
	{

		TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);				/* Enable TWI, generate start condition and clear interrupt flag */
		while (!(TWCR & (1<<TWINT)));						/* Wait until TWI finish its current job (start condition) */
		status = TWSR & 0xF8;								/* Read TWI status register with masking lower three bits */
		if (status != 0x08)									/* Check weather start condition transmitted successfully or not? */
		continue;											/* If no then continue with start loop again */
		TWDR = address;								/* If yes then write SLA+W in TWI data register */
		TWCR = (1<<TWEN)|(1<<TWINT);						/* Enable TWI and clear interrupt flag */
		while (!(TWCR & (1<<TWINT)));						/* Wait until TWI finish its current job (Write operation) */
		status = TWSR & 0xF8;								/* Read TWI status register with masking lower three bits */
		if (status != I2C_ACK_SLA_W_STATUS && status != I2C_ACK_SLA_R_STATUS)								/* Check weather SLA+W transmitted & ack received or not? */
		{
			I2C_End();										/* If not then generate stop condition */
			continue;										/* continue with start loop again */
		}
		break;												/* If yes then break loop */
	}
}

s8 I2C_Master_Write(I2C_Handle *handle)
{
	handle->sendBuffCount = 0;
	uint8_t status;
	while(handle->sendBuffCount < handle->sendBuffLen)
	{
		TWDR = handle->sendBuff[handle->sendBuffCount];
		TWCR = (1<<TWEN)|(1<<TWINT);
		while (!(TWCR & (1<<TWINT)));
		status = TWSR & 0xF8;
		if(status != I2C_MASTER_ACK_DATA_STATUS)
		{
			//continue;
			return ERR;
		}
		handle->sendBuffCount++;
	}
	return 1;
}

/** Read **/
s8 I2C_Master_Read(I2C_Handle *handle)
{
	uint8_t status;
	handle->receiveBuffCount = 0;
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);						/* Enable TWI and clear interrupt flag */
	while(1)
	{
		while (!(TWCR & (1<<TWINT)));						/* Wait until TWI finish its current job (Write operation) */
		status = TWSR & 0xF8;
		if(status != I2C_MASTER_ACK_DATA_RECEIVED_STATUS)
		{
			return ERR;
		}
		if(handle->receiveBuffCount < handle->receiveBuffLen)
		{
			handle->receiveBuff[handle->receiveBuffCount] = TWDR;
			handle->receiveBuffCount++;
		}
		else
		{
			return 1;
		}
		TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);						/* Enable TWI and clear interrupt flag */
	}
}

s8 I2C_Slave_Write(I2C_Handle *handle)
{
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	_delay_ms(10);
	uint8_t status;
	while(1)
	{
		while (!(TWCR & (1<<TWINT)));
		status = TWSR & 0xF8;
		if(status == I2C_SLAVE_ACK_DATA_STATUS)
		{
			if(handle->sendBuffCount < handle->sendBuffLen)
			{
				TWDR = handle->sendBuff[handle->sendBuffCount];
				handle->sendBuffCount++;
			}
			else
			{
				return 1;
			}
		}
		else if(status != I2C_SLAVE_ACK_SLA_R_STATUS)
		{
			return ERR;
		}
		TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);

		//		else if(status == I2C_SLAVE_LAST_BYTE_STATUS)
//		{
//
//		}
	}
}

s8 I2C_Slave_Read(I2C_Handle *handle)
{
	handle->receiveBuffCount = 0;
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	_delay_ms(10);
	uint8_t status;
	while(1)
	{
		while (!(TWCR & (1<<TWINT)));
		status = TWSR & 0xF8;
		if(status == I2C_SLAVE_ACK_DATA_RECEIVED_STATUS)
		{
			if(handle->receiveBuffCount < handle->receiveBuffLen)
			{
				//TWDR = handle->receiveBuff[handle->receiveBuffCount];
				handle->receiveBuff[handle->receiveBuffCount] = TWDR;
				handle->receiveBuffCount++;
			}
			else
			{
				return 2;
			}
		}
		else if(status != I2C_SLAVE_ACK_SLA_W_STATUS)
		{
			//return status;
			return ERR;
		}
		else if(status == I2C_STOP_RECEIVED_STATUS)
		{
			return 1;
		}
		TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	}
}


void I2C_End()
{
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);					/* Enable TWI, generate stop condition and clear interrupt flag */
	while(TWCR & (1<<TWSTO));								/* Wait until stop condition execution */
}
