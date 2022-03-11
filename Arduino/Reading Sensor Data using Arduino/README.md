# Project/Script Name

Reading Sesnor Data Using Arduino

## Aim

Reading the sensor data  of ultrasonic sensor and printing it on serial monitor.

## Purpose

Reading the data of sensor using Arduino and print it on serial monitor or use it for analysing different things.

## Components Required

List out the components used in this project are:
* Arduino UNO R3
* Ultrasonic Sensor
* Breadboard
* Tinkercad (if component is not available)


## Short description of package/script

* pulseIn() -- measures the time period of a high or low pulse input signal generally use for ultrasonic sensor.
* Serial.print() -- For printing on serial monitor or we can say sending the data form arduino to your computer.
* delayMicroseonds() -- Pauses the program for the amount of time (in microseconds) specified as parameter.
* trigPin and echoPin --The ultrasound transmitter (trig pin) emits a high-frequency sound (40 kHz). The sound travels through the air. If it finds an object, it bounces back to the module. The ultrasound receiver (echo pin) receives the reflected sound (echo).

## Workflow of the Project

* Intialize the variable trigPin and echoPin.
* Set the pinMode of trigPin as OUTPUT and echoPin ans INPUT.
* Send the wave through trigPin by giving HIGH voltage.
* delay by 2 microseonds.
* Set trigPin to LOW voltage and read the time period in recieving the wave using echoPin and pulseIn() function.
* Find the distance using formula (speed*time)/2
* Print the distance on serial monitor using Serial.print() function.


## Setup instructions

* Open tinkercad
* Make circuit as shown [here](https://github.com/rk18venom/IoT-Spot/blob/Sesning-Data/Arduino/Reading%20Sensor%20Data%20using%20Arduino/Images/Circuit%20Image.png)
* First try to implement the program by yourself if you not able to do so then you can do this copy the code and paste it on code section.
* Run the simulation and hover on ultrasonic sensor for changing the distance of object.
* Open the serial monitor and see the output.

## Compilation Steps

No error during the compilation of program.

## Output

* [Image Link](https://github.com/rk18venom/IoT-Spot/blob/Sesning-Data/Arduino/Reading%20Sensor%20Data%20using%20Arduino/Images/Circuit%20Simulation.png)
* [Video Link](https://github.com/rk18venom/IoT-Spot/blob/Sesning-Data/Arduino/Reading%20Sensor%20Data%20using%20Arduino/Videos/2022_03_04_201055.mp4)


## Author(s)

[Rahul Kashyap](https://github.com/rk18venom)


