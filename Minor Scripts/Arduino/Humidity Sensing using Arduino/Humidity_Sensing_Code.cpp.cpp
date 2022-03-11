//Including Libraries
// include the library code:
#include <LiquidCrystal.h>
//include the adafruit library
#include <Adafruit_NeoPixel.h>
//include the serial library
#include <SoftwareSerial.h>

//defining neopixel pin
#define PIN 7 
// input pin for Potentiometer
#define SENSOR A0
// number of neopixels in strip
#define NUMPIXELS 1


//Parameters set to define wetness and dryness
// below this value, begin alerting dry, turn red
#define dryThreshold 50    
// above this value, begin alerting wet, turn blue
#define wetThreshold 200 
// brightest green point
#define thresholdCenter (dryThreshold + wetThreshold)/2  
// how much blue and red should fade in to green
#define crossFade 20       

//creating object to set parameters
Adafruit_NeoPixel pixels = Adafruit_NeoPixel (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Initialising colors
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

//Initialising values
int sensorValue = 0;
int transitionValue = 0;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialise the NeoPixel library
  pixels.begin();
  //Taking input 
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 0
  lcd.setCursor(3, 0);
  lcd.print("IoT-Spot");
  // set the cursor to column 2, line 1
  lcd.setCursor(0, 1);
  lcd.print("Humidity-Sensing");
  
  sensorValue = analogRead(SENSOR);//Taking analog value 
  	transitionValue = map(sensorValue, 0, 1023, 0, 255);//mapping values as per requirement
  	setColor();
	// pixels.Color takes RGB value, from 0,0,0 up to 255, 255, 255
  	pixels.setPixelColor(0, redColor, greenColor, blueColor);
  
    //sending the updated pixel color to the hardware
  	pixels.show();
  //Applying conditions and displaying in serial port
  if((transitionValue >= 0)&(transitionValue < 50)){
  Serial.print("DRY");
  Serial.print("\n");
  }
  if((transitionValue >= 50)&(transitionValue < 200)){
  
    if(transitionValue == 125){
    Serial.print("Moderate");
  Serial.print("\n");
    }
    else{
    Serial.print("WET");
  Serial.print("\n");
    }
  }
  
    // delay for a period of time (in milliseconds)
  	delay(1000);
}

//Creating a function to setup colors
void setColor(){
	// red value greater towards higher resistance/drier
  	redColor = ((transitionValue <= dryThreshold + crossFade) && (transitionValue >= 0 )) ? map(transitionValue, 0, dryThreshold + crossFade, 255, 0) : 0;

   	// blue value greater towards lower resistance/wetter
  	blueColor = ((transitionValue >= wetThreshold - crossFade) && (transitionValue <= 255)) ? map(transitionValue, wetThreshold - crossFade, 255, 0, 255) : 0;

	// green value towards middle resistance
    if(transitionValue >= dryThreshold && transitionValue <= thresholdCenter) {
  		greenColor = map(transitionValue, dryThreshold, thresholdCenter, 0, 255);

    } 
    else if(transitionValue > thresholdCenter && transitionValue < wetThreshold){
    	greenColor = map(transitionValue, dryThreshold, thresholdCenter, 255, 0);
  
    }
    else {
    	greenColor = 0;
    }
}
 