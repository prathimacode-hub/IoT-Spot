
#include <LiquidCrystal.h>   // including library for lcd
int fsrpin=0;  //for force sensor pin;
int fsrread; //to store vlue from sensor
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //setting lcd pins

void setup() {
  lcd.begin(16, 2);   //starts lcd
  lcd.print("Pressure sensor");
  delay(1000);
  lcd.clear();   //clear lcd screen
}

void loop() {
   fsrread = analogRead(fsrpin);   //reading data from force sensor and stroing in a variable
   //printing value on lcd
  lcd.print("Pressure: ");
  lcd.print(fsrread);
    lcd.print(" Pa");

  delay(400);
  lcd.clear();
}
 