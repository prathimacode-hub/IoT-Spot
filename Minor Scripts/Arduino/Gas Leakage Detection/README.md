# Gas Leakage Detection
## Aim
To detect gas leakage using Arduino.
## Purpose
Detects Gas Level and sounds and alarm when a certain gas level is crossed.
## Components Used
- Aurdinu Uno R3
- MQ2 Gas Sensor
- Piezo Buzzer
- Resistor 1K ohm
- Breadboard

## Short Description 
The project simply uses Arduino Uno R3 that recieves the gas level from a MQ2 gas sensor. When the gas level is above 100 itrns on the buzzer. And as soon as the gas level drops down from 100 it shuts the buzzer off. Components required are already mentioned above and the projects was built on tinkercad. The language used to code the arduino is Embedded C.

## Workflow of the Project
There is one input and one output sensor connected to the arduino. The gas sensor detects the gas level and continuously sends it to the the arduino. Then the in the loop arduino checks if the gas level is above a certain limit, here 100. And if it is above the limit the arduino turns the piezo buzzer on.

## Setup Instructions
- Use Tinkercad
- Make the circuit as seen in the images.
- Upload the source code.
- Run
#### [Circuit Image](https://github.com/san-13/IoT-Spot/blob/main/Minor%20Scripts/Arduino/Gas%20Leakage%20Detection/images/circuit_image.png)
#### [Schematic View](https://github.com/san-13/IoT-Spot/blob/main/Minor%20Scripts/Arduino/Gas%20Leakage%20Detection/images/schematic_view.png)
#### [Source Code](https://github.com/san-13/IoT-Spot/blob/main/Minor%20Scripts/Arduino/Gas%20Leakage%20Detection/source_code.ino)

## Output
#### [Simulation Video](https://github.com/san-13/IoT-Spot/blob/main/Minor%20Scripts/Arduino/Gas%20Leakage%20Detection/images/simulation_video.webm)
## Author
[Sandeep Verma](github.com/san-13)
