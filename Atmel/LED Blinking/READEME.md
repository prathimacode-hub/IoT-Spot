# LED Blinking in Atmega32
## AIM:
To blink an LED with Atmega32.

## Purpose:
An LED turns on and off (blinks) for certain amount of period.

## Short Description:
**Requirements:**
- Microchip studio (IDE)
- Atmega32A
- 1 LED
- An Atmega32 development board
- Atmega32 Programmer
(SimulIDE can be used for simulation if hardware not there)

## Workflow:
- First we declare a port as output port
- We taken a while loop and changed the required bits
- A delay is added so that blinking is visible

## Setup instructions:
- Assemble the circuit as shown in circuit diagram.
- Make sure to connect End of LED to ground.
- Make a gcc executable project in Microchip studio. 
- Upload the code provided [here](https://github.com/prathimacode-hub/IoT-Spot/blob/main/Atmel/LED%20Blinking/led_blinking.c).
- Build the project and upload the generated hex file in simulIDE simulated atmega32.
- Run to see the project in action!
------------
## Output:
[Simulation Video](https://github.com/prathimacode-hub/IoT-Spot/blob/main/Atmel/LED%20Blinking/Gallery/simulation_video.mkv)
![Circuit Diagram](https://github.com/prathimacode-hub/IoT-Spot/blob/main/Atmel/LED%20Blinking/Gallery/circuit_diagram.png)
------------

## Author:
[Asif khan](https://github.com/khanasif786)
