#define F_CPU 8000000UL

#include <avr/delay.h>
#include "Related/STD_Types.h"
#include "Related/UART_Init.h"
#include "Related/RTC_Init.h"



void main()
{
    RTC_Handle rtc_handle;
    RTC_Init();
    UART_Init();
    while(1)
    {
        //get time
        RTC_getTime(&rtc_handle);
        //Display time on terminal
        UART_PrintNum(rtc_handle.hours);
        UART_SendStr(":");
        UART_PrintNum(rtc_handle.minutes);
        UART_SendStr(":");
        UART_PrintNum(rtc_handle.seconds);
        UART_SendStr("      ");
        _delay_ms(1000);
    }

}