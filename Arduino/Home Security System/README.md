# Home Security System


## Aim

To design a Arduino Based Home Security System


## Purpose

What's the purpose of this project


## Components Required

* Arduino UNO
* Breadboard
* Connecting Wires
* LCD 
* Potentiometer
* Keypad
* PIR Sensor
* Servo Motor
* Buzzer
* 1 Red LED
* 1 Green LED
* 4 Resisitors


## Workflow of the Project

- First we setup a default password 
- The servo acts like the lock
- When ths system is not locked the green LED is turned on and a LOCK INACTIVE message is displayed on the LCD Screen
- When the system is locked by giving the default password through the keypad:
  - Servo rotates
  - Secured message is displayed on the LCD
  - When any movement is detected by the PIR Sensor:
    - Red LED is turned on
    - Warning message is displayed on the LCD
    - Buzzer is turned on
- When again the default password is inputed :
  - Servo rotates back to the origial position
  - Lock is disarmed 
  - Message displayed on the LCD screen.


## Setup instructions

- Design and assemble the circuit as shown in the image.
- Check the connections of all the components.
- Upload the code provided [here](https://github.com/rittikadeb/IoT-Spot/blob/main/Arduino/Home%20Security%20System/home_security_system.cpp)
- Start the simulation

## Output

(https://github.com/rittikadeb/IoT-Spot/blob/main/Arduino/Home%20Security%20System/Images/home-security-system.PNG)
[Simulation Video](https://github.com/rittikadeb/IoT-Spot/blob/main/Arduino/Home%20Security%20System/Images/home_security_system.mp4)



## Author(s)

Name(s) of author(s)


## Disclaimers, if any

Use this section to mention if any particular disclaimer is required
