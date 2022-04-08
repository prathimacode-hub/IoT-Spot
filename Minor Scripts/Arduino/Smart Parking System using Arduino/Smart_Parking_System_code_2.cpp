//Include libraries
#include <LiquidCrystal.h>
#include <Servo.h>

int cm = 0;//Initialize distance to zero
int inches = 0;
int pos = 0;//Initialize position
int cm1=0;
int buzzer=13;//Initialize buzzer pin no.
int buzzer1=10;

//Function to read and perform opertaions on ultrasonic sensor
long readUltrasonicDistance(int triggerPin, int echoPin)
{
    pinMode(triggerPin, OUTPUT); // Clear the trigger
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Sets the trigger pin to HIGH state for 10 microseconds
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    // Reads the echo pin, and returns the sound wave travel time in microseconds
    return pulseIn(echoPin, HIGH);
}

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
    Serial.begin(9600);//Initialize serial port
    lcd.begin(16, 2);
    lcd.print("Smart Parking");
    lcd.setCursor(0, 1);
    lcd.print("   System");
    delay(2000); // Millisecond
    lcd.clear();
    lcd.setCursor(0, 0);
	pinMode(buzzer,OUTPUT);
  	pinMode(buzzer1,OUTPUT);
    lcd.print("Total two");
    lcd.setCursor(0, 1);
    lcd.print("Parking Slots");
}


void loop()
{
    // measure the ping time in cm
    cm = 0.01715 * readUltrasonicDistance(6, 7);//Passing parameters and assigning values
  	cm1 = 0.01715 * readUltrasonicDistance(8, 9);
    // convert to inches by dividing by 2.54
    inches = (cm / 2.54);
    Serial.print(cm);
    Serial.print("cm, ");
    Serial.print(inches);
    Serial.println("in");
  //Applying various conditions
    if (cm >= 0 && cm <= 50)
    {
        tone(buzzer, 500); // Send 1KHz sound signal...     // Stop sound...
  		delay(1000);
      	noTone(buzzer);//Buzzer off
      	delay(1000);
    }
    if (cm > 50)
    {
        noTone(buzzer);
      	delay(1000);
    }
  	if (cm1 >= 0 && cm1 <= 50)
    {
        tone(buzzer1, 500); // Send 1KHz sound signal...     // Stop sound...
  		delay(1000);
      	noTone(buzzer1);
      	delay(1000);
    }
    if (cm1 > 51)
    {
        noTone(buzzer1);
      	delay(1000);
    }
}