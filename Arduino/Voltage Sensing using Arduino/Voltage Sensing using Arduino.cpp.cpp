
//Include all libraries
// include the library code:
#include <LiquidCrystal.h>
//include the Serial library
#include<SoftwareSerial.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //Setup Serial port
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 4, line 0
  lcd.setCursor(4, 0);
   lcd.print("IoT-Spot");
   // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  // set the cursor to column 1, line 1
  lcd.setCursor(1,1);
  lcd.print("Voltage:");
  lcd.print(voltage);
  lcd.print("V");
  //print on serial port as well
  Serial.println(voltage);
  //give delay for 100ms(may vary)
  delay(100);
}
 