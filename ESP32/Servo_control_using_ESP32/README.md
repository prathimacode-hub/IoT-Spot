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

![Circuit Connections](./Images/circuit_diagram.png)

### Example 1 – Sweep

The two examples we are going to look at are both updated versions of classic Arduino sketches. You won’t need to write any code, as these example sketches were included when you installed the _ESP32Servo_ library.

```c
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo

// 16 servo objects can be created on the ESP32

int  pos  =  0;  // variable to store the servo position

// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33

int  servoPin  =  13;

void  setup()  {

// Allow allocation of all timers

ESP32PWM::allocateTimer(0);

ESP32PWM::allocateTimer(1);

ESP32PWM::allocateTimer(2);

ESP32PWM::allocateTimer(3);

myservo.setPeriodHertz(50);  // standard 50 hz servo

myservo.attach(servoPin,  500,  2400);  // attaches the servo on pin 18 to the servo object

// using default min/max of 1000us and 2000us

// different servos may require different min/max settings

// for an accurate 0 to 180 sweep

}

void  loop()  {

for  (pos  =  0;  pos  <=  180;  pos  +=  1)  {  // goes from 0 degrees to 180 degrees

// in steps of 1 degree

myservo.write(pos);  // tell servo to go to position in variable 'pos'

delay(15);  // waits 15ms for the servo to reach the position

}

for  (pos  =  180;  pos  >=  0;  pos  -=  1)  {  // goes from 180 degrees to 0 degrees

myservo.write(pos);  // tell servo to go to position in variable 'pos'

delay(15);  // waits 15ms for the servo to reach the position

}

}
```
The function of the Sweep sketch is pretty simple, it sweeps the servo motor shaft from zero to 180 degrees and then back to zero. It repeats this as long as it is powered up.

The only modifications made to the Sweep sketch from the original are the changes necessary to use the _ESP32Servo_ library instead of the Arduino _Servo_ library.

After including the _ESP32Servo_ library we define an object called  _“myservo_” to represent the servo motor. We also define the GPIO pin that the control input for the servo is connected to.

In the setup you will note the timer allocation statements, something you will need to do when using the _ESP32Servo_ library.

We then define the frequency that we will be using to drive the servo control. 50Hz is pretty standard, but you can play with this value to improve servo performance.

Then we attach our servo object to the servo motor. You’ll notice three parameters here:

-   The servo GPIO pin number.
-   The minimum pulse width, which should drive the servo to the zero position.
-   The maximum pulse width, which should drive the servo to its maximum position, typically 180 degrees.

The loop is very simple and consists of two for-loop counters. One counts from 0 to 180 and steps the servo in one direction, the other steps it in reverse back to the zero point. We then repeat everything.

Hook everything up, load up the code and take a look at it working. You should see the servo sweep back and forth.



When I did this it worked, but not very well. My servo motor did indeed sweep, but it wasn’t a full 180-degrees. More like about half that.

The way to fix this is to modify the sketch and change the values for the minimum and maximum time. Every servo is different so you can experiment to find the best fit for your motor. For the SG90 I was using the values of 500 and 2400 seemed to work.

### Example 2 – Knob

Knob is another “classic” Arduino sketch, it’s entire purpose is to allow you to position a servo motor using a potentiometer. If that was ALL you wanted to do then using a microcontroller is a bit of an overkill, but of course, this is just a demonstration!

As with the _Sweep_ sketch _Knob_ has been modified to support the _ESP32Servo_ library instead of the original Arduino library. It has also been adjusted to account for the increased resolution of the ESP32’s analog to digital converters (ADC) over the Arduino’s.

```c
// Include the ESP32 Arduino Servo Library instead of the original Arduino Servo Library

#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo

// Possible PWM GPIO pins on the ESP32: 0(used by on-board button),2,4,5(used by on-board LED),12-19,21-23,25-27,32-33

int  servoPin  =  18;  // GPIO pin used to connect the servo control (digital out)

// Possible ADC pins on the ESP32: 0,2,4,12-15,32-39; 34-39 are recommended for analog input

int  potPin  =  34;  // GPIO pin used to connect the potentiometer (analog in)

int  ADC_Max  =  4096;  // This is the default ADC max value on the ESP32 (12 bit ADC width);

// this width can be set (in low-level oode) from 9-12 bits, for a

// a range of max values of 512-4096

int  val;  // variable to read the value from the analog pin

void  setup()

{

// Allow allocation of all timers

ESP32PWM::allocateTimer(0);

ESP32PWM::allocateTimer(1);

ESP32PWM::allocateTimer(2);

ESP32PWM::allocateTimer(3);

myservo.setPeriodHertz(50);// Standard 50hz servo

myservo.attach(servoPin,  500,  2400);  // attaches the servo on pin 18 to the servo object

// using SG90 servo min/max of 500us and 2400us

// for MG995 large servo, use 1000us and 2000us,

// which are the defaults, so this line could be

// "myservo.attach(servoPin);"

}

void  loop()  {

val  =  analogRead(potPin);  // read the value of the potentiometer (value between 0 and 1023)

val  =  map(val,  0,  ADC_Max,  0,  180);  // scale it to use it with the servo (value between 0 and 180)

myservo.write(val);  // set the servo position according to the scaled value

delay(200);  // wait for the servo to get there

}
```

