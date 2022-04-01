#include <IRremote.h>       //adding library for IR sensor 
int led = 5;                //Setting led to pin 5
int RECV_PIN = 6;           //Pin of IR sensor
int glow=0;                 //Declaring a variable to detect whether led is turned on/off
IRrecv irrecv(RECV_PIN);    //For led pin
decode_results results;     //Variable foroutput from IR sensor


void setup()
{
  pinMode(led, OUTPUT);     //Set LED pin
  Serial.begin(9600);       //Begin the serial monitor
  irrecv.enableIRIn();      //Begining the IR sensor
}

void loop() {
  if (irrecv.decode(&results))           //If any pushing of buttons detected 
  {
    unsigned int value = results.value;  //A variable to store output from IR sensor
    Serial.println(value);               //Printing the output on serrial monitor

    if(value==255){                      //If Voltage value was detected as 255
      if(glow==0){                       //and LED was off
        digitalWrite(led, HIGH);         //Turn on the LED
        glow=1;                          //And set the variable as 1
      }
      else{                              //And if LED was already on
      digitalWrite(led, LOW);            //Turn it on    
        glow=0;                          //Again set the variable as 0
      }
    }
    
    irrecv.resume();                    //Prepare to receive another input
  }
}