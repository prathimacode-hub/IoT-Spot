#include<LiquidCrystal.h>
int signalpin=2;
int buzzerpin=3;
int rs=12, en=11, d4=7, d5=6,d6=5,d7=4;
// for the display
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup()
{
  pinMode(signalpin,INPUT);
  pinMode(buzzerpin,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  //lcd display
  lcd.print("DragonUncaged's House");
  //second line of lcd display
  lcd.setCursor(0,1);
  lcd.print("Get Near to Door");
  }
void loop()
{
  //for  the sensor
  if(digitalRead(signalpin)==HIGH)
    {
      //sensitivity for the buzzer
    tone(buzzerpin,200);
     delay(50);
     tone(buzzerpin,500);
     delay(50);
     tone(buzzerpin,900);
     delay(50);
     tone(buzzerpin,1000);
     delay(50);
     tone(buzzerpin,1300);
     delay(50);
     tone(buzzerpin,1800);
     delay(50);
     } 
  else
    {
    noTone(buzzerpin);
    }
}