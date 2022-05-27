/*
 * LCD_PRG.c
 *
 * Created: 5/22/2022 6:30:08 PM
 *  Author: Mohamed Ismail
 */ 

#ifndef F_CPU
#define F_CPU	8000000UL
#endif

#include <util/delay.h>
#include "LCD_INT.h"

/* Private Function */
#if(mode == 4)
	/* LCD Initialize function for 4-bit mode */
	static void LCD_Init4(void);
	/* LCD send commands function to configure LCD for 4-bit mode */
	static void LCD_SendCommand4(uint8 cmd);
	/* LCD send char function to put on LCD display (panel) for 8-bit mode */
	static void LCD_SendChar4(uint8 data);
	
#elif(mode == 8)	
	/* LCD Initialize function for 8-bit mode */
	static void LCD_Init8(void);
	/* LCD send commands function to configure LCD for 8-bit mode */
	static void LCD_SendCommand8(uint8 cmd);
	/* LCD send char function to put on LCD display (panel) for 4-bit mode */
	static void LCD_SendChar8(uint8 data);
#endif

/* LCD Initialize function for any mode */
void LCD_Init(void)
{
	DIO_SetPinDirection(Control, RS, OUTPUT);
	DIO_SetPinDirection(Control, EN, OUTPUT);
	DIO_SetPinDirection(Control, R_W, OUTPUT);
	/* check LCD connection mode */
	#if (mode == 4)
	{
		/* set from pin 4---->7 in data port to be output */
		DIO_SetPortDirection(Date, 0xf0);
		LCD_Init4();
	}
	#elif (mode == 8)
	{
		/* set all pins in data port to be output */
		DIO_SetPortDirection(Date, OUTPUT);
		LCD_Init8();
	}
	#endif
}

#if(mode == 4)
/* LCD Initialize function for 4-bit mode */
static void LCD_Init4(void)
{
	/* Delay 50ms to ensure the initialization of the LCD driver start */
	_delay_ms(50);
	
	/* return cursor to start */
	LCD_SendCommand(CURSOR_HOME);
	_delay_ms(1);
	
	/* Function Set */
	LCD_SendCommand(FUNCTION_SET4B);
	_delay_ms(1);
	
	/* Display on */
	LCD_SendCommand(DISPLAY_ON);
	_delay_ms(1);
	
	/* Display Clear */
	LCD_SendCommand(DISPLAY_CLEAR);
	_delay_ms(20);
	
	/* Entry mode set */
	LCD_SendCommand(ENTRY_MODE);
	
	/* Set cursor */
	LCD_SendCommand(Set_Cursor);
	_delay_ms(2);
}

#elif(mode == 8)
/* LCD Initialize function for 8-bit mode */
static void LCD_Init8(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver start */
	_delay_ms(30);
	
	/* return cursor to start */
	LCD_SendCommand(CURSOR_HOME);
	_delay_ms(15);
	
	/* Function Set */
	LCD_SendCommand(FUNCTION_SET8B);
	_delay_ms(1);
	
	/* Display on */
	LCD_SendCommand(DISPLAY_ON);
	_delay_ms(1);
	
	
	/* Display Clear */
	LCD_SendCommand(DISPLAY_CLEAR);
	_delay_ms(15);
	
	/* Entry mode set */
	LCD_SendCommand(ENTRY_MODE);
	_delay_ms(2);
}
#endif

/* LCD send commands function to configure LCD for any mode */
void LCD_SendCommand(uint8 cmd)
{
	/* check LCD connection mode */
	#if (mode == 4)
	{
		LCD_SendCommand4(cmd);
	}
	#elif (mode == 8)
	{
		LCD_SendCommand8(cmd);
	}
	#endif
}

#if(mode == 4)
/* LCD send commands function to configure LCD for 4-bit mode */
static void LCD_SendCommand4(uint8 cmd)
{
	/* Set RS pin to 0 value for select command register */
	DIO_SetPinValue(Control, RS, LOW);
	/* Set R_W pin to 0 value for select write operation */
	DIO_SetPinValue(Control, R_W, LOW);
	/* Set E to HIGH */
	DIO_SetPinValue(Control, EN, HIGH);
	
	/* SEND the command high nibble to D4:D7 */
	uint8 x  = cmd & 0xf0;
	DIO_SetPortValue(Date, x);
	
	/* Set EN pin to 1 value then to 0 to make pulse */
	DIO_SetPinValue(Control, EN, LOW);
	/* Wait for E to settle */
	_delay_ms(1);
	DIO_SetPinValue(Control, EN, HIGH);
	/* Delay for 2ms to let the LCD execute command */
	_delay_ms(1);
	
	/* shift cmd to right by 4 , to send the Low nibble to D0:D4 */
	x  = (cmd << 4);
	DIO_SetPortValue(Date, x);
	/* Set EN pin to 1 value then to 0 to make pulse */
	DIO_SetPinValue(Control, EN, LOW);
	/* Wait for E to settle */
	_delay_ms(1);
	DIO_SetPinValue(Control, EN, HIGH);
	/* Delay for 2ms to let the LCD execute command */
	_delay_ms(1);
}
#elif(mode == 8)
/* LCD send commands function to configure LCD for 8-bit mode */
static void LCD_SendCommand8(uint8 cmd)
{
	/* Set RS pin to 0 value for select command register */
	DIO_SetPinValue(Control, RS, LOW);
	/* Set R_W pin to 0 value for select write operation */
	DIO_SetPinValue(Control, R_W, LOW);
	/* Set E to HIGH */
	DIO_SetPinValue(Control, EN, HIGH);
	
	/* Set data port to cmd value to send it for LCD D0->D7 */
	DIO_SetPortValue(Date, cmd);
	/* Set EN pin to 1 value then to 0 to make pulse */
	DIO_SetPinValue(Control, EN, LOW);
	/* Wait for E to settle */
	_delay_ms(1);
	DIO_SetPinValue(Control, EN, HIGH);
	/* Delay for 2ms to let the LCD execute command */
	_delay_ms(1);
}
#endif

