# Properties Validation of Thermistors Using Arduino

## AIM:

To implement sensing the room brightness using photoresistor and Arduino.

## Purpose:

To sense the room brightness using photoresistor and Arduino.

## Short Description:

**Requirements:**

- Arduino UNO
- 1 LCD Display
- 1 TMP 36 Sensor
- 1 Resistor
- USB
  (Tinkercad can also be used)

## Workflow:

- We initiate analog pin A0 as input for the photoresistor and the default pin 13 as output for the LED.
- We initiate a loop.
- We read the value of the light sensor using analogRead that changes as we change the brightness of the light.
- We set the sensorvalue as a delay timer in between the HIGH and LOW states of the LED.
- This ensures when the room is dark,the LED blinks rapidly and the speed of blinking decreases with increase in brightness.

## Setup instructions:

- Assemble the circuit as shown below.
- Make sure to connect one end of the RGB LED to ground(i.e. GND)
- Upload the code provided [here](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Properties%20Validation%20of%20Thermistors/properties_validation_of_thermistors.ino)
- Run to see the project in action!

---

## Output:

[Simulation Video](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Properties%20Validation%20of%20Thermistors/Images/properties_validation_of_thermistors.mp4)
![Tinkercad Circuit](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Properties%20Validation%20of%20Thermistors/Images/properties_validation_of_thermistors.png)

---

## Author:

[Shreya Ghosh](https://github.com/shreya024)
