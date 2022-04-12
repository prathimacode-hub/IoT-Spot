# Dino Game using Arduino

## AIM:
To create a dino game using arduino.

## Purpose:

To mimic the chrome dino game using arduino with LCD and Push buttons.

## Short Description:

**Requirements:**

- Arduino Board
- 16x2 LCD
- 1K ohm Resistor
- 2 Pushbuttons
- Some Wires

## Workflow:
- Here we start by including the LCD library and the LCD definition and the bitmap array for the dinosaur character.
- Then we define the character for the tree. The definition for buttons Enter and Select. String for alphabet to write your name.
- Start by initializing the LCD. Then create special characters the dinosaur character and the tree character.
- The main loop function, start by clearing the LCD. Reads from the two push buttons. The pin mode as internal pull up using the internal pull up resistor.
- Then we print the menu and we read the buttons using digital read function. The print score function prints the score on the LCD.
## Setup instructions:

- We connect Arduino UNO to the LCD using 4 Pins of Data and the control Pins R/W, E and RS.
- We connect LCD power pins VCC and GND to Arduino 5V and GND.
- The contrast V0 pin connected to GND.
- The Backlight LED +ve connected to 5v and the -ve connected to GND through 1K ohm Resistor.
- We use pushbuttons to control the game.
- Upload the code provided [here](https://github.com/SarthakSKumar/IoT-Spot/blob/ea08c63f64471f38684518c0bb151cfe8508183c/Arduino/Dino%20Game%20using%20Arduino/Dino_Game_using_arduino.ino)
- Run to see the project in action!

## Output:

![Circuit Diagram](https://github.com/SarthakSKumar/IoT-Spot/blob/4d51545e31fa835f0a11f6db0ffcfe64c35cb90f/Arduino/Dino%20Game%20using%20Arduino/Images/Circuit%20Diagram.jpg)
![Simulation Video](https://github.com/SarthakSKumar/IoT-Spot/blob/8e520f235b068e6b1907ee27458c6ea664d01593/Arduino/Dino%20Game%20using%20Arduino/Images/Dino_Game_Using_Arduino_Simulation.mp4)

## Author:

[Sarthak S Kumar](https://github.com/SarthakSKumar)