The servo motor object is created and attached exactly as it was in the previous sketch.

Note the value of 4096 for _ADC_Max_, it represents the maximum value for the analog to digital converter. By default, the ESP32 uses a 12-bit A/D converter.

In the loop, all we do is read the potentiometer position by obtaining a value from the A/D converter. This is mapped to a range of 0-180.

We then use this value to write to the servo object, which moves the servo motor to the desired position.

Run the sketch and twist the potentiometer. You should observe the servo motor moving when you move the potentiometer.


# Controlling Servo using Web server on ESP32

## [Video demonstration](https://youtu.be/ijbJ6VeHzgk)

This tutorial is regarding controlling servo motor with ESP32 over a web server using Arduino IDE. You will discover how to control the  **Servo motor with ESP32**  and you will also ready to make a simple web server with a slider to control the position of the servo motor in both positions. Web server consists of a slider with a position from 0-180. With this slider, a user can control the shaft position. We use the Arduino IDE to program the ESP32 dev kit module.



## **Prerequisites**

To follow the concepts of this tutorial, you should have the background knowledge required to grasp concepts.

-   First, you should know have an introduction of ESP32 boards, we are using ESP32 dev kit in this tutorial, so can read: **[Introduction to ESP32 development board](https://microcontrollerslab.com/esp32-development-board/)**
-   You should also have an idea of GPIO pins of ESP32, you read this:  [**How to use GPIO pins of ESP32 devkit**](https://microcontrollerslab.com/esp32-pinout-use-gpio-pins/)
-   As mentioned ahead, we are using Arduino IDE to program ESP32, you can read about how to  [**install ESP32 in Arduino IDE and How to program ESP32**](https://microcontrollerslab.com/install-esp32-arduino-ide/).

## Components Required

We will be using these components for this tutorial:

-   ESP32 DOIT DEVKIT Development board
-   Few jumper wires
-   Servo motor ( you can use any sort of servo motor within the current limit of ESP32)

## Interfacing Servo Motor With ESP32

In this section, We will review about basics of servo motor, types of servo motors, pinout, and connection layout of servo motor interfacing with ESP32. In order to understand, interfacing circuit, you first need to understand its working. Let’s start with the basics.

The Servo motor is controlled by giving a  **series of pulses to control the pin**. Almost all servos used for hobbyist projects work on the  **50Hz frequency**  or the time period of the control signal should be 20ms. Control signal width defines the position of a shaft that how much it will rotate. Pulse width and  **position of the shaft**  are directly proportional to each other. They can rotate from 0 to 180 degrees depending on pulse width. You can go through the following tutorial to know more about PWM and its related terms:


The picture shown below provides more details about it.

[![ESP32 servo motor position](https://microcontrollerslab.com/wp-content/uploads/2019/04/ESP32-servo-motor-position.png)](https://microcontrollerslab.com/wp-content/uploads/2019/04/ESP32-servo-motor-position.png)

ESP32 servo motor position source  [link](https://howtomechatronics.com/how-it-works/how-servo-motors-work-how-to-control-servos-using-arduino/)

You don’t need to worry about working and how to generate this control signal. Because we will use  **Servo library for ESP32**  to provide a control signal. In the next section, We will show you how to add  **Servo library for ESP32**.

## Pinout

[![Servo motor pinout esp32](https://microcontrollerslab.com/wp-content/uploads/2019/04/Servo-motor-pinout-esp32.png)](https://microcontrollerslab.com/wp-content/uploads/2019/04/Servo-motor-pinout-esp32.png)

Servo motor consists of three pins:

-   Power pin is of red color.
-   Ground pin is of brown color.
-   Control signal usually has an orange, yellow and white color.


Before connecting it with ESP32, we need to make sure how much current is required to operate. For example, different power servo motors are available in market. When you are using small power servo motor like S0009, you can directly connect it with an ESP32 board. Because its current requirement is less than 10ms. We will use S0009 in this tutorial as shown above. You can also connect SG90, SG92R series directly with board. But if you want to use high power servo motor with ESP32, you need to use motor driver IC like  [UNL2003](https://microcontrollerslab.com/relay-driver-circuit-using-uln2003/)  between these two. Also if you want to use  **multiple Servos**  with ESP32, you still have to use current driver IC.

## Connection diagram

[![ESP32 servo motor control with web server in Arduino IDE](https://microcontrollerslab.com/wp-content/uploads/2019/04/ESP32-servo-motor-control-with-web-server-in-Arduino-IDE.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/04/ESP32-servo-motor-control-with-web-server-in-Arduino-IDE.jpg)

Very simple connection layout is given here.

Above schematic use ESP32 DOIT DEVKIT 30 pin version. But if you are using 36 pin version or any other ESP32 board, you should check its pinout and find GPIO pin 13.

Now, You just make a connection according to this layout on a breadboard. To  **connect a single servo with ESP32**, we will connect according to these connections:

-   Connect  **Ground Pin**  of servo with Ground pin of ESP32
-   **Power pin**  >> Vin Pin
-   **Control Signal pin**  >> GPIO 13 of ESP32

you can use any pin of ESP32 as PWM pin because we need to provide PWM signal to control signal pin of servo. In this tutorial, we are using GPIO pin 13 as PWM pin as shown in layout. But you can also use any pin for control signal. But you need to specify the GPIO pin number inside the code which we will discuss in programming section of this guide.

## Install Servo Library for ESP32

As mentioned in the last two sections, servo’s are controlled through a series of pulses with variable pulse width. But instead of creating its own code that how to create a series of pulses with variable pulse width, we can use  [ESP32 servo library](https://github.com/RoboticsBrno/ESP32-Arduino-Servo-Library). Follow these steps to download and install the library.

-   Follow this link to get  [ESP32 Servo library for Arduino IDE](https://github.com/RoboticsBrno/ESP32-Arduino-Servo-Library).
-   After downloading, you will get a .zip file.
-   Use any software to Unzip this downloaded folder.
-   You will get a folder with name  _ESP32-Arduino-Servo-Library-Master._
-   Change the name of folder from  ESP32-Arduino-Servo-Library-Master  to _ESP32_Arduino_Servo_Library._
-   Copy this folder to Arduino library folder. You can find the Arduino library folder inside the Arduino installation folder.
-   Now open your Arduino IDE, library for servo will be there. Now you can use it with ESP32.

Remember, you might have already installed library for servo motor in your Arduino IDE. But that library will not work with your ESP32, because that is for other boards like Arduino Uno, Arduino mega and stm32. Now we can use this library to control position of servo from a web server.

## Example code

Upload this code to Arduino IDE, this code rotates the servo for 180 degrees in clockwise direction and for 180 degrees in back direction. Shaft will move from initial position till 180 degrees and then come back to the same position.

```c
#include <Servo.h>

static const int servoPin = 13;  // defines pin number for PWM

Servo servo1;  // Create object for servo motor

void setup() {
Serial.begin(115200);
servo1.attach(servoPin);  // start the library 
}

void loop() {
for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
servo1.write(posDegrees);
Serial.println(posDegrees);
delay(20);
}

for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
servo1.write(posDegrees);
Serial.println(posDegrees);
delay(20);
}
}
```

## Controlling servo with POT example

This sketch controls the position of servo with the help potentiometer. **GPIO32**  is used as an analog pin. Voltage across POT is mapped to pulse width position which controls the shaft position. you can read of  [ADC of ESP32 in this article](https://microcontrollerslab.com/adc-esp32-measuring-voltage-example/).

```c
#include <Servo.h>

static const int servoPin = 13;
static const int potentiometerPin = 32;

Servo servo1;

void setup() {
Serial.begin(115200);
servo1.attach(servoPin);
}

void loop() {
int servoPosition = map(analogRead(potentiometerPin), 0, 4096, 0, 180);
servo1.write(servoPosition);
Serial.println(servoPosition);
delay(20);
}
```

Now, We will show you an example of  **controlling servo motor from web server**  and after that, we will explain working of code and how to  **make a web server with esp32**.

## Creating Servo Web server with ESP32

After making the connection diagram and installing library, copy this code to Arduino IDE and upload it to ESP32 DOIT DEVKIT.

```c
/*********
Microcontrollerslab.com
you can get more projects about ESP32
Microcontrollers lab
*********/

#include <WiFi.h> 
#include <Servo.h>

Servo ObjServo; // Make object of Servo motor from Servo library
// Objects are made for every servo motor,we want to control through this library

static const int ServoGPIO = 13; // define the GPIO pin with which servo is connected

// Variables to store network name and password
const char* ssid = "PTCL-BB"; // Enter your network name
const char* password = "5387c614"; //Enter your network password

// Set the server port nunber to deafualt 80
WiFiServer server(80);

// this variable header stores the HTTP requests data
String header;

// These variables used to store slider position 
String valueString = String(0);
int positon1 = 0;
int positon2 = 0;

void setup() 
{
Serial.begin(115200); //define serial commuination with baud rate of 115200
ObjServo.attach(ServoGPIO); // it will attach the ObjServo to ServoGPIO pin which is 13 
Serial.print("Making connection to "); // it will display message on serial monitor
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
// These lines prints the IP address value on serial monitor 
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin(); // It will start the servo motor with given position value. 
}

void loop(){
WiFiClient client = server.available(); // Listen for incoming clients

if (client)
{ // If a new client connects,

String header = client.readStringUntil('\r');
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();

// Display the HTML web page
client.println("<!DOCTYPE html><html>");
client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
client.println("<link rel=\"icon\" href=\"data:,\">");
// CSS to style the on/off buttons 
// Feel free to change the background-color and font-size attributes to fit your preferences
client.println("<style>body { text-align: center; font-family: \"Trebuchet MS\", Arial; margin-left:auto; margin-right:auto;}");
client.println(".slider { width: 300px; }</style>");
client.println("<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>");

// Web Page
client.println("</head><body><h1>ESP32 with Servo</h1>");
client.println("<p>Position: <span id=\"servoPos\"></span></p>"); 
client.println("<input type=\"range\" min=\"0\" max=\"180\" class=\"slider\" id=\"servoSlider\" onchange=\"servo(this.value)\" value=\""+valueString+"\"/>");

client.println("<script>var slider = document.getElementById(\"servoSlider\");");
client.println("var servoP = document.getElementById(\"servoPos\"); servoP.innerHTML = slider.value;");
client.println("slider.oninput = function() { slider.value = this.value; servoP.innerHTML = this.value; }");
client.println("$.ajaxSetup({timeout:1000}); function servo(pos) { ");
client.println("$.get(\"/?value=\" + pos + \"&\"); {Connection: close};}</script>");

client.println("</body></html>"); 

//GET /?value=180& HTTP/1.1
if(header.indexOf("GET /?value=")>=0) 
{
positon1 = header.indexOf('=');
positon2 = header.indexOf('&');
valueString = header.substring(positon1+1, positon2);

//Rotate the servo
ObjServo.write(valueString.toInt());
Serial.println(valueString); 
} 

header = "";
client.stop();
Serial.println("Client disconnected.");
Serial.println("");
}
}
```

Before you upload code, you need to change network credentials and change them with your WiFI name and password.

[![servo motor web server accessing through IP address](https://microcontrollerslab.com/wp-content/uploads/2019/04/servo-motor-web-server-accessing-through-IP-address.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/04/servo-motor-web-server-accessing-through-IP-address.jpg)

After uploading this code to ESP32 board, open your serial monitor and note down the IP address as shown in picture below:

[![ESP32 servo motor Web server slider](https://microcontrollerslab.com/wp-content/uploads/2019/04/ESP32-servo-motor-Web-server-slider.jpeg)](https://microcontrollerslab.com/wp-content/uploads/2019/04/ESP32-servo-motor-Web-server-slider.jpeg)

Copy this IP address and open it with any web browser. You will see this web page in your browser. you will see a slider with position control.

[![ESP32 servo motor control with web server](https://microcontrollerslab.com/wp-content/uploads/2019/04/ESP32-servo-motor-control-with-web-server.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/04/ESP32-servo-motor-control-with-web-server.jpg)

You can control the position of servo’s shaft with the help of this slider.

You can move the slideR in the left or right position to rotate the motor position in the clockwise and ant-clockwise direction.

## Code working



-   It will create a web page with a slider. Any web client can connect to this web page through an IP address we get in the last section.
-   The slider can control the position of the shaft between 0 and 180 degrees. A web client can move the slider in the left or right position to control the shaft position.
-   Web client once opens the web page, they do not need to update the page, again and again, to update the position of the slider because we use the AJAX javascript file to refresh the web page automatically when a user updates the position of the slider.
-   Web page sends HTTP requests to ESP32 to update position of a servo motor.

These lines add libraries of the WiFi driver and servo motor.

```c
#include <WiFi.h>   // add library of WiFi for ESP32
#include <Servo.h> // add library of Servo for ESP32
```

This line makes an object of Servo motor from the  **Servo library**. Objects are made for every servo motor if we want to control multiple servos through this single servo library. We can create up to 12 objects.

```c
Servo ObjServo;  // create object with name ObjServo
```

This line defines the name of the GPIO pin to which we have connected the servo motor.

```c
static const int ServoGPIO = 13;  // Pin number to which control signal pin is connected
```

These variables store network name and password for connecting ESP32 with WiFi network

```c
const char* ssid = "PTCL-BB"; // Enter your network name
const char* password = "5387c614"; //Enter your network password
WiFiServer server(80);// Set the server port nunber to deafualt 80
```

This variable header stores the HTTP requests data received from a web client.

```c
String header;
```

These variables store previous and update values of servo position and slider position.

```c
String valueString = String(0);
int positon1 = 0;
int positon2 = 0;
```

First line defines the baud rate of serial communication and second line attaches the  **GPIO pin**  with the object of the servo motor which we created earlier.

```c
Serial.begin(115200); //define serial communication with baud rate of 115200
ObjServo.attach(ServoGPIO); // it will attach the ObjServo to ServoGPIO pin which is 13
```

This part of the code is used for connecting ESP32 to a WiFi router. ESP32 connects to the WiFi router and displays the IP address on the serial monitor.

```c
Serial.print("Making connection to "); // it will display message on serial monitor
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
// These lines prints the IP address value on serial monitor 
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin(); // It will start the servo motor with given position value. 
}
```

Before explaining the code inside the loop function, we will explain HTML part of this code which we have used inside the main function. This HTML part of code is used to create slider and web page layout.

### Creating a Web page

The following code is used for an HTML page. This web page is responsible for making a range slider and updating the web page automatically. If you are just a beginner with HTML and CSS, you can  [visit](https://www.w3schools.com/)  this website to learn the basics of HTML and CSS.

```c
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
<style>
body {
text-align: center;
font-family: "Trebuchet MS", Arial;
margin-left:auto;
margin-right:auto;
}
.slider {
width: 300px;
}
</style>
<script
src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></sc
ript>
</head>
<body>
<h1>ESP32 with Servo</h1>
<p>Position: <span id="servoPos"></span></p>
<input type="range" min="0" max="180" class="slider" id="servoSlider"
onchange="servo(this.value)"/>
<script>
var slider = document.getElementById("servoSlider");
var servoP = document.getElementById("servoPos");
servoP.innerHTML = slider.value;
slider.oninput = function() {
slider.value = this.value;
servoP.innerHTML = this.value;
}
$.ajaxSetup({timeout:1000});
function servo(pos) {
$.get("/?value=" + pos + "&");
{Connection: close};
}
</script>
</body>
</html>
```

### Creating a range slider

To create a range slider in HTML, we use <input> and </input> tags. This line create a range slider with <input> and </input> tags.

```c
<input type="range" min="0" max="180" class="slider" id="servoSlider"
onchange="servo(this.value)"/>
```

-   The type defines the type of slider because we want to create a range slider, therefore used “range” and define the minimum value of 0 and a maximum value of 180.
-   One change feature calls a javascript function which is explained below.

This is a javascript code which is used to update web page automatically and send HTTP request having values of the slider position. We write javascript functions between <script> </script> tags. This code updates the web page with slider position value.

```c
var slider = document.getElementById("servoSlider");
var servoP = document.getElementById("servoPos");
servoP.innerHTML = slider.value;
slider.oninput = function() {
slider.value = this.value;
servoP.innerHTML = this.value;
} 
$.ajaxSetup({timeout:1000});
 function servo(pos) {
 $.get("/?value=" + pos + "&");
 {Connection: close};
 }
```

These lines get the values of slider position from HTTP request data which is stored in header string. ObjServo.write() function rotate the servo motor according to received value of slider position.

```c
if(header.indexOf("GET /?value=")>=0) 
{
positon1 = header.indexOf('=');
positon2 = header.indexOf('&');
valueString = header.substring(positon1+1, positon2);


ObjServo.write(valueString.toInt());
Serial.println(valueString); 
}
```