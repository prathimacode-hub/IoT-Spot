/*
 * UART_Prog.c
 *
 *  Created on: Oct 14, 2022
 *      Author: mahmo
 */

#include "STD_Types.h"
#include <avr/io.h>
#include "string.h"
#include "BIT_Math.h"
// #include "UART_Reg.h"
#include "UART_Init.h"


void UART_Init()
{
	// set baud rate
	UBRRL = 51;

	// enable Tx & Rx
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);

	// set format, 8 data bits
	CLEAR_BIT(UCSRB, 2);

}


void UART_SendChar(u8 data)
{
	//Check for Transmit flag
	while(!(GET_BIT(UCSRA,5)));
	//send data
	UDR = data;
}


void UART_SendStr(u8 *data)	
{
	u8 i;
	while(*data != '\0')
	{
		UART_SendChar(*data);
		data += 1;
	}
	// for(i=0;i<strlen(data);i++)
	// {
	// }
}

void UART_PrintNum(u8 num)
{
	u8 tempNum = num;
	u8 num_len = 0;
	while(tempNum > 0)
	{
		//UART_SendChar((num%10)+48);
		tempNum /= 10;
		num_len += 1;
	}
	u8 *digits = (u8*)malloc(sizeof(u8)*num_len);
	s8 i = 0;
	while(i < num_len)
	{
		digits[i] = (num%10);
		num /= 10;
		i+=1;
	}
	i = num_len-1;
	while(i >= 0)
	{
		UART_SendChar(digits[i]+48);
		i--;
	}
}

u8 UART_ReceiveChar()
{
	//Check for receive flag
	while(!(GET_BIT(UCSRA,7)));
	return UDR;

}
