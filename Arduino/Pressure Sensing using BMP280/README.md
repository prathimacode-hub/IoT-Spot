# Pressure sensing using BMP280

## AIM:

To understand working of BMP280 with Arduino Uno

## Purpose:

We have to analyse pressure , temperature and altitude readings of BMP280 and verify them by blinking an LED after a certain threshold value is reached . In our case it will be a pressure of 1000hPa / 100000Pa as 1hPa = 100Pa.

## Short Description:

**Requirements:**

-   1 Arduino UNO
-   1 LED
-   1 BMP280
-   1 Resistor
-   USB
    (Proteus can also be used)

## Workflow:

-   First we install Adafruit BMP280 and SPI library by opening library manager on Arduino IDE .
-   Then we import the installed libraries
-   We define all the SPI pins
-   We create an object "bmp" to access the functionalities of Adafruit BMP280 library.
-   In setup we initialise BMP280 sensor by stating bmp.begin(0x56)
-   We initialise pinmode output for LED.
-   In void loop we access bmp functions to read pressure , temperature and altitude . Further we make use of a conditional statement checking if pressure read is more than 1000hPa/10000Pa and if so then state digitalWrite as HIGH for LED else it will be LOW.

## Setup instructions:

-   Assemble the circuit as shown below.
-   Make sure to connect one end of LED to ground(i.e. GND)
-   Upload the code provided [here](https://github.com/piyusha2001/IoT-Spot/tree/main/Arduino/Pressure%20Sensing%20using%20BMP280/pressure_sensing_BMP280.ino)
-   Run to see the project in action!

---

## Output:

[Simulation Video](https://github.com/piyusha2001/IoT-Spot/tree/main/Arduino/Pressure%20Sensing%20using%20BMP280/Images/pressure_sensing_using_BMP280.mp4)
![Proteus Circuit](https://github.com/piyusha2001/IoT-Spot/tree/main/Arduino/Pressure%20Sensing%20using%20BMP280/Images/pressure_sensing_using_BMP280.png)

---

## Author:

[Piyusha Patil](https://github.com/piyusha2001)
