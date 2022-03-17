# Storing Sensory Data to SD Card

## AIM:

To store sensor readings/data as a file on an SD Card using Arduino

## Purpose:

To be able to access the readings given out by the sensor by storing it as a file on an SD Card using Arduino

## Short Description:

**Requirements:**

- Arduino board
- DHT11 sensor
- SD card
- SD card socket (connector)
- 10K ohm resistor
- 4.7K ohm resistor
- 3 x 3.3K ohm resistor
- 3 x 2.2K ohm resistor
- Breadboard
- Jumper wires/Connectors

## Workflow:

- Import relavant libraries and define objects/references
- We define standard pins for the DHT11 Sensor and setup Serial Communication
- We check for the correct functioning of the SD Card.
- We read the Value from the sensor, and print it out in the serial monitor
- After printing to the serial monitor, we write the same data to a file
- We shall throw an error if the file wasn't available or couldn't be created

## Setup instructions:

- Assemble the circuit as shown below.
- the sd card module is supplied with 5V which comes from the Arduino board. The SD card module has 6 pins which are from left to right: GND, VCC, MISO, MOSI, SCK and CS [here]()
- Run to see the project in action!

## Output:

[Simulation Video]()
[Circuit Diagram](## Output:

[Simulation Video]()
[Circuit Diagram](https://github.com/SarthakSKumar/IoT-Spot/blob/main/Arduino/Storing%20Sensory%20Data%20to%20SD%20Card/Images/Circuit%20Diagram.png)
)

---

## Author:

[Sarthak S Kumar](https://github.com/SarthakSKumar)
