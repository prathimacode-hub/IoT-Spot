# Room Brightness Sensing Using Arduino

## AIM:

To implement continuous scrolling of red,green and blue colors using the RGB LED.

## Purpose:

Continuous Scrolling can be made using RGB LED.

## Short Description:

**Requirements:**

- Arduino UNO
- 1 Photoresistor
- 1 RGB LED
- 2 Resistors
- USB
  (Tinkercad can also be used)

## Workflow:

- We initiate a loop that ensures continuous scrolling.
- We initiate pin 11, 10 and 9 as the output of Red ,Blue and Green terminals respectively.
- We use analogWrite function to give the input value of 255 one at a time to each of these color terminals of the RGB LED.
- We set the values of the other two pins to 0 to show distinct colors - Red,Blue and Green.
- Each color is separated by a very minimal delay of 1 sec.

## Setup instructions:

- Assemble the circuit as shown below.
- Make sure to connect one end of the RGB LED to ground(i.e. GND)
- Upload the code provided [here](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/RGB%20LED%20Scrolling/rgb_led_scrolling.ino)
- Run to see the project in action!

---

## Output:

[Simulation Video](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/RGB%20LED%20Scrolling/Images/rgb_led_scrolling.mp4)
![Tinkercad Circuit](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/RGB%20LED%20Scrolling/Images/rgb_led_scrolling.png)

---

## Author:

[Shreya Ghosh](https://github.com/shreya024)
