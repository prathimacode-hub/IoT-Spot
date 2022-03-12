
//Circuit Connections:
//connect SCL of the RTC with A5
//connect SDA of the RTC with A4

#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"
 
RTC_DS3231 realtc; //Real Time Clock Variable
 
char week_days[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
 
int day, month, year, sec, minutes, hours;
 
String day_name, mydate, mytime; 
 
// Pin out for 16x2 LCD
 
#define rs 2 // rs to Pin 9 on Arduino
#define en 3 // en to Pin 8 on Arduino
#define d4 4 // d4 to Pin 7 on Arduino
#define d5 5 // d5 to Pin 6 on Arduino
#define d6 6 // d6 to Pin 5 on Arduino
#define d7 7 // d7 to Pin 4 on Arduino

// initialize the library with the numbers of the interface pins
LiquidCrystal display(rs, en, d4, d5, d6, d7);
 
void setup() {
  Serial.begin(9600);
  display.begin(16, 2);
  delay(2000);
 
  if (!realtc.begin()) {
    Serial.println("Cannot find the Real Time Clock");
    while true;
  }
 
  if (realtc.lostPower()) {
    Serial.println("Real Time Clock lost power. Let's set the time: ");
  
    // Following line sets the RTC to the date & time this sketch was compiled
    realtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
    // You can also set date and time explicitly
    // realtc.adjust(DateTime(2022, 3, 2, 17, 43, 0)); = March 2 2022 at 17:43
  }
}
 
void loop() {

DateTime now = realtc.now();

display.clear();        

day = now.day(); month = now.month(); year = now.year();
secs = now.second(); hours = now.hour(); minutes = now.minute(); 

day_name = week_days[now.dayOfTheWeek()];  
 
mydate = mydate +day_name+ " "+ day + "/" + month + "/" + year ; 
mytime = mytime + hours +":"+ minutes +":" + secs ; 

// send to serial monitor
Serial.println(day_name); 
Serial.println(mydate); 
Serial.println(mytime);

//To print on display
display.setCursor(0,0);
display.print(mydate); 
display.setCursor(0,1); 
display.print(mytime); 

mydate = "";   
mytime = ""; 
delay(1000);

}
