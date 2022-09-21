# Controlling Servo using ESP32 and Potentiometer

Today we’ll see a few ways of interfacing servo motors to the ESP32 microcontroller and controlling them with code, with a potentiometer, and over WiFi.

## [Simulation Link](https://wokwi.com/projects/342489008903815762)

## [Video Link](https://youtu.be/zxBC1ivOVfM)

## Introduction

We have already looked at both the [ESP32 microcontroller](https://dronebotworkshop.com/esp32-intro/) and at [using analog servo motors](https://dronebotworkshop.com/servo-motors-with-arduino/), and today we’ll put both of them together. We’ll see how to interface and control servo motors with the ESP32 and we’ll take advantage of the microcontrollers’ WiFi capabilities to control a servo with a web-based interface.

As you’ll soon see, controlling a servo motor with the ESP32 is quite similar to using an Arduino, with the added advantage of the ESP32’s wealth of ports and capabilities.

## Servos & ESP32

Controlling an analog servo motor, which is the type of servo motors most commonly used by hobbyists, is a task that most microcontrollers have no problem performing. Arduino’s, for example, have no problem controlling servos and the Arduino IDE even comes with a built-in servo motor library and a few bits of sample code to get you started.

So why use an ESP32, especially as most Arduino’s are less expensive? Depending upon your application there may be no reason, or there may be several. Here are a few:

-   The ESP32 has a wealth of I/O ports, more than most Arduino’s.
-   The ESP32 has analog outputs as well as analog inputs.
-   There are built-in sensors in the ESP32, including a hall-effect sensor.
-   The ESP32 has I/O pins that can be used as touch switches
-   It has a lot of PWM output pins, so it can drive several servo motors.
-   It has built-in WiFi and Bluetooth capabilities.

The latter reason is why many people choose the ESP32 over an Arduino for controlling servo motors. Built-in WiFi and Bluetooth open the door to all sorts of remote control possibilities.

### Servo Motors

Servo motors are geared DC motors that have an integrated servomechanism with a feedback loop to allow precise positioning of the motor shaft. A high gear ratio allows a small servo to have an impressive torque rating.

Most servos are limited in rotation to either 180 or 270 degrees, with 180-degree servo motors being more common. There are specially modified servo motors that can rotate beyond 360-degrees, but we won’t be working with those today.

Servo motors come in a wide range of sizes and can be controlled either with an analog PWM signal or with a digital I/O signal. The inexpensive servos we use for hobbyist applications are usually analog servo motors, which are the types we will be using today.

A very common and inexpensive servo motor is the SG90. It’s a small plastic-gear servo that has become a standard for experimenting and is also used in a lot of RC hobby applications. It has a “cousin”, the MG90, which has similar specifications but uses metal gears.

The SG90, like most servo motors, can be powered from 5-6 volts, so servo motors are great for battery-powered applications.

### Servo Motor Connections

Most analog servo motors like the SG90 use a 3-wire color-coded cable for interfacing. Although the color-coding is not an official standard many manufacturers use the same colored wires:

-   **Orange**  – The PWM servo control input. This is a logic-level signal, and most servo motors can accept 3.3-volt logic as well as 5-volt logic. Some models, especially 270-degree rotation servos, use a White wire for this connection.
-   **Red** – The servo motor power supply input. Generally 5-6 volts DC, but be sure to check first.
-   **Brown** – The ground connection. On some servo motors, this is a Black wire.

Most servo motor cables terminate in a 3-pin Dupont female connector. You can use jumper wires to connect this to a solderless breadboard.

### Servo Positioning

Analog servo motors use PWM, or Pulse Width Modulation, to control the motor shaft position.

The PWM signal is usually about 50Hz, which is a period of 20ms. Within that period the pulse width is varied, a shorter pulse positions the servo towards the zero-degree mark while a longer one moves the motor shaft towards the 180 (or 270) degree position.

The pulse is continually applied to the control lead on the motor, locking the shaft into the desired position.


### ESP32 PWM

Most microcontrollers can be used to generate PWM signals and the ESP32 is certainly no exception. In fact, the ESP32 has the capability of controlling 16 PWM outputs independently.

One thing to note about the ESP32, however, is that many of the GPIO pins have multiple functions. So when selecting a PWM pin to use with your servo motor you’ll want to be sure that you don’t need one of the pins other functions in your design.

Even with that slight restriction, there are still several PWM pins available to drive servo motors, LEDs, and many other devices.

## ESP32Servo Library

The Arduino IDE comes with a built-in servo motor control library, which is appropriately named “Servo”. Unfortunately, it won’t work with the ESP32.

There are many servo motor control libraries available for the ESP32, many of which emulate the Arduino Servo library while adding new functionality.

I’ve chosen to use the [_ESP32Servo_ Library by Kevin Harrington](https://github.com/madhephaestus/ESP32Servo). This library duplicates the functionality of the original Arduino Servo library while adding a few extra features of its own.

### IDE Setup

In order to work with ESP32 boards in the Arduino IDE, you are going to need to add a new Board Manager into the IDE. You’ll then use that new Board Manager to import the ESP32 boards and software examples.

You’ll need to open the _Preferences_ box, which you’ll find under the File menu item, and then add the following location to the “_Additional Boards Manager URLs_” box:

[https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)

After doing that and restarting the IDE you can go into the _Boards Manager_, which you’ll find under the _Tools/Board_s menu item, and search for ESP32. You should see an entry for “_esp32 by Espressif Systems_”. Highlight this entry and click on the Install button.

For more detailed instructions see my [ESP32 introductory article](https://dronebotworkshop.com/esp32-intro/).

### Library Installation

You can install the _ESP32Servo_ Library directly from within your Arduino IDE using the Library Manager.

Open the Library Manager, which you’ll find under the _Sketch/Include Library/Manage Libraries_ menu item.

Type “ESP32Servo” into the search box. From the displayed libraries select the _ESP32Servo_ library, when you do the OK button will appear. Click that button to install the library.

Once the library is installed open your _File/Examples_ menu and scroll down to the section for ESP32Servo. You’ll see a number of examples, some with familiar names. The ones that look familiar are modified versions of the example sketches from the Arduino Servo Library.

We are going to test out a couple of those sketches right now, but before we do we’ll need to get our ESP32 and servo motor all hooked up.

### ESP32 Servo Hookup

For our first two experiments you’ll need the following parts:

-   **An ESP32 WROOM based module.** You don’t need to use the same module I used, just make sure you have a pinout diagram of your module handy so that you can wire to the correct pins.
-   **A Servo Motor.** I used an SG90, but any small analog servo motor will work. You can fine-tune the servo position in the code for just about any servo motor.
-   **A Potentiometer.** I used a 10k linear pot, but any value from 5k upwards should work. Just make sure it is a linear-taper pot, i.e. it is at half-value when the shaft is turned to the halfway point.
-   **A Servo Power Supply**. I always advocate powering motors with a power supply independent of the microcontroller. The servos usually need 5-6 volts. A 4-cell AA or AAA battery pack makes a great power supply for a servo motor.

For our experiments, you can just power the ESP32 using the USB connection to your computer. To run the circuit away from the computer you can use it’s 5-volt or 3.3-volt power pins to power it independently.

Here is the hookup, if your module has a different pinout then just make sure to use GPIO pin 18 for the PWM output. If you would like to use a different PWM-capable pin you’ll need to change the code to match.



For my tests, I elected to use a breadboard power supply to supply the motor voltage with 5-volts. You can also use a 6-volt battery or other suitable supply to power the motor.

Make sure you use 3.3-volts on the connection to the potentiometer and not 5-volts.



Once you have it all wired up connect it to your computer with the USB cable.

