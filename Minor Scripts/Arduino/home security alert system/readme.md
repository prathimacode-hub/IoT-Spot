# Home Security Alert System
## Aim
To provide alert security system which prevent an outsider to barge in your house using Arduino.
## Purpose
By pressing correct password on keyboard, the servomotor(door) will rotote at 90 degrees. And if we press incorrect password, the piezo create noise.
## Components Used
- Aurdinu Uno R3
- keypad
- Piezo Buzzer
- LCD
- servo motor 
- wires

## Short Description 
When we start simulation, the servomotor ratotes in anti-clockwise direction of 90 degrees, that tells, main door of house is locked now. If anyone presses incorrect password, the door will remains locked and the Piezo buzzer on.
Noone, other than who know the correct password, can open the door.

## Workflow of the Project
Arduino takes input from keypad, that is, password of length 4, consist of digits and letters, output display on the LCD. After pressing 4 digits/letters, arduino checks whether it is a correct password or not.
If it is a correct password, then the servomotor rotates at 90 degrees, and door is opened now. It is opened for 5 seconds, the count down will be displayed on LCD. After 5 sec, the servomotor rotates at 90 degrees in anti clockwise
and closes the door. 
If it is incorrect password, then the peizzobuzzer creates noise and in LCD, message appears "Get away".

## Setup Instructions
- Use Tinkercad
- Make the circuit as seen in the images.
- Upload the source code.
- Run
#### Circuit Image
![circuit diagram](https://github.com/ritikalohia/IoT-Spot/blob/main/Minor%20Scripts/Arduino/home%20security%20alert%20system/Images/circuit_diagram.png)
#### [Source Code](https://github.com/ritikalohia/IoT-Spot/blob/main/Minor%20Scripts/Arduino/home%20security%20alert%20system/code.ino)

## Output
#### [Simulation Video](https://github.com/ritikalohia/IoT-Spot/blob/main/Minor%20Scripts/Arduino/home%20security%20alert%20system/Images/simulation-video.mp4)
## Author
[Ritika lohia](github.com/ritikalohia)
