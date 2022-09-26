# ESP32 web server control relay and 220 volt lamp

One of the best projects, you can consider doing with ESP32 is to  **control a 220 volts lamp**  from a web server. But you can also use the same procedure to control  **fans, lights, AC or other electrical devices**  that you want to control from a  **web server**. This tutorial is about controlling a relay and 220 volts lamp from a Web Server using  **ESP32**. First, we will see how to interface a relay and bulb with ESP32 and after that, I will show you how to make a webserver to control lamp/bulb from a web page.

## Introduction to a relay module

Relay is an electromechanical device that is used as a switch between high current and low current devices. Its main parts are coil and contacts. We generally apply dc voltages to coil and connect load across normally open and close contacts. When we supply dc voltage across the coil, it starts to energize. When coil fully energized, contact shift from normally open position to normally close position. You can read these articles to gain further details on relays and their working.

-   Introduction to Electromechanical relays.
-   How to control 5 volts relay with Arduino

## Why we need to use relay?

Light bulbs usually operate on 120 volts or 220 volts power supply in case of AC main supply. We can not interface these AC loads directly with ESP32 development board. We have to use a relay between **ESP32 and lamp**. You will use a relay as a switch to control 120-220 volts lamps. We will control relay with ESP32. We will use a button on web page to control a relay. ESP32 will give signal to relay depending upon the button state from a web page. You can use any relay module. However, I will be using SRD-05VDC-SL-C 5V  **Relay module**. It works on and can be used to control output loads from 120-240 volts and current range of 10A.

### How 5V relay module works?

It consists of 6 pins. Three pins are used to connect with high voltage side i.e. electrical loads and 220 volts power supply and other three pins are used for low voltage side namely; vcc, ground and control signal pin.

### Relay module pinouts

![Relay Module]("./../Images/relay.png)
![Pinout](./Images/pinout.png)

As shown in relay module picture, it also has other components and relay in the middle of board. When we apply active high signal at the signal pin from any microcontroller like ESP32, relay contact move from normally open to normally close. It makes the circuit complete and load turns on.

There are two contact pins that are normally open and normally closed. You always use common pin and either normally open pin or normally close pin to connect load. Depending on NC or NO, you will use active high or active low signal to control the relay.

Normally open: If you use normally open pin, relay will activate with active high signal on control pin and active low signal turn off the relay as shown in figure below:

[![5 volt relay normally open](https://microcontrollerslab.com/wp-content/uploads/2019/05/5-volt-relay-normally-open.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/05/5-volt-relay-normally-open.jpg)

Normally closed: if you use normally close pin, active low signal activates the relay and active high signal on signal pin will deactivate the relay.[![5 volt relay normally close](https://microcontrollerslab.com/wp-content/uploads/2019/05/5-volt-relay-normally-close.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/05/5-volt-relay-normally-close.jpg)

So, you can choose either pin according to active high or low signal. Through which type of signal, you want to turn on or turn off relay.


### List of components

You will require following components to build  **ESP32 remote control relay**  project:

-   ESP32 development board
-   Relay module
-   Lamp
-   Lamp holder
-   Jumper wires
-   Bread board
-   Power supply connector

## Connection diagram of relay and lamp with ESP32

**Warning:**  Before making this circuit diagram, make sure you have not connected ESP32 and lamp with power supply. You are using HIGH voltage in this project, please take all precautions before making this layout.

Now make this layout on breadboard according to the connection diagram shown here:

[![Web Server control a Relay module with ESP32](https://microcontrollerslab.com/wp-content/uploads/2019/05/Web-Server-control-a-Relay-module-with-ESP32.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/05/Web-Server-control-a-Relay-module-with-ESP32.jpg)

We will be using normally open configuration in this project. Because we want to light up the bulb with active high signal. To do so, we will use COM pin and NO pins of high voltage side of relay. Normally there will be no contact between COM and NO pins and lamp will remain off. As soon as we will apply active high signal to control pin of relay through GPIO pin of ESP32, relay will become activate and lamp lights up. In short, when we send an active high signal from ESP32, relay turns on and when we send active low signal from ESP32, relay turns off and similarly lamp turns on and turns off.

Note: Some relay modules have transistors which works with inverted logic. Inverted logic means active low signal will activate the relay and active high signal will tur off the relay. You should check your relay module functionality before using it. SRD-05VDC-SL-C 5V Relay module does not work on inverted logic.

-   Connect 220 volts connector one terminal with lamp one terminal and another terminal with NO pin.
-   Connect other terminal of lamp with COM pin of relay.
-   We will connect low voltage side of relay with ESP32.
-   We are using GPIO22 of ESP32 to provide active high signal to relay. Connect GPIO22 with control signal pin of relay. 
-   Connect ground pin of relay with ground pin of ESP32.
-   Connect Vcc or + pin of relay with Vin pin of ESP32. We are using 5 volts relay and it will work on 5 volt only.

Note: We are using SRD-05VDC-SL-C 5V Relay module and it works on 5 volt. If you connect ESP32 3.3 volts pin with rely Vcc pin, relay will not work. Therefore, I recommend you use Vin pin of ESP32 to supply 5 volts to relay Vcc pin.

## Controlling relay module remotely with ESP32

Now, we will see how to control relay and ultimately lamp from a web server. We will create a **web server to display web page**  with buttons and picture of a bulb. Web server will server the following pages. When you press the ‘ON’ button, you will see this web page on web browser.

[![ESP32 LAMP ON WEB SERVER](https://microcontrollerslab.com/wp-content/uploads/2019/05/ESP32-LAMP-ON-WEB-SERVER.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/05/ESP32-LAMP-ON-WEB-SERVER.jpg)

When you press the ‘OFF’ button, you will see a web page with lamp off picture.[![ESP32 LAMP OFF WEB SERVER](https://microcontrollerslab.com/wp-content/uploads/2019/05/ESP32-LAMP-OFF-WEB-SERVER.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/05/ESP32-LAMP-OFF-WEB-SERVER.jpg)

Now copy this code and upload to ESP32 kit. But before uploading coding, you need to make changes in ssid and password portion with your own WiFi name and password.
