# Project/Script Name
Obstacle Avidance Bot Circuit simulation on Tinkercad

## Aim

To make obstacle avoidance bot circuit simulation in Tinker Cad.


## Purpose

Bot will avoid all the obstacle in its path.


## Components Required

List out the components used in your project
* Arduio UNO R3
* 2 H Bridge Motor
* Breadboard
* L293D Motor Driver
* Jumper Wires
* USB (TinkerCad if USB not available)
* Ultrasonic Sensor

## Workflow of the Project
In motor there are two terminals one is positive and another one is negative.
If one give high voltage to one terminal and one low the roation of motor changes in any clockwise or anticlockwise direction.
For moving Forward Both motor should be move in clockwise direction so we have high the one terminal of each motor and low another terminal of each motor.
Similarly, we have done vice versa of Forward to move it in Backward direction.
For Moving Left one Motor left motor should me move in anticlockwise direction and right one in clockwise direction.
For Moving Right we can do vice versa.
For stopping we have to low both motor.
Now there is a ultrasonic sensor which will detect the obstacle it bot path if the distance of obstacle is less than threshold value that is 57 cm in my code
then bot will stop and move backward for 1 sec each after that the bot will move left in this way the bot successfully avoid the obstacle. 
Now as the distance of obstacle is 0 bot will forward until the obstacle is not detected.


## Setup instructions

* Open Tinker Cad on any browser and make the circuit as shown [here](https://github.com/rk18venom/IoT-Spot/blob/RC_car_circuit/Arduino/RC%20car%20circuit/Images/RC_car_circuit_image.png).
* Then paste the code in code section.
* Open the Serial Monitor.
* Start Simulation.

## Compilation Steps
There is not any error on running the code. It will run perfectly fine.

## Screenshort
[Circuit Diagram](https://github.com/rk18venom/IoT-Spot/blob/Obstacle-Avoidance/Arduino/Obstacle%20Avoidance%20Bot%20Circuit/Images/circuit_image.png)

## Output

[Video Link](https://github.com/rk18venom/IoT-Spot/tree/Obstacle-Avoidance/Arduino/Obstacle%20Avoidance%20Bot%20Circuit/Videos)

## Author(s)

[Rahul Kashyap](https://github.com/rk18venom)

