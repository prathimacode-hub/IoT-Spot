# Mood Ring Light using Arduino

## AIM:

Implementing a Mood Ring Light using Arduino.

## Purpose:

To implement a mood ring light with the help of Neopixel and Arduino

## Short Description:

**Requirements:**

- 1 Arduino UNO
- 1 NeoPixel 12 Ring
- 1 Neopixel Jewel
- USB
  (Tinkercad can also be used)

## Workflow:

- We use a Neopixel 12 Ring and a Neopixel Jewel to construct a Mood Ring Light.
- We connect the input, power and GND of the ring to the input, power and GND of the jewel respectively.
- We connect the input of the ring to the digital pin 6.
- The custom function Wheel() detects the wheel position and helps in determining color change.
- The custom function rainbow() displays a series of the color that slowly morphs into the next color.
- The custom function rainbowCycle() displays a multicolor ring that changes color 1 LED strip at a time.
- We initiate the LED strips to begin showing color in the setup().
- In the loop() function the rainbow() and rainbowCycle() functions are each make to run at an interval of 20 secs.
- Thus, we can implement a mood ring light using Neopixel and Arduino.

## Setup instructions:

- Assemble the circuit as shown below.
- Make sure to connect one end of both the Neopixel to ground(i.e. GND)
- Upload the code provided [here](./mood_ring_light_using_arduino.ino)
- Run to see the project in action!

---

## Output:

[Simulation Video](https://github.com/shreya024/IoT-Spot/blob/main/Minor%20Scripts/Arduino/Mood%20Ring%20Light/Images/mood_ring_light_using_arduino.mp4)

![Tinkercad Circuit](./Images/mood_ring_light_using_arduino.png)

---

## Author:

[Shreya Ghosh](https://github.com/shreya024)

