/*
 * Bit_Math.h
 * Description: define common operations on manipulating bits 
 * Created: 5/21/2022 3:05:37 PM
 * Author: Mohamed Ismail
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* Set a certain pin in a given register */
#define SET_BIT(PORT, Bit)	PORT |= (1<<Bit)

/* Reset a certain pin in a given register */
#define CLR_BIT(PORT, Bit)	PORT &= ~(1<<Bit)

/* Toggle a certain pin in a given register */
#define TOG_BIT(PORT, Bit)	PORT ^= (1<<Bit)

/* Read a certain pin in a given register */
#define RD_BIT(PORT, Bit)	(PORT&(1<<Bit))



#endif /* BIT_MATH_H_ */