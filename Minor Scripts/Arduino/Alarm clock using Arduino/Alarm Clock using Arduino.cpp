//Include Libraries
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int seconds;//define integer variable for seconds
int prevtime = 0;

int hours = 0;//initialize hours to '0'
int mins = 0;//initialize minutes to '0'

int ahours = 0;//initialize alarm hour to '0'
int amins = 0;//initialize alarm minutes to '0'



void setup()
{
  lcd.begin(16, 2);//Initizlize LCD 
  
  Serial.begin(9600);//Initialize serial port

  pinMode(9, INPUT);//Taking input from button
  pinMode(13, INPUT);//Taking input from slideswitch
  pinMode(12, INPUT);//Taking input from slideswitch
  pinMode(11, INPUT);//Taking input from button
  pinMode(10, INPUT);//Taking input from button
  pinMode(8, OUTPUT);//Providing output to buzzer and LED
  
}


void loop()
{
  
  while(digitalRead(12) == LOW)//Checking condition at input 12
  {
    lcd.setCursor(4,1);
    lcd.print("Set-Alarm");
    
       if(digitalRead(11) == HIGH)//Checking for push button if pressed increments the minutes of alarm
    {
     amins++; 
    } 
    else if (digitalRead(10) == HIGH)//Checking for push button if pressed increments the hours of alarm
    {
      ahours++;
    }
    
    lcd.setCursor(4,0);
  
  if(ahours < 10)//if alarm hours less than '10'
  {
    lcd.print("0");//Display '0' in hours section
    lcd.print(ahours);
  }
  else
  {
    lcd.print(ahours);
  }
    
    lcd.print(":");
    
  if (amins < 10)//if alarm mins less than '10'
  {
    lcd.print("0");//Display '0' in minutes section
      lcd.print(amins);
  }
  else
  {
      lcd.print(amins);
  }
 if (amins > 59)//if alarm minutes greater than '59' increment hour by '1'
     {
      ahours++;
      amins = 0;
     } 
     if(ahours > 23)//if alarm hours greater than '23' set hours to '0'
     {
      ahours = 0; 
     }
    
     lcd.print(":00");
     delay(500);
  }
  

  
  if (digitalRead(13) == LOW)//if input for slideswitch is low
  {
    
    lcd.setCursor(4,1);
    lcd.print("Set-Time ");//set the actual time as per requirement
    lcd.setCursor(4,0);
    
     if(digitalRead(11) == HIGH)//increment minutes
    {
     mins++;
    } 
    else if (digitalRead(10) == HIGH)//increment hours
    {
      hours++;
    }
    
  } 
   if (digitalRead(13) == HIGH)
  {
    lcd.setCursor(4,1);
     lcd.print("IoT-Spot "); 
  } 
  

   seconds = (millis() / 1000);
      if(prevtime < (seconds - 59))//setting time according to desired timings
      {
       mins++;
       prevtime = seconds;
      } 
  
  
      if(mins > 59)
     {
      hours++;
      mins = 0;
     } 
     
     if(hours > 23)
     {
      hours = 0; 
     }
  
  lcd.setCursor(4,0);  
  
  if (hours < 10)
  {
    lcd.print("0");
    lcd.print(hours);
  }
  else
  {
    lcd.print(hours);
  }
    
    lcd.print(":");
    
  if (mins < 10)
  {
    lcd.print("0");
      lcd.print(mins);
  }
  else
  {
      lcd.print(mins);
  }
  
   lcd.print(":");
  
  if (seconds >59)
  {
    seconds = seconds-prevtime;
  }
  
  
  if (seconds < 10)
  {
    lcd.print("0");
    lcd.print(seconds);
  }
  else 
  {
    lcd.print(seconds);
  }
    
//If actual time and alarm time matches switch on LED and buzzer
if (ahours == hours && amins == mins && amins != 0)
{
  //Patteren are created for alarm sound
  tone(8, 1000);
  delay(100);
  noTone(8);
  delay(100);
  tone(8, 1000);
  delay(100);
  noTone(8);
  delay(100);
  tone(8, 1000);
  delay(100);
  noTone(8);
  delay(100);
  tone(8, 1000);
  delay(100);
  noTone(8);
  delay(1000);
}
  
if (digitalRead(9)==HIGH)
{
  ahours=0;
  amins=0;
}
  //Display information in serial port 
  Serial.print("minutes: ");
  Serial.println(mins);
  Serial.print("hours: ");
  Serial.println(hours);
  Serial.println("");
  Serial.print("alarm minutes: ");
  Serial.println(amins);
  Serial.print("alarm hours: ");
  Serial.println(ahours);
  Serial.println("");
  Serial.print("seconds: ");
  Serial.println(seconds);
  Serial.println("");
}