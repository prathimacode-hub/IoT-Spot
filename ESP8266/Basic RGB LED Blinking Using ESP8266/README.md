# ESP8266 RGB LED Blinking

This project demonstrates how to blink an RGB LED using an ESP8266 microcontroller. The code is written in Arduino and uses the Adafruit NeoPixel library for controlling the RGB LED.

## Hardware Setup

1. Connect the common cathode of the RGB LED to the ground (GND) pin on the ESP8266.
2. Connect each RGB LED anode (R, G, B) to different GPIO pins on the ESP8266 (e.g., D1, D2, D3).
3. Connect a current-limiting resistor (around 330-470 ohms) in series with each LED anode to limit the current.

## Software (Arduino IDE) Setup

1. Open the Arduino IDE and ensure you have the ESP8266 board support installed.
2. Include the Adafruit NeoPixel library: `Sketch -> Include Library -> Adafruit NeoPixel`.
3. Replace the placeholder values in the code with the actual GPIO pins you used for the Red, Green, and Blue LEDs.
4.Upload the code to your ESP8266.


```cpp
#define PIN_R 1  // Replace with the GPIO pin for the Red LED
#define PIN_G 2  // Replace with the GPIO pin for the Green LED
#define PIN_B 3  // Replace with the GPIO pin for the Blue LED
```

## Code Explanation:

The provided code cycles the RGB LED through red, green, and blue colors with a delay between each color change. You can adjust the speed of color transitions by changing the wait value in the colorWipe function.

```
void loop() {
  // Turn on Red
  colorWipe(strip.Color(255, 0, 0), 50);
  delay(500);

  // Turn on Green
  colorWipe(strip.Color(0, 255, 0), 50);
  delay(500);

  // Turn on Blue
  colorWipe(strip.Color(0, 0, 255), 50);
  delay(500);
}
```