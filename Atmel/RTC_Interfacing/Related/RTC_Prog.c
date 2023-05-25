#include "STD_Types.h"
#include "I2C_Init.h"
#include "RTC_Init.h"


//---------------RTC initialization-----------------------
void RTC_Init()
{
    i2c_handle.address = 0x44;
    i2c_handle.clock = I2C_BIT_RATE_FOR_100KHZ;
    i2c_handle.receiveBuff = receiveBuff; // receive buffer for storing time from RTC
    i2c_handle.receiveBuffLen = 7;
    i2c_handle.sendBuff = sendBuff;  // send buffer for wirting time to RTC
    i2c_handle.sendBuffLen = 7;
    I2C_Init(&i2c_handle);  // initialize I2C handle
}

//------------Function for retrieving time from RTC-------------
void RTC_getTime(RTC_Handle *rtc_handle)
{       
    //--------reset the register pointer
    i2c_handle.sendBuff[0] = 0x00;
    i2c_handle.sendBuffLen = 1;
    I2C_Start(RTC_WRITE_ADD);
    I2C_Master_Write(&i2c_handle);
    I2C_End();
    //---------
    
    //-----Read date&time
    I2C_Start(RTC_READ_ADD);
    I2C_Master_Read(&i2c_handle);
    I2C_End();
    //------

    //decode date & time
    RTC_bcdDecoder(i2c_handle.receiveBuff,rtc_handle);
}


//--------------Function for decoding the BCD data received from RTC---------------
void RTC_bcdDecoder(u8 *bcd_data, RTC_Handle *rtc_handle)
{
    rtc_handle->seconds = ((u8)(bcd_data[0] >> 4)*10)  + (bcd_data[0] & 0x0F);
    rtc_handle->minutes = (bcd_data[1] >> 4)*10  + (bcd_data[1] & 0x0F);
    rtc_handle->hours = (bcd_data[2] >> 4)*10  + (bcd_data[2] & 0x0F);
    rtc_handle->days =  (bcd_data[4] >> 4)*10  + (bcd_data[4] & 0x0F);
    rtc_handle->months = (bcd_data[5] >> 4)*10  + (bcd_data[5] & 0x0F);
    rtc_handle->years = (bcd_data[6] >> 4)*10  + (bcd_data[6] & 0x0F);
}


//--------------Function for encoding the BCD data to store in RTC---------------
void RTC_bcdEncoder(u8 *bcd_data, RTC_Handle *rtc_handle)
{
	bcd_data[0] = 0;
    bcd_data[1] = (((u8)(rtc_handle->seconds/10)) << 4) | (rtc_handle->seconds%10);
    bcd_data[2] = (((u8)(rtc_handle->minutes/10)) << 4) | (rtc_handle->minutes%10);
    bcd_data[3] = (((u8)(rtc_handle->hours/10)) << 4) | (rtc_handle->hours%10);
    bcd_data[5] = (((u8)(rtc_handle->days/10)) << 4) | (rtc_handle->days%10);
    bcd_data[6] = (((u8)(rtc_handle->months/10)) << 4) | (rtc_handle->months%10);
    bcd_data[7] = (((u8)(rtc_handle->years/10)) << 4) | (rtc_handle->years%10);
}

//------------Function for storing time to RTC-------------
void RTC_setTime(RTC_Handle *rtc_handle)
{
   //--------- reset the register pointer
   i2c_handle.sendBuff[0] = 0x00;
   i2c_handle.sendBuffLen = 1;
   I2C_Start(RTC_WRITE_ADD);
   I2C_Master_Write(&i2c_handle);
   I2C_End();
   //----------------------
    RTC_bcdEncoder(i2c_handle.sendBuff,rtc_handle);
    //---------set day&time
    i2c_handle.sendBuffLen = 8;
    I2C_Start(RTC_WRITE_ADD);
    I2C_Master_Write(&i2c_handle);
    I2C_End();
    //---------
}
