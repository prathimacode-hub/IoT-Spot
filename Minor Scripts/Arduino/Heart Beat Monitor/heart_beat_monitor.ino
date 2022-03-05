#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>        

//  Variables
const int PulseWire = 0;      
const int LED13 = 13;         
int Threshold = 550;          
                               
PulseSensorPlayground pulseSensor;  


void setup() {   

  Serial.begin(9600);         

 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       
  pulseSensor.setThreshold(Threshold);   

   if (pulseSensor.begin()) {
    Serial.println("Pulse sensor started");  
  }
}



void loop() {

 int BPM = pulseSensor.getBeatsPerMinute();  

if (pulseSensor.sawStartOfBeat()) {            
 Serial.print("BPM: ");                        
 Serial.println(BPM);                        
}

  delay(20);                   

}