/*
 * DIO_INT.h
 * Description: File of all Function prototypes for DIO peripheral 
 * Created: 5/21/2022 3:14:49 PM
 * Author: Mohamed Ismail
 */ 



#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "std_types.h"
#include "DIO_REG.h"

/******************************************************************************************
*								Preprocessor Macros                                       *
******************************************************************************************/

/* Define all ports */
#define PORTA	0
#define PORTB	1
#define PORTC	2
#define PORTD	3

/* define pin number */
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

/* define pin direction */ 
#define OUTPUT	1
#define INPUT	0

/* define pin state */
#define HIGH	1
#define LOW		0


/***************************************************************************************
*								Function Prototypes                                    *
***************************************************************************************/


/*********************************************************************************************************
 * Function Name: DIO_Init
 *
 * Description:  Function to initialize DIO
 *
 * Function Parameters:	 NONE          
 *
 * Returns:						NONE
 ********************************************************************************************************/
void DIO_Init(void);


/*********************************************************************************************************
 * Function Name: DIO_SetPinDirection
 *
 * Description:  Function to Set a pin direction depending on the state parameter
 *
 * Function Parameters:	 First Parameter is port number, Second Parameter is pin number, and Third Parameter          
 *
 * Returns:						NONE
 ********************************************************************************************************/
void DIO_SetPinDirection(uint8 portno, uint8 pinno, uint8 state);


/*********************************************************************************************************
 * Function Name: DIO_SetPortDirection
 *
 * Description:  Function to Set a port direction depending on the state parameter
 *
 * Function Parameters:	 First Parameter is port number, Second Parameter is port state         
 *
 * Returns:						NONE
 ********************************************************************************************************/
void DIO_SetPortDirection(uint8 portno, uint8 state);


/*********************************************************************************************************************************
 * Function Name: DIO_SetPinValue
 *
 * Description:  Function to Set a pin to a value (high or low) depending on the value parameter
 *
 * Function Parameters:	 First Parameter is port number, Second Parameter is pin number, and Third Parameter is value for the pin          
 *
 * Returns:						NONE
 ********************************************************************************************************************************/
void DIO_SetPinValue(uint8 portno, uint8 pinno, uint8 value);


/*********************************************************************************************************
 * Function Name: DIO_SetPortValue
 *
 * Description:  Function to Set a port to value depending on the given value parameter
 *
 * Function Parameters:	 First Parameter is port number, Second Parameter is value on the port        
 *
 * Returns:						NONE
 ********************************************************************************************************/
void DIO_SetPortValue(uint8 portno, uint8 value);


/*********************************************************************************************************
 * Function Name: DIO_RdPinValue
 *
 * Description:  Function to read pin value
 *
 * Function Parameters:	 First Parameter is port number, Second Parameter is pin number        
 *
 * Returns:				 pin value (high or low)
 ********************************************************************************************************/
uint8 DIO_RdPinValue(uint8 portno, uint8 pinno);


/*********************************************************************************************************
 * Function Name: DIO_RdPortValue
 *
 * Description:  Function to read a port value
 *
 * Function Parameters:	 Parameter is port number     
 *
 * Returns:				 Port value
 ********************************************************************************************************/
uint8 DIO_RdPortValue(uint8 portno);



#endif /* DIO_INT_H_ */