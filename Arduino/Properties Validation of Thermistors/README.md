# Properties Validation of Thermistors Using Arduino

## AIM:

To show validation of properties of thermistors using Arduino.

## Purpose:

To show variation of resistance of the thermistor with respect to temperature.

## Short Description:

**Requirements:**

- Arduino UNO
- 1 LCD Display
- 1 TMP 36 Sensor
- 1 Resistor
- USB
  (Tinkercad can also be used)

## Workflow:

- We initiate analog pin A0 as input for the thermistor and the LCD Display as output for the analog reading value.
- We initiate a loop.
- We read the value of the TMP36 sensor (Thermistor) using analogRead that changes as we change the temperature.
- We extract the value of the resistance from the sensorvalue.
- We observe that with the increase in temperature, resistance decreases.
- Thus, it validates the properties of a thermistor.

## Setup instructions:

- Assemble the circuit as shown below.
- Make sure to connect one end of both the breadboard and sensor to ground(i.e. GND)
- Upload the code provided [here](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Properties%20Validation%20of%20Thermistors/properties_validation_of_thermistors.ino)
- Run to see the project in action!

---

## Output:

[Simulation Video](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Properties%20Validation%20of%20Thermistors/Images/properties_validation_of_thermistors.mp4)
![Tinkercad Circuit](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Properties%20Validation%20of%20Thermistors/Images/properties_validation_of_thermistors.png)

---

## Author:

[Shreya Ghosh](https://github.com/shreya024)
