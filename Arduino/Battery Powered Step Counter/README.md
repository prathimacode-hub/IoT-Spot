# Battery Powered Step Counter

## AIM:

To count number of steps using battery powered Arduino.

## Purpose:

To implement a Battery Powered Step Counter.

## Short Description:

**Requirements:**

- Arduino UNO
- 1 LCD Display
- 1 Tilt Sensor
- 1 Resistor
- 1 9V Battery(for power source)
  (Tinkercad can also be used)

## Workflow:

- We initiate digital pin 7 as input for the tilt sensor and the LCD Display as output for the steps count value.
- We use a 9V battery as power source for the circuit.
- We initiate a loop.
- We read the value of the tilt sensor using digitalRead that changes as we change the orientation of the tilt sensor.
- We extract the sensorValue and store it in a variable c.
- Variable b has the oldtilt sensor value.This way we can keep a track and count steps only when orientation of tilt sensor changes.
- We keep adding the sensorValue to the olda variable to store it as total steps count in variable a.
- We print the value of a on the lcd display thereby showing the total number of steps.

## Setup instructions:

- Assemble the circuit as shown below.
- Make sure to connect one end of both the breadboard and battery to ground(i.e. GND)
- Upload the code provided [here](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Battery%20Powered%20Step%20Counter/battery_powered_step_counter.ino)
- Run to see the project in action!

---

## Output:

[Simulation Video](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Battery%20Powered%20Step%20Counter/Images/battery_powered_step_counter.mp4)
![Tinkercad Circuit](https://github.com/shreya024/IoT-Spot/blob/main/Arduino/Battery%20Powered%20Step%20Counter/Images/battery_powered_step_counter.png)

---

## Author:

[Shreya Ghosh](https://github.com/shreya024)
