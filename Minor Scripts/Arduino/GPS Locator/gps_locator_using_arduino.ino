// Code for Arduino 1
// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

//neopixel setup
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 7

#define NUMPIXELS 12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//location of gpsUnit
int gpsSender = 219;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
  Wire.begin();
  Serial.begin(9600);
  pixels.begin();
}

String cardinal(int temp){
  if (temp == 0) return "North";
  else if (temp == 1) return "Northeast";
  else if (temp == 2) return "East";
  else if (temp == 3) return "Southeast";
  else if (temp == 4) return "South";
  else if (temp == 5) return "Southwest";
  else if (temp == 6) return "West";
  else if (temp == 7) return "Northwest";
  else if (temp == 8) return "Found";
  else return "Searching...";
} 

void showDirection(int num){
  pixels.clear();
  
  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  if (num == 0){
    pixels.setPixelColor(0, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.setPixelColor(1, pixels.Color(0,150,0));
  }
  else if (num == 1){
    pixels.setPixelColor(2, pixels.Color(0,150,0)); // Moderately bright green color.
  }                       
  else if (num == 2){
    pixels.setPixelColor(3, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.setPixelColor(4, pixels.Color(0,150,0));
  }
  else if (num == 3){
    pixels.setPixelColor(5, pixels.Color(0,150,0)); // Moderately bright green color.
  }
    else if (num == 4){
    pixels.setPixelColor(6, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.setPixelColor(7, pixels.Color(0,150,0));
  }
  else if (num == 5){
    pixels.setPixelColor(8, pixels.Color(0,150,0)); // Moderately bright green color.
  }
    else if (num == 6){
    pixels.setPixelColor(9, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.setPixelColor(10, pixels.Color(0,150,0));
  }
  else if (num == 7){
    pixels.setPixelColor(11, pixels.Color(0,150,0)); // Moderately bright green color.
  }
  else {
     pixels.setPixelColor(2, pixels.Color(0,0,255)); // Moderately bright green color.
     pixels.setPixelColor(5, pixels.Color(0,0,255));
     pixels.setPixelColor(8, pixels.Color(0,0,255)); // Moderately bright green color.
     pixels.setPixelColor(11, pixels.Color(0,0,255));
   }                     
   pixels.show(); // This sends the updated pixel color to the hardware.
}
  

void loop() {
  lcd.clear();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // delay a bit
  delay(50);
  Wire.requestFrom(gpsSender, 1);
  
  while(Wire.available()) {
    int location = Wire.read();
    Serial.println(location);
    lcd.print(location);
    lcd.setCursor(0,1);
//convert to text and print results
    String direction = cardinal(location);
    Serial.println(direction);
    lcd.print(direction);
//illuminate neopixel
    showDirection(location);
    
  }
  
  delay(1000);
}
 


//Code for Arduino 2
//gpsUnit

#include<Wire.h>

int getDirection(){
  int x = random(9);
  return x;  
}

String cardinal(int temp){
  if (temp == 0) return "North";
  if (temp == 1) return "Northeast";
  if (temp == 2) return "East";
  if (temp == 3) return "Southeast";
  if (temp == 4) return "South";
  if (temp == 5) return "Southwest";
  if (temp == 6) return "West";
  if (temp == 7) return "Northwest";
  if (temp == 8) return "Found";
  else return "Searching...";
}  

void generateLocation(){
  //create variables
  int gps = getDirection();
  //Send to Master
  Wire.write(gps);
}  

void setup(){
  Wire.begin(219);
  Wire.onRequest(generateLocation);
}

void loop(){
}
