//Include Libraries
#include <LiquidCrystal.h>
#include <Servo.h>

Servo s1, s2;
//Define pin for infrared sensor
#define IR_Slot1 7  
#define IR_Slot2 8
#define IR_Entry 6
#define IR_Exit 13

int cm = 0; //Iniialize distance
int inches = 0;
int count=2;//Initialize parking slot count
int pos = 0;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
    Serial.begin(9600);//Setup serial port
    s1.attach(10);//Setup servo pin 
    s2.attach(9);

    s1.write(pos);//Rotate motor to given position
    s2.write(pos);

    pinMode(IR_Slot1, INPUT);
    pinMode(IR_Slot2, INPUT);
    pinMode(IR_Entry, INPUT);
    pinMode(IR_Exit, INPUT);

    lcd.begin(16, 2);
    lcd.print("Smart Parking");
    lcd.setCursor(0, 1);
    lcd.print("   System");
    delay(2000); // Millisecond
    lcd.clear();
    lcd.setCursor(0, 0);

    lcd.print("Slot available");
    lcd.setCursor(0, 1);
    lcd.print(count);
    
}
  
void loop()
{
    // measure the ping time in cm
    
    Serial.print(cm);
    Serial.print("cm, ");
    Serial.print(inches);
    Serial.println("in");
    
  //If infrared sensor enabled
    if (digitalRead(IR_Entry) == HIGH)
    {
        s1.write(pos + 90);//Rotate motor
      	count--;
      	lcd.clear();
      	lcd.setCursor(0,0);
      	lcd.print("Slot available");
    	lcd.setCursor(0, 1);
    	lcd.print(count);
      	delay(10000);
    }
    else
    {
        s1.write(pos);
    }
    if (digitalRead(IR_Exit) == HIGH)
    {
        s2.write(pos + 90);
      	count++;
      	lcd.clear();
      	lcd.setCursor(0,0);
      	lcd.print("Slot available");
    	lcd.setCursor(0, 1);
    	lcd.print(count);
      	delay(10000);
    }
    else
    {
        s2.write(pos);
    }

  //If count of cars less than zero
  	if(count<0)
    {
    	lcd.clear();
      	lcd.setCursor(0,0);
      	lcd.print("Not available");
      	count=0;
    }
  //If count of cars more than maximum(here it's two)
  	if(count>2)
    {
    	lcd.clear();
      	lcd.setCursor(0,0);
      	lcd.print("All empty");
      	count=0;
    }
  delay(3000);
}