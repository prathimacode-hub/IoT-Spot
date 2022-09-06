# LED Blinking using ESP32

## [Simulation Link](https://wokwi.com/projects/342032382586520146)
## [Video Demonstration](https://youtu.be/4OFz-PGe03Q)
## ESP32 LED Blinking Tutorial Prerequisites

Let’s start with the basic introduction of general-purpose input-output pins of the ESP32 Devkit. You can use any ESP32 development board you want until it has an ESP-WROOM-32 chip on it. Also, the concepts used in this article will remain applicable to other types of ESP32 boards. For more features of this board, you can go through this tutorial:



We will be using  **Arduino IDE**  to program ESP32. So if you don’t know how to install a library of this IOT board you can check this tutorial:

-   [How to install ESP32 in Arduino IDE](https://microcontrollerslab.com/install-esp32-arduino-ide/)

## ESP32 GPIO Pins

ESP32 Devkit supports 36 GPIO pins and but not all the pins can be used as digital output pins. From a total of 30 pins, only 24 pins can be used both as digital input and output. But six pins like GPIO34, GPIO35, GPIO36, GPIO37, GPIO38, GPIO39 can be used as digital input pins only. But We have enough 24 pins which can be used as digital output pins. So we can use any out of thirty pins to drive a LED, relay, seven segment displays, liquid crystal display, and other actuators.

Note: GPIO6 to GPIO 11 are not exposed to pinout of ESP32 dev kit which we are using in this tutorial. Because these pins are internally connected to the integrated SPI flash on the ESP-WROOM-32 chip.

-   [ESP32 pinout and details of each pin](https://microcontrollerslab.com/esp32-pinout-use-gpio-pins/)

Now that I believed you have already installed ESP32 in Arduino IDE and You have also gone through the article on ESP32 pinout. Now let’s see how to blink an LED using ESP32 and Arduino IDE.

[![ESP32 pin mapping](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-pin-mapping-1024x578.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-pin-mapping.jpg)

## LED Blinking Using ESP32

As I mentioned earlier in ESP32, we have can use 30 pins as a digital output pin. Now let’s select one pin and used it to turn on and turn off LED with some delay.

In this example, we will control an LED with GPIO22 of ESP32. That means we will learn to use GPIO pins as digital output pins. We connect an LED to GPIO22 through a current limiting resistors of 220 ohm. This ESP32 LED blinking example works as mentioned below:

-   RED LED Turns on for one second that means GPIO22 goes to active high state
-   In next step, LED turns off for one second that means GPIO22 goes to active low state
-   Above two steps keep repeating as shown below:

![LED blinking ESP32 example in Arduino IDE](https://microcontrollerslab.com/wp-content/uploads/2019/03/LED-blinking-ESP32-example-in-Arduino-IDE.jpg)

### LED Blinking Connection Diagram

As you can in the above pinout diagram of ESP32, we have a total of 36 GPIO pins, but we will be using  **GPIO22** as a digital output pin. On different boards, these pins can be located at different locations. Therefore, you need to check its datasheet before using pin number in programming which I will explain in the programming part of this article.

Now check the schematic and make it on your breadboard as shown below:

[![LED blinking ESP32](https://microcontrollerslab.com/wp-content/uploads/2019/03/LED-blinking-ESP32.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/LED-blinking-ESP32.jpg)

Now make the circuit connection according to the above circuit diagram on the bread board.

-   Connect  **GPIO22**  with the anode or positive pin of the LED. Positive pin is usually round edge.
-   Connected other end of the LED with ground through  **330 ohm resistor**. Resistor is used as a current limiting resistor.
-   Each pin can provide a maximum of 10mA current. So current limiting resistor is used to limit current not crossing this limit.
-   If you want to use GPIO pins to drive any other device which has a higher current requirement, you should connect a transistor in between or current driver integrated circuit like ULN2003 relay driver circuit IC.

### ESP32 GPIO Pins Arduino Functions

To write code for LED blinking using ESP32, first, you need to understand three main functions used in Arduino IDE to control general purpose input output pins. If you have already used Arduino IDE for Arduino or esp8266 programming, you will be already familiar with these functions :

-   **pinMode() :**This function is used to select input output pin mode either as a input or output. First argument to this function is pin number to which you want to declare either as a input or output. Second argument to this function is in which direction you want to use a digital pin. For example, if we write pinMode(22, OUPUT) , it will declare pin number 22 as a digital output pin.
-   **digitalWrite(pin_number, LOGIC_HIGH_LOW) :** This function is used to control digital output pin. First argument is a pin number and second value to this function is logic state ‘HIGH’ or ‘LOW’. For example, if you write digitalWrite(22, HIGH), it will make pin number 22 logic HIGH or 3.3 volt and if you write digitalWrite(22, LOW), it will make digital output pin 22 LOW or you will get zero volt at the output pin.
-   **delay(value) :** This function is used to generate delay in mili seconds. If you want to add a delay of one second between turning on and turning off a LED, you will use this state delay(1000).
-   **setup( ) :** In Arduino IDE, setup function is used for declaration or initialization. A pinMode function is used for declaration of digital pins. So it will be defined inside setup function. It will become more clear when you see the example code at the end of this article.
-   **Loop( ) :** In Arduino IDE, loop function is like a main function in c programming. In c programming whenever, you want to perform certain tasks again and again, we use those c statements inside the loop. Similarly, we use loop function in Arduino IDE to perform certain tasks again and again.

### Code

This code is used to blink LED connected with pin number 22 with a delay of one second.

```c
void setup()
{
pinMode(22, OUTPUT); // Set GPIO22 as digital output pin
}

void loop() 
{
digitalWrite(22, HIGH); // Set GPIO22 active high
delay(1000);  // delay of one second
digitalWrite(22, LOW); // Set GPIO22 active low
delay(1000); // delay of one second
}
```

Now to run this example of LED blinking using ESP32, simply copy this code to Arduino IDE and compile the code.

After compiling code, click on upload button to upload code to ESP32 devkit.

Before uploading the code, make sure you have selected the board and COM pin to which your ESP32 board is connected.

![installing ESP32 in Arduino IDE 10](https://microcontrollerslab.com/wp-content/uploads/2019/03/installing-ESP32-in-Arduino-IDE-10.jpg)

If you do not see this board in toots>port option , you need to install the driver for this board, you can download and install drivers from this  [link](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers).

Go to tools>Boards and select ESP32[![installing ESP32 in Arduino IDE 09](https://microcontrollerslab.com/wp-content/uploads/2019/03/installing-ESP32-in-Arduino-IDE-09.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/installing-ESP32-in-Arduino-IDE-09.jpg)

Go to tools>Upload speed and choose 115200

Also, select Flash Frequency of 80Mhz from tools options.

Now click on the upload button.[![installing ESP32 in Arduino IDE 11](https://microcontrollerslab.com/wp-content/uploads/2019/03/installing-ESP32-in-Arduino-IDE-11.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/installing-ESP32-in-Arduino-IDE-11.jpg)