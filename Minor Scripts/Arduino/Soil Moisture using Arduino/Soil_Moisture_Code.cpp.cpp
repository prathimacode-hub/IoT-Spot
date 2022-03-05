//Inlcuding libraries
// include the Serial library
#include <SoftwareSerial.h>
// include the library code:
#include <LiquidCrystal.h>
//defining analog pin
#define sensor_pin A4 
int Input;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);//Initializing Serial port no.
}

void loop() {
  // set the cursor to column 4, line 0
  lcd.setCursor(4, 0);
  lcd.print("IoT-Spot");
  // set the cursor to column 1, line 1
  lcd.setCursor(1, 1);
  lcd.print("Soil-Moisture");
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);//Reading Analog Value
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );//Performing calculations
  Serial.print("Moisture Percentage = ");//Printing result in serial port
  Serial.print(moisture_percentage);//Printing percentage
  Serial.print("%\n\n");
  delay(1000);//Displaying for every 1000ms
  
}
 