/* LCD send char function to put on LCD display (panel) for any mode */
void LCD_SendChar(uint8 data)
{
	//check LCD connection mode
	#if (mode == 4)
	{
		LCD_SendChar4(data);
	}
	#elif (mode == 8)
	{
		LCD_SendChar8(data);
	}
	#endif
}

#if(mode == 4)
/* LCD send char function to put on LCD display (panel) for 4-bit mode */
static void LCD_SendChar4(uint8 data)
{
	/* Set RS pin to 1 value for select data register */
	DIO_SetPinValue(Control, RS, HIGH);
	/* Set R_W pin to 0 value for select write operation */
	DIO_SetPinValue(Control, R_W, LOW);
	/* Set E to HIGH */
	DIO_SetPinValue(Control, EN, HIGH);
	
	/* SEND the Data high nibble to D4:D7 */
	uint8 x  = data & 0xf0;
	DIO_SetPortValue(Date, x);
	/* Set EN pin to 1 value then to 0 to make pulse */
	DIO_SetPinValue(Control, EN, LOW);
	/* Wait for E to settle */
	_delay_ms(2);
	DIO_SetPinValue(Control, EN, HIGH);
	/* Delay for 2ms to let the LCD execute command */
	_delay_ms(2);
	
	/* shift data to right by 4 , to send the Low nibble to D0:D4 */
	x  = (data << 4);
	DIO_SetPortValue(Date, x);
	/* Set EN pin to 1 value then to 0 to make pulse */
	DIO_SetPinValue(Control, EN, LOW);
	/* Wait for E to settle */
	_delay_ms(2);
	DIO_SetPinValue(Control, EN, HIGH);
	/* Delay for 2ms to let the LCD execute command */
	_delay_ms(2);
}

#elif(mode == 8)
/* LCD send char function to put on LCD display (panel) for 8-bit mode */
static void LCD_SendChar8(uint8 data)
{
	/* Set RS pin to 1 value for select data register */
	DIO_SetPinValue(Control, RS, HIGH);
	/* Set R_W pin to 0 value for select write operation */
	DIO_SetPinValue(Control, R_W, LOW);
	/* Set E to HIGH */
	DIO_SetPinValue(Control, EN, HIGH);
	
	/* Set data port to data value to send it for LCD D0->D7 */
	DIO_SetPortValue(Date, data);
	/* Set EN pin to 1 value then to 0 to make pulse */
	DIO_SetPinValue(Control, EN, LOW);
	/* Wait for E to settle */
	_delay_ms(1);
	DIO_SetPinValue(Control, EN, HIGH);
	/* Delay for 1ms to let the LCD execute command */
	_delay_ms(1);
}
#endif

/* LCD send string function to put on LCD display (panel) */
void LCD_SendString(uint8 * data)
{
	uint8 i; 
	for (i = 0; data[i] != '\0'; i++)
	{
		LCD_SendChar(data[i]);
		/* Delay to let LCD write character */ 
		_delay_ms(2);
	}
}

/* go to xy position */
void LCD_Goto_xy(uint8 row,uint8 col)
{
	uint8 pos = 0;
	
	switch(row)
	{
		case 0:
				pos = col;
				break;
		case 1:
				pos = col+0x40;
				break;
		case 2:
				pos = col+0x14;
				break;
		case 3:
				pos = col+0x54;
				break;
	}					
	/* send command to set cursor at pos */
	LCD_SendCommand(pos | 0x80); 
}

/* write a string into LCD in x-y position */
void LCD_String_xy (uint8 row, uint8 pos, uint8* data)
{
	/* go to LCD position required position */
	LCD_Goto_xy(row,pos); 
	
	/* display the string */
	LCD_SendString(data); 
}

/* write number into LCD */ 
void LCD_SendNumber(uint16 Number)
{
	uint8 i = 0, arr[10];
	if (Number == 0)
	{
		LCD_SendChar ('0');
	}
	while (Number != 0)
	{
		arr[i] = Number % 10 + '0';
		Number = Number / 10;
		i++; 
	}
	while (i > 0)
	{
		LCD_SendChar(arr[i-1]);
		i--;
	}
}

/* clear LCD display */
void LCD_Clear(void)
{
	LCD_SendCommand(DISPLAY_CLEAR);
	LCD_SendCommand(CURSOR_HOME);
}




