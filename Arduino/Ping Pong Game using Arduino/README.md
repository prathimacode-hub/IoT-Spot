# Ping Pong Game using Arduino

## AIM:

To be able to simulate actual ping pong game with the help of a LCD Display and Arduino

## Purpose:

To play with the ping pong game simulation by using push buttons for control, and LED's for better interaction with the game.

## Short Description:

**Requirements:**

- 1 x Arduino UNO board.
- 2 x NeoPixel LEDs.
- 1 x piezoelectric crystal.
- 6 x resistors.
- 5 x pushbuttons.
- 1 x potentiometer.
- 1 x LCD display 16x2.
- 1 x breadboard.

## Workflow:
- We define pinouts for different components used in the project. We define globals which we will be using throughout the program.
- We initialise the components, print welcome message and begin the game.
- We initiate a loop.
- Based on the push button clicks, the game will continue, until either of the player wins.
- For better interaction, buzzer and LED's beep and light up respectively to indicate the player's actions
- Winner and Loser is shown by changing the color of the LED's.
- We initiate analog pin A0 as input for the thermistor and the LCD Display as output for the analog reading value.
## Setup instructions:
- Assemble the circuit as shown below.
- Upload the code provided [here](https://github.com/SarthakSKumar/IoT-Spot/blob/8680f2de66d20703953bb2538c715a2169864f4e/Arduino/Ping%20Pong%20Game%20using%20Arduino/Ping_Pong_Game_Using_Arduino.ino)
- Run to see the project in action!

---

## Output:


---

## Author:

[Sarthak S Kumar](https://github.com/SarthakSKumar)
