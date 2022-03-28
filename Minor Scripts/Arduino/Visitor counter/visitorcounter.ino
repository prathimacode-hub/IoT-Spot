#include <LiquidCrystal.h>   //Library for lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //LCD pin setup

int buzzerpin = 6; // pin for the piezo
int trigpin = 10;   //trigger pin of ultrasonic sensor
int echopin = 9;     //echopin of ultrasonic sensor
int status = 0; // variable for reading the pin status
int visits = 0;   //visitor count
int currentstate = 0;   //for current state of piezo
int previousstate = 0;    //for previous state piezo



void setup() {
  lcd.begin(16, 2);  //begin lcd
  pinMode(buzzerpin, OUTPUT); // declare piezo as output
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);   //begin serial monitor.
  lcd.setCursor(0,0);
  lcd.print("visitor counter");  //printing on lcd
  delay(2000);
  lcd.clear();
}






void loop(){
delay(200);// reading will be taken after 200 milliseconds

int duration, distance;
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration = pulseIn (echopin, HIGH);   //output from sensor
distance = (duration/2) / 29.1;  //converting it into distance
  
if (distance < 15) //if distance less than 15 alaram will buzz.
{  
  // Change the number for long or short distances.
      digitalWrite(buzzerpin, HIGH);
}


 else
{
      digitalWrite(buzzerpin, LOW);
} 



status = digitalRead(buzzerpin); // read input value
if (status ==  HIGH) 
{ 
    // check if the input is HIGH (piezo on)
    currentstate = 1;
}



else //else set current state of buzzer as 0
{
      currentstate = 0;
}


if(currentstate != previousstate)
{  
  //to check if piezo is not still buzzing
  


if(currentstate == 1)
{   
  //if piezo is buzzing
visits = visits + 1;  //increasing number of visitor by one
//printing on LCD
lcd.clear();
lcd.setCursor(0,0);
lcd.print("People visited:"); 
lcd.setCursor(0,1);
lcd.print(visits);
delay(400);
}


}


//updating previous state by current state
previousstate = currentstate;



}
 