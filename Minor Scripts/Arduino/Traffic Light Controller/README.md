# Project/Script Name


## Aim

This project is a simple the traffic light controller for three way using Arduino. Traffic lights allow everyone to cross the intersection point one by one, reducing conflicts between vehicles entering intersection points from different directions. 


## Purpose

We use three set of traffic light which are placed on respective three paths. Our purpose is to allow vehicles from one path and keep the others stop at a time. 


## Components Required

Arduino Uno(R3)
Breadboard
LEDs ( Red(3), Yellow(3), Green(3))
Resistor( 220 Ohm)(3)
Wires


## Short description of package/script

- In the project, we have exhibited traffic lights for a three-way road. The LEDs will be glowing in a particular sequence to form an actual traffic light controller system.


## Workflow of the Project

- In the void setup of the code, we have defined the pins for the LEDs as outputs from 2 to 10. In the void loop section, we have defined the functions to turn LEDs ON and OFF into the sequence.
- At a time, 2 RED and 1 YELLOW for a second. Then YELLOW turns into GREEN for 5 second. This happens with another both sets of traffic light. It performs in a loop.


## Setup instructions

- Connect LEDs on the breadboard as Red, Yellow, Green, respectively.
- Connect the negative terminal of the LED and connect the 220 Ohm resistor in series.
- Connect these negative terminals to the ground.
- Connect the positive terminal of the LEDs to the pins 2 to 10, respectively.
- Power the breadboard by using 5V and GND on the Arduino.
- Upload the code provided in this link.



## Detailed explanation of script, if needed

If code is not explainable using comments, use this sections to explain your script


## Compilation Steps

- After uploading the code, run simulation and observe the LEDs.


## Output

Display images/videos of output/result and simulations of your script here in README so that users can visualize it
Direct up the links here and add them up in "Images" folder.


## Author

Ritika lohia


## Disclaimers, if any

Use this section to mention if any particular disclaimer is required
