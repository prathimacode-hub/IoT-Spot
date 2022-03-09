# Home Automation


## Aim

To design a Arduino Based Home Automation System


## Purpose

This projects deals with the working of home automation.


## Components Required

* Arduino UNO
* Breadboard
* Connecting Wires
* LCD 
* Potentiometer
* DC Motors
* Bulbs
* Relays
* Photoresistor
* Temperature Sensor
* Power Supply
* 2 Resisitors

## Short Description 

In this project, we are using PIR Motion Sensor Module as an infraredsensor that generates electric charge when exposed in heat and sends a signal to Arduino. Accordingly the Arduino displays the status on LCD screen and start buzzing the buzzer and glows the LEDs.

## Workflow of the Project

- The DC motors acts like the fans. 
- The values of the temperature sensor and photoresistor are read by the Arduino
  - If the temperature is high and light is more
    - Bulbs are turned off
    - Fans are turned on
  - If the temperature is low and light is more
    - Bulbs are turned off
    - Fans are turned off
  - If the temperature is high and light is less
    - Bulbs are turned on
    - Fans are turned on
  - If the temperature is low and light is less
    - Bulbs are turned on
    - Fans are turned off 
- All messages are displayed on the LCD screen along with the current temperature.


## Setup instructions

- Design and assemble the circuit as shown in the image.
- Check the connections of all the components.
- Upload the code provided [here](https://github.com/rittikadeb/IoT-Spot/blob/main/Minor%20Scripts/Arduino/Home%20Automation/home_automation.cpp)
- Start the simulation

## Output

![Circuit](https://github.com/rittikadeb/IoT-Spot/blob/main/Minor%20Scripts/Arduino/Home%20Automation/Images/home_automation.JPG)


[Simulation Video](https://github.com/rittikadeb/IoT-Spot/blob/main/Minor%20Scripts/Arduino/Home%20Automation/Images/home_automation.mp4)



## Author(s)

[Rittika Deb](https://github.com/rittikadeb)


