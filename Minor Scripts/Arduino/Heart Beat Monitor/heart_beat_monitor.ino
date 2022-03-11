#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Including PulseSensorPlayground library for pulse sensor functions   

//  Variables
const int PulseWire = 0;      //heartbeat sensor wire connected to analog pin A0
const int LED13 = 13;         //LED light on arduino board at pin 13
int Threshold = 550;          // to determine which signal to be counted as pulse
                               
PulseSensorPlayground pulseSensor;  //creating object for pulseplayground library


void setup() {   

  Serial.begin(9600);       //set serial monitor  

 
  pulseSensor.analogInput(PulseWire);   //taking input
  pulseSensor.blinkOnPulse(LED13);       
  pulseSensor.setThreshold(Threshold);   

  // to check if circuit working properly
   if (pulseSensor.begin()) {
    Serial.println("Pulse sensor started");  
  }
}



void loop() {

 int BPM = pulseSensor.getBeatsPerMinute();   //calling getbeatsperminutes function on pulsesensor object and 
                                                  //assigning this int value to variable called BPM

if (pulseSensor.sawStartOfBeat()) {   //if a beat is detected         
 Serial.print("BPM: ");                        
 Serial.println(BPM);                        //printing BPM on virtual monitor
}

  delay(20);                   

}