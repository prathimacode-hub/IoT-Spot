# ESP8266 RGB LED Blinking Project


## Aim

The main aim of this project is to demonstrate how to control an RGB LED using an ESP8266 microcontroller.

## Purpose

The purpose of this project is to provide a simple example of RGB LED control with an ESP8266, suitable for educational and learning purposes.


## Components Required

- ESP8266 microcontroller (NodeMCU)
- RGB LED
- Breadboard and jumper wires


## Short description of package/script

This Arduino script controls an RGB LED connected to an ESP8266 microcontroller. It uses the Adafruit NeoPixel library to cycle through red, green, and blue colors with adjustable speed.

- IDE: Arduino IDE
- Library: Adafruit NeoPixel


## Workflow of the Project

1. Initialize the NeoPixel strip.
2. Cycle through red, green, and blue colors with a delay between each color change.
3. Adjust the speed of color transitions by changing the `wait` value in the `colorWipe` function.


## Setup instructions

1. Connect the common cathode of the RGB LED to the ground (GND) pin on the ESP8266.
2. Connect each RGB LED anode (R, G, B) to different GPIO pins on the ESP8266 (e.g., D1, D2, D3).
4. Open the Arduino IDE and ensure ESP8266 board support is installed.
4. Include the Adafruit NeoPixel library.
5. Copy the provided code into the Arduino IDE.
6. Replace placeholder values with actual GPIO pins.
7. Upload the code to the ESP8266.

## Detailed explanation of script

The script uses the Adafruit NeoPixel library to control the RGB LED. The `colorWipe` function fills the LED with a specified color, creating a visual effect.

```
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
```


## Compilation Steps

1. Open Arduino IDE.
2. Set the board to ESP8266.
3. Include the Adafruit NeoPixel library.
4. Copy and paste the code.
5. Replace placeholder values.
6. Upload the code to the ESP8266.

## Disclaimer

Before you start making any connections please disconnect the device from your laptop/workstation so there is no power getting to the device. You should never make any connection changes when the device is powered on.

## Author(s)

[MUKUND SOLANKI](https://github.com/mukundsolanki)
