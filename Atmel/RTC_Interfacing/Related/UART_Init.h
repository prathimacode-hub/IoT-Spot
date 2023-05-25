/*
 * UART_Init.h
 *
 *  Created on: Oct 14, 2022
 *      Author: mahmo
 */

#ifndef UART_INIT_H_
#define UART_INIT_H_

#define UART_UCSRC_SELECT 0x80
#define UART_ASYNC_MODE 0x40
#define UART_PARITY_DISABLE 0x00
#define UART_STOP_BITS_1 0x06
#define UART_CHARACTER_8_BIT 0x06
#define UART_BAUDRATE_9600_UBRR 51
#define UART_TRANSMITTER_ENABLE 0x08
#define UART_RECEIVER_ENABLE 0x10
#define UART_DATA_REGISTER_EMPTY 0x20
#define UART_RECEIVE_COMPLETE 0x80

void UART_Init();
void UART_SendChar(u8 data);
u8 UART_ReceiveChar();
void UART_SendStr(u8 *data);
void UART_PrintNum(u8 num);

#endif /* UART_INIT_H_ */
