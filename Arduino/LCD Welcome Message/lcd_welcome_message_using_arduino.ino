#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buzzerPin = 8;
String msg1 = "Welcome to";
String msg2 = "IoT-Spot";
int size = msg2.length();

void setup() {
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
  tone(buzzerPin, 1000);  
  delay(50);
  noTone(buzzerPin);
  delay(50);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(msg1);
  lcd.setCursor(16-size, 1);
  lcd.print(msg2);
  
}