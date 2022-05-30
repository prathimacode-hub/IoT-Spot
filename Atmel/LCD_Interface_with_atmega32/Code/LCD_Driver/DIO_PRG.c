/*
 * DIO_PROG.c
 * Description: Function implementation to DIO peripheral
 * Created: 5/21/2022 3:32:11 PM
 * Author: Mohamed Ismail
 */ 

#include "DIO_INT.h"
#include "Bit_Math.h"
#include "DIO_REG.h"
#include "DIO_CONFIG.h"

/*
* Description: Function to initialize DIO
*/
void DIO_Init(void)
{
	DDRA_REG = DDRA_INIT;
	DDRB_REG = DDRB_INIT;
	DDRC_REG = DDRC_INIT;
	DDRD_REG = DDRD_INIT;
	
	PORTA_REG = PORTA_INIT;
	PORTB_REG = PORTB_INIT;
	PORTC_REG = PORTC_INIT;
	PORTD_REG = PORTD_INIT;
}


/*
 * Description:  Function to Set pin direction
 *					- switch over ports 
 *					- check if state is OUTPUT
 *					- if so, set pin number in the register to output state 
 *					- else 	clear that pin
 */
void DIO_SetPinDirection(uint8 portno, uint8 pinno, uint8 state)
{
	/* Switch over portno if it 0->>>PORTA, if 1->>>PORTB, if 2->>>PORTC, if 3->>>PORTD */
	switch (portno)
	{
		case PORTA:
			/* check state */
			if (state == OUTPUT)
			{
				SET_BIT(DDRA_REG, pinno);
			}
			else
			{
				CLR_BIT(DDRA_REG, pinno);
			}
			break;
			
		case PORTB:
			/* check state */
			if (state == OUTPUT)
			{
				SET_BIT(DDRB_REG, pinno);
			}
			else
			{
				CLR_BIT(DDRB_REG, pinno);
			}
			break;
			
		case PORTC:
			/* check state */
			if (state == OUTPUT)
			{
				SET_BIT(DDRC_REG, pinno);
			}
			else
			{
				CLR_BIT(DDRC_REG, pinno);
			}
			break;
			
		case PORTD:
			/* check state */
			if (state == OUTPUT)
			{
				SET_BIT(DDRD_REG, pinno);
			}
			else
			{
				CLR_BIT(DDRD_REG, pinno);
			}
			break;
	}
}


/*
 * Description:  Function to Set PORT direction
 *					- switch over ports 
 *					- check if state is OUTPUT
 *					- if so, set all pins in the register to output state 
 *					- else if INPUT clear that all pins
 *					- else put state
 */
void DIO_SetPortDirection(uint8 portno, uint8 state)
{
	/* check which port */
	switch (portno)
	{
		case PORTA:
			/* check direction state for port */
			if (state == OUTPUT)
			{
				DDRA_REG = 0XFF;
			}
			else if (state == INPUT)
			{
				DDRA_REG = 0X00;
			}
			else
			{
				DDRA_REG |= state;		
			}
			break;
			
		case PORTB:
			/* check direction state for port */
			if (state == OUTPUT)
			{
				DDRB_REG = 0XFF;
			}
			else if (state == INPUT)
			{
				DDRB_REG = 0X00;
			}
			else
			{
				DDRB_REG |= state;
			}
			break;
			
		case PORTC:
			/* check direction state for port */
			if (state == OUTPUT)
			{
				DDRC_REG = 0XFF;
			}
			else if (state == INPUT)
			{
				DDRC_REG = 0X00;
			}
			else
			{
				DDRC_REG |= state;
			}
			break;
			
		case PORTD:
			/* check direction state for port */
			if (state == OUTPUT)
			{
				DDRD_REG = 0XFF;
			}
			else if (state == INPUT)
			{
				DDRD_REG = 0X00;
			}
			else
			{
				DDRC_REG |= state;
			}
			break;
	}
}


/*
 * Description:  Function to Set pin to a value
 *					- switch over ports 
 *					- check if value is HIGH
 *					- if so, set pin number in the register to HIGH state 
 *					- else 	clear that pin
 */
void DIO_SetPinValue(uint8 portno, uint8 pinno, uint8 value)
{
	/* check which port */
	switch (portno)
	{
		case PORTA:
			/* check if value is high */
			if (value == HIGH)
			{
				SET_BIT(PORTA_REG, pinno);	
			}
			else
			{
				CLR_BIT(PORTA_REG, pinno);
			}
			break;
		
		case PORTB:
			/* check if value is high */
			if (value == HIGH)
			{
				SET_BIT(PORTB_REG, pinno);
			}
			else
			{
				CLR_BIT(PORTB_REG, pinno);
			}
			break;
		
		case PORTC:
			/* check if value is high */
			if (value == HIGH)
			{
				SET_BIT(PORTC_REG, pinno);
			}
			else
			{
				CLR_BIT(PORTC_REG, pinno);
			}
			break;
			
		case PORTD:
			/* check if value is high */
			if (value == HIGH)
			{
				SET_BIT(PORTD_REG, pinno);
			}
			else
			{
				CLR_BIT(PORTD_REG, pinno);
			}
			break;
	}
}

/*
 * Description:  Function to Set port to a value
 *					- switch over ports 
 *					- set port to its value
 */
void DIO_SetPortValue(uint8 portno, uint8 value)
{
	/* check which port */
	switch (portno)
	{
		case PORTA:	PORTA_REG = value;	break;
		case PORTB:	PORTB_REG = value;	break;
		case PORTC:	PORTC_REG = value;	break;
		case PORTD:	PORTD_REG = value;	break;
	}
}


/*
 * Description:  Function to Read value of a pin and return it
 *					- switch over ports 
 *					- read the value of a pin and return it
 */
uint8 DIO_RdPinValue(uint8 portno, uint8 pinno)
{
	uint8 ret = 0;
	
	switch (portno)
	{
		case PORTA: ret = RD_BIT(PINA_REG, pinno);	break;
		case PORTB: ret = RD_BIT(PINB_REG, pinno);	break;
		case PORTC: ret = RD_BIT(PINC_REG, pinno);	break;
		case PORTD: ret = RD_BIT(PIND_REG, pinno);	break;	
	}
	return ret;
}

 
/*
 * Description:  Function to read port value and return it
 *					- switch over ports 
 *					- read the value of a port and return it
 */
uint8 DIO_RdPortValue(uint8 portno)
{
	uint8 ret = 0;
	
	switch (portno)
	{
		case PORTA: ret = PINA_REG; break;
		case PORTB: ret = PINB_REG;	break;
		case PORTC:	ret = PINC_REG;	break;
		case PORTD: ret = PIND_REG;	break;
	}
	return ret;
}