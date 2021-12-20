// C++ code
//
#include<Servo.h>

Servo motor1;
int potpin = 0;		// The Analog input pin to read potentiometer
int led_pin = 10;
int potval, val1;

void setup()
{
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  motor1.attach(8);
  motor1.write(0);
  analogWrite(led_pin, 0);
}

void loop()
{
  potval = analogRead(potpin);					// Read the input of potentiometer (0-1023)
  val1 = map(potval, 0, 1023, 0, 180);			// Scale it to servo angle range (0-180 degrees)
  motor1.write(val1);							// Sets the servo angle accordingly
  int intensity = map(val1, 0, 180, 0, 255);	// Set LED brightness based on degree of rotation
  analogWrite(led_pin, intensity);				// Turn ON LED at required brightness
  delay(20);									// Time delay to overcome motor inertia
}