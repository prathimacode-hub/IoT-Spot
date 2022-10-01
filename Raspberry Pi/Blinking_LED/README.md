# LED Blinking using Rasoberry Pi Pico


## Aim

To make an 4 LEDs Blink in sequential order by connecting it to the raspberry pi pico and implementing the code 


## Purpose

Blinking LEDs at particular intervals to create a pattern of Blinking green and red LEDs


## Components Required

1.Raspberry Pi Pico
2.One Red LED
3.Three Green LED
4.Wires


## Description

- For Raspberry Pi Pico we can code it in Embedded C and use its library/ddl files.
- For Other Raspberry Pi we can use Raspbeian OS and code it in Python. 


## Workflow of the Project

In this program we have connected 4 LEDs (1 Red and 3 Green) in adjacent pins.
In the C code we have a setup function where we configure Pins- 10, 11, 12 and 14 as OUTPUT.
In the loop function we first turn on the green LED connected to pin 10 for 0.5 secs adn then switch it off and switch on the next green LED connected to pin 11. After 0.5 secs we switch off this LED and the green LED connected to pin 12 glows for 0.5 secs.
After the green LED is switched off the red LED connected to pin 14 glows for 0.5 secs and then is switched off.
Since this is written inside the loop function it repeats this as long as the code is running and the Raspberry Pi Pico is connected to the power supply and no new code is flashed onto it.


## Setup instructions

First we need to install the Arduino IDE which can be done from the Arduino website, on windows it can be installed easily from the Microsoft Store.
We connect the Raspberry Pi Pico to the computer and in tools->port select the Raspberry Pi Pico's port number.
Next we connect the anode of Red LED to pin 14 of the microcontroller and te cathode to GND pin, similarly connect the 3 Green LED's anode to pin 12, 11 and 10 of the microcontroller and the cathode to GND pin.
On the Arduino IDE write the specified code and flash it onto the microcontroller by compiling and the clicking upload.
This will execute the code and the LEDs will blink in the order Green-Green-Green-Red



## Compilation Steps

Once we install the Arduino IDE it automatically enables the library files required for Embedded C and adds the compiler for the following to the system's path.
We require only to write the necessary C code for the LED Blinking experiment.
After this we click on the compile button in the Arduino IDE for the code to build and then click on the upload button to flash it onto the Raspberry Pi Pico.


## Output



## Author(s)

Yash Kumar
Github- https://github.com/yk3066
Twitter- https://twitter.com/yashkumar3066


## Disclaimers, if any

Use this section to mention if any particular disclaimer is required