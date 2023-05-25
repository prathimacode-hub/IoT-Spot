
#include "STD_Types.h"
#include "I2C_Init.h"

#define RTC_READ_ADD 0xD1
#define RTC_WRITE_ADD 0xD0


//Global variables

//RTC struct
typedef struct RTC_Handle{
    u8 seconds;
    u8 minutes;
    u8 hours;
    u8 day_time;
    u8 days;
    u8 months;
    u8 years;
}RTC_Handle;


u8 receiveBuff[7];
u8 sendBuff[8];

I2C_Handle i2c_handle;


void RTC_bcdDecoder(u8 *bcd_data, RTC_Handle *rtc_handle);
void RTC_bcdEncoder(u8 *bcd_data, RTC_Handle *rtc_handle);
void RTC_Init();
void RTC_setTime(RTC_Handle *handle);
void RTC_getTime(RTC_Handle *handle);




