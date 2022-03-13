//Including all libraries
// include the library code
#include <LiquidCrystal.h>
//include serial library
#include <SoftwareSerial.h>

//Declaring variables
int fl;//Input Variable
int buz=13;//Pin for buzzer
int led=13;//Pin for LED
int flag;// status

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(fl,INPUT);//Declaring flame sensor
pinMode(buz,OUTPUT);//Declaring buzzer
pinMode(led,OUTPUT);//Declaring LED 
Serial.begin(9600);//Initialising serial port
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(4, 0);
  lcd.print("IoT-Spot");
  flag= digitalRead(fl);
  if(Serial.available()){//Taking Serial Input
    flag = Serial.read();//Reading Input
    Serial.write(flag);//Displaying input in Serial Port
    Serial.println("\n");
  }
if( flag==1)
{
  tone(buz, 1000, 1000);//Keeping buzzer on with frequency 1000Hz
  digitalWrite(led,HIGH);//Switching on LED
  lcd.setCursor(6,1);//LCD Display
  lcd.print("FIRE!");
  Serial.println("Alert! Flame detected");
  delay(2000);
  lcd.setCursor(2,1);
  lcd.print("         ");
}
  //For input 1 status of fire on
  if(flag!=1)
{
  digitalWrite(buz,LOW);//Keeping buzzer off
  digitalWrite(led,LOW);//Keeping LED on
  Serial.println("No-Flame detected");
  lcd.setCursor(4,1);
  lcd.print("N0-FIRE!");
  delay(2000);
  lcd.setCursor(2,1);
  lcd.print("         ");

  } 
}
 