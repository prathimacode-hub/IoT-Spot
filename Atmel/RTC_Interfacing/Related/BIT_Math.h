/*
 * BIT_Math.h
 *
 *  Created on: Aug 27, 2022
 *      Author: mahmo
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H


#endif /* BIT_MATH_H_ */


#define SET_BIT(VAR,BITNUM) (VAR |= 1<<BITNUM)
#define CLEAR_BIT(VAR,BITNUM) (VAR &= ~(1<<BITNUM))
#define TOGGLE_BIT(VAR,BITNUM) (VAR ^= (1<<BITNUM))
#define GET_BIT(VAR,BITNUM) ((VAR >> BITNUM) & 1)


