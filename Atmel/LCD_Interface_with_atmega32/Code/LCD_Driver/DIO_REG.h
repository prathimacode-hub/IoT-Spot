/*
 * DIO_REG.h
 * Description: define all DIO register addresses
 * Created: 5/21/2022 2:51:05 PM
 *  Author: Mohamed Ismail
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_

#include "std_types.h"

/* Group of register for PORTA */ 
#define DDRA_REG	*((volatile uint8 *)0x3A)
#define PINA_REG	*((volatile uint8 *)0x39)
#define PORTA_REG	*((volatile uint8 *)0x3B)

/* Group of register for PORTB */ 
#define DDRB_REG	*((volatile uint8 *)0x37)
#define PINB_REG	*((volatile uint8 *)0x36)
#define PORTB_REG	*((volatile uint8 *)0x38)

/* Group of register for PORTC */
#define DDRC_REG	*((volatile uint8 *)0x34)
#define PINC_REG	*((volatile uint8 *)0x33)
#define PORTC_REG	*((volatile uint8 *)0x35)

/* Group of register for PORTD */
#define DDRD_REG	*((volatile uint8 *)0x31)
#define PIND_REG	*((volatile uint8 *)0x30)
#define PORTD_REG	*((volatile uint8 *)0x32)


#endif /* DIO_REG_H_ */