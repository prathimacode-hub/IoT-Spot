# Project/Script Name
Remote Control Car Circuit simulation on Tinkercad

## Aim

To make remote control car circuit simulation in Tinker Cad.


## Purpose

On giving the command from serial monitor F(Forward), B(Backward), L(Left), R(Right) and S(Stop) the car will move in that way.


## Components Required

List out the components used in your project
* Arduio UNO R3
* 2 H Bridge Motor
* Breadboard
* L293D Motor Driver
* Jumper Wires
* USB (TinkerCad if USB not available)

## Workflow of the Project
In motor there are two terminals one is positive and another one is negative.
If one give high voltage to one terminal and one low the roation of motor changes in any clockwise or anticlockwise direction.
For moving Forward Both motor should be move in clockwise direction so we have high the one terminal of each motor and low another terminal of each motor.
Similarly, we have done vice versa of Forward to move it in Backward direction.
For Moving Left one Motor left motor should me move in anticlockwise direction and right one in clockwise direction.
For Moving Right we can do vice versa.
For stopping we have to low both motor.
Now if you give F command from serial monitor both motor will rotate in clockwise.
B command from serial monitor both motor will rotate in anti clockwise.
L command from serial monitor left one motor will rotate in anti clockwise and right one motor will rotate in clockwise.
R command from serial monitor left one motor will rotate in clockwise and right one motor will rotate in anti clockwise.
S command form serial monitor both motor will stop rotating.


## Setup instructions

* Open Tinker Cad on any browser and make the circuit as shown [here](https://github.com/rk18venom/IoT-Spot/blob/RC_car_circuit/Arduino/RC%20car%20circuit/Images/RC_car_circuit_image.png).
* Then paste the code in code section.
* Then give any command from among these (F,B,L,R,S) through serial monitor.
* Start Simulation.

## Screenshort
[Circuit Diagram](https://github.com/rk18venom/IoT-Spot/blob/RC_car_circuit/Arduino/RC%20car%20circuit/Images/RC_car_circuit_image.png)

## Output

[Video Link](https://github.com/rk18venom/IoT-Spot/blob/RC_car_circuit/Arduino/RC%20car%20circuit/Video/2022_03_01_151325.mp4)

## Author(s)

Rahul Kashyap

