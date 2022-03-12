# Project/Script Name

Safe Lock Circuit Simulation on TinkeCad

## Aim

To make a Safe Lock Circuit Simulation. 

## Purpose

To make a Safe Lock Circuit Simulation. in which we set the password using potentiometer and once its set we will recheck the password using recheck password button if passwrod is correct the safe door will pen as servo motor will turn on and green light will turn on. If it is wrong red led will turn on and buzzer will on and alert the user that password is wrong.

## Components Required

List out the components used in this project are:
* Arduino UNO R3
* Servo Motor
* Breadboard
* Buzzer
* 4 Potentiometer
* RGB LED
* 2 PushButtons
* Tinkercad (if component is not available)


## Short description of package/script

* Serial.println() -- Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n'). This command takes the same forms as Serial.
* Serial.print() -- For printing on serial monitor or we can say sending the data form arduino to your computer.
* delay() -- Pauses the program for the amount of time (in milliseconds) specified as parameter.
* <Servo.h> -- Library for servo motor.
* myServo.attach() -- For intializing the pin attached to signal pin of sevo motor.
* myServo.write() -- Writes a value to the servo, controlling the shaft accordingly. On a standard servo, this will set the angle of the shaft (in degrees), moving the shaft to that orientation.

## Workflow of the Project

* Set the password using 4 potentiometer and press the push button named set password button.
* Set the password recheck using four potentiometer and press the push button named password recheck button.
* If password recheck is matches with set password then Green light will turn on and servo motor rotate by 180 degree.
* If password is not correct then Red light will turn on and buzzer will be beeping.
* You can the see the password and password recheck strings in serial monitor.


## Setup instructions

* Open tinkercad
* Make circuit as shown [here](https://github.com/rk18venom/IoT-Spot/blob/Safe-Lock-Circuit/Arduino/Safe%20Lock%20Cicruit%20Simulation%20on%20TinkerCad/Images/Circuit%20Image.png)
* First try to implement the program by yourself if you not able to do so then you can do this copy the code and paste it on code section.
* Run the simulation and set the password and set the recheck the password if it matches then great servo motor will rotate and if its not the buzzer will beep.
* Open the serial monitor for seeing the set password and password recheck string.

## Compilation Steps

No error during the compilation of program.

## Output

* [Image Link](https://github.com/rk18venom/IoT-Spot/blob/Safe-Lock-Circuit/Arduino/Safe%20Lock%20Cicruit%20Simulation%20on%20TinkerCad/Images/Circuit%20Image.png)
* [Video Link](https://github.com/rk18venom/IoT-Spot/tree/Safe-Lock-Circuit/Arduino/Safe%20Lock%20Cicruit%20Simulation%20on%20TinkerCad/Videos)


## Author(s)

[Rahul Kashyap](https://github.com/rk18venom)
