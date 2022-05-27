/*
 * LCD_Driver.c
 *
 * Created: 5/22/2022 5:23:12 PM
 * Author : Mohamed Ismail
 */ 

#ifndef F_CPU
#define F_CPU	8000000UL
#endif

#include "LCD_INT.h"
#include "DIO_INT.h"
#include "std_types.h"


int main(void)
{
	//Initialize LCD
	LCD_Init();
	//Clear screen
	LCD_Clear();
	/* Goto first location in LCD*/ 
	LCD_Goto_xy(0,0);
	//write MOHAMEDISMAIL on screen
	LCD_SendString("mohamedismail");
	LCD_String_xy(1, 0, "ahmed");
	LCD_Goto_xy(1, 7);
	uint16 x = 30;
	LCD_SendNumber(x);
    while (1) 
    {
				
    }
}

