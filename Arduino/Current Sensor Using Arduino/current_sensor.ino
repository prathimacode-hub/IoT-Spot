#include <LiquidCrystal.h>  //including liquidcrystal library for lcd
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  //setting lcd pins to arduino
const int sensorpin = A0;  //current sensor input pin
int sensitivity = 66;  //standard sensitivity of sensor
int adcValue= 0; //ADC value is a rationmatric value
int offsetVoltage = 2500;  //offset voltage (the voltage that must be applied to the input to cause the output to be 0.)
double voltage = 0;  //inital voltage
double current = 0;  //inital current value
void setup() 
{
  lcd.begin(16, 2);  //lec starts
  lcd.print(" Current Sensor");
  delay(2000);
} 
void loop()
{
   adcValue = analogRead(sensorpin);   //taking input from current sensor and storing in variable
  voltage = (adcValue / 1024.0) * 5000;    //voltage in mV
                                            //5000 is analog reference voltage which is default value. 
                                            //1024 as analog voltage lies between 0 to 1024V 
  current = ((voltage - offsetVoltage) / sensitivity);   //for current we need to divide voltage with sensitivity
 ////while no current is flowing through +-IP, assume vcc as 5V at vout is 2.5V. So  it is subtracted(offsetVoltage)
  lcd.clear();
  delay(1000);
  //displaying values on lcd screen
  lcd.setCursor(0,0);
  lcd.print("Current is   ");
  lcd.setCursor(10,0);
  lcd.print(current,2);
  lcd.setCursor(14,0);
  lcd.print("A");
  delay(2500);
}