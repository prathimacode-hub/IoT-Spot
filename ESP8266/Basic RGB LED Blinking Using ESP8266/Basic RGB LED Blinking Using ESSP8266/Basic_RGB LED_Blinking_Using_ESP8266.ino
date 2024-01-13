#include <Adafruit_NeoPixel.h>

#define PIN_R 1  // Replace with the GPIO pin for the Red LED
#define PIN_G 2  // Replace with the GPIO pin for the Green LED
#define PIN_B 3  // Replace with the GPIO pin for the Blue LED
#define NUM_LEDS 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_R, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  // Turn on Red LED
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  delay(500);

  // Turn on Green LED
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  delay(500);

  // Turn on Blue LED
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  delay(500);
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
