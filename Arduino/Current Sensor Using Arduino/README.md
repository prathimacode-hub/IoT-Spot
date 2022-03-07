# Current Sensing Using Arduino
## Aim
To Measure the current using current sensor
## Purpose
To measure current.
The ASC712 is based on Hall Effect. There is a copper strip connecting the IP+ and IP- pins internally. When some current flows through this copper conductor, a magnetic field is generated which is sensed by the Hall Effect sensor. 
## Components Used
- ACS712 ELC-30 Current Sensor
- DC motor
- Battery
- LCD 16*2
- Arduino Board
- Potentiometer
- wires
## Short Description 
When simulation is started, Current sensor produces analog voltage proportional to dc current (as a dc motor is used)
and we calculate the current being produced

## Workflow of the Project
- First, we assume that the VCC is at 5V  when there is no current flowing through the IP+ and IP- terminals of the sensor. So, the voltage at VIOUT of sensor will be 2.5V.
- This means that we need to subtract 2.5V from the voltage measured at the analog pin to avoid errors.
- We have used battery of 12 V which provides power to dc motor.
- When the simulation is started, sensor reads analog voltage proportional to dc current and stores it into a variable.
- The actual voltage and will be calculated by given formula and current will be displayed on screen.
## Setup Instructions
- Download Proteus software.
- build the circuit as shown in diagram
- Download Arduino IDE
- use the code attached.
- run the code
- A .hex file will be generated in the terminal.
- Upload it on Arduino board in Program file section
- Start simulation

## OUTPUT
[Simulation Video]: https://github.com/vaishnavighiradkar/heartbeatSensor/blob/main/156584570-8ffe7872-bc2a-4154-8f7b-676eb32fc75c.zip          

(click on view raw)

[Circuit Image]:https://github.com/vaishnavighiradkar/heartbeatSensor/blob/main/Screenshot%20(168).png

[Source code]: https://github.com/vaishnavighiradkar/heartbeatSensor/blob/main/heartBeatSensorCode


## author
Vaishnavi Ghiradkar
(https://github.com/vaishnavighiradkar)