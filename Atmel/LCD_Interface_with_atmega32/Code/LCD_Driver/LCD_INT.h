/*
 * LCD_INT.h
 * Description: 16x2 Character LCD for chip LMB161A  
 * Created: 5/22/2022 5:29:17 PM
 *  Author: Mohamed Ismail
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_

/******************************************************************************************
*								Preprocessor Macros                                       *
******************************************************************************************/

/* includes */
#include "delay.h"
#include "LCD_CONFIG.h"

/* FUNCTION_SET4B command for interface data length, font size, and number of lines for 4-bit mode */
#define	FUNCTION_SET4B	0X28


/* FUNCTION_SET8B command for interface data length, font size, and number of lines for 8-bit mode */ 
#define	FUNCTION_SET8B	0x38

/* return cursor to start row0, character 0 */
#define	CURSOR_HOME	0X02

/* display on, cursor off, don't blink character */
#define	DISPLAY_ON	0X0C


/* replace all characters with ASCII 'space' */
#define DISPLAY_CLEAR	0x01

/* shift cursor from left to right on read/write */
#define ENTRY_MODE	0x06  

/* SET cursor */
#define Set_Cursor   0x80        
  

/***************************************************************************************
*								Function Prototypes                                    *
***************************************************************************************/


/* LCD Initialize function for any mode */
void LCD_Init(void);

/* LCD send commands function to configure LCD for any mode */
void LCD_SendCommand(uint8 cmd);

/* LCD send char function to put on LCD display (panel) for any mode */
void LCD_SendChar(uint8 data);

/* LCD send string function to put on LCD display (panel) */
void LCD_SendString(uint8* data);

/* go to xy position */
void LCD_Goto_xy(uint8 row,uint8 col);

/* write a string into LCD in x-y position */
void LCD_String_xy (uint8 row, uint8 pos, uint8* data);

/* write number into LCD */
void LCD_SendNumber(uint16 Number);

/* clear LCD display */
void LCD_Clear(void);

#endif /* LCD_INT_H_ */