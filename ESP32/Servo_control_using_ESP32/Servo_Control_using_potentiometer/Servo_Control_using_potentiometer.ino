#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo

// Possible PWM GPIO pins on the ESP32: 0(used by on-board button),2,4,5(used by on-board LED),12-19,21-23,25-27,32-33

int  servoPin  =  18;  // GPIO pin used to connect the servo control (digital out)

// Possible ADC pins on the ESP32: 0,2,4,12-15,32-39; 34-39 are recommended for analog input

int  potPin  =  34;  // GPIO pin used to connect the potentiometer (analog in)

int  ADC_Max  =  4096;  // This is the default ADC max value on the ESP32 (12 bit ADC width);

// this width can be set (in low-level oode) from 9-12 bits, for a

// a range of max values of 512-4096

int  val;  // variable to read the value from the analog pin

void  setup()

{

// Allow allocation of all timers

ESP32PWM::allocateTimer(0);

ESP32PWM::allocateTimer(1);

ESP32PWM::allocateTimer(2);

ESP32PWM::allocateTimer(3);

myservo.setPeriodHertz(50);// Standard 50hz servo

myservo.attach(servoPin,  500,  2400);  // attaches the servo on pin 18 to the servo object

// using SG90 servo min/max of 500us and 2400us

// for MG995 large servo, use 1000us and 2000us,

// which are the defaults, so this line could be

// "myservo.attach(servoPin);"

}

void  loop()  {

val  =  analogRead(potPin);  // read the value of the potentiometer (value between 0 and 1023)

val  =  map(val,  0,  ADC_Max,  0,  180);  // scale it to use it with the servo (value between 0 and 180)

myservo.write(val);  // set the servo position according to the scaled value

delay(200);  // wait for the servo to get there

}