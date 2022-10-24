
# Welcome to IoT-Spot👋



![Logo](https://github.com/prathimacode-hub/prathimacode-hub/blob/main/Cover%20Photos/IoT-Spot.png)


## 📌Espressif ESP8266
The ESP8266 is a low-cost Wi-Fi microchip, with built-in TCP/IP networking software, and microcontroller capability, produced by Espressif Systems. NodeMCU is a low-cost open source IoT platform.NodeMCU is an open source firmware for which open source prototyping board designs are available. The name "NodeMCU" combines "node" and "MCU" (micro-controller unit). The term "NodeMCU" strictly speaking refers to the firmware rather than the associated development kits. NodeMCU is formed by an ESP12E, which still has an ESP8266EX inside it.
In a nutshell, an ESP8266 is an open hardware development board that can be used by tinkerers, hobbyists, and makers to design and build devices that interact with the real world. 

This repository contains all the basic ESP8266 Projects one needs to know before working on end-to-end projects.
### Features of ESP8266 include:
- 32-bit microprocessor operating at 80 or 160MHz.
- 320 KByte of RAM.
- Operating voltage: 3.3V.
- Input voltage: 7-12V.
- Digital I/O pins: 16.
- Analog input pin: 1.
- 2 UART channel
- 2 SPI channel.
- 1 I2C channel.
- WiFi 802.11 b/g/n support (2.4 GHz), up to 72.2 Mbps.
- PCB Antenna.

- 17 programmable GPIO pins.
- 10 bit ADC with upto 18 channels.
- 8 bit DAC.

- 4 PWM output interfaces.
- Integrated Hall effect sensor.
- WPA, WPA2 authentication and Privacy Infrastructure.
- Wi-Fi Mode Station/SoftAP/SoftAP+Station.
- 3 sleep modes.

## 📍Pin Diagram
![pindiagram](https://www.electroniclinic.com/wp-content/uploads/2020/06/NODEMCU-ESP8266-Pinout-features-and-specifications.jpg)

Specifications:
- Micro-USB port
- 3.3V regulated supply.
- Vin: External input power supply.
- EN, RST: Pin and button to reset the microcontroller.
- A0: Used to measure analog voltage in the range 0-3.3V
- GPIO1 to GPIO16: Used as input-output pins.
- SD1, CMD, SD0, CLK: Used for SPI communication.
- TXD0, RXD0, TXD2, RXD2: Used as UART interfaces. RXD1 & TXD1 are used to upload firmware on the board.

## 📃Documentation

[Documentation provided by Espressif for all ESP Series](https://www.espressif.com/en/support/documents/technical-documents)

[Documentation provided by Espressif for ESP8266EX](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf)

## 📦Installation

### Prerequisites
Before starting the installation process, make sure you have the latest version of [Arduino IDE][1].

[1]: <https://www.arduino.cc/en/software>

### Installing ESP8266 libraries to Arduino IDE
Follow the steps below:
1. In your Arduino IDE, go to `File>Preferences`.

![filemenu][filemenu]

2. Enter the following URL into the "Additional Board Manager URLs" fields:<br>
`http://arduino.esp8266.com/stable/package_esp8266com_index.json`<br>
Then, click "OK".

![preferences][preferences]

Note: If you already have ESP8266 board URL, you can seperate the URLs with a comma.

3. Open Boards Manager. Go to `Tools>Board>Boards Manager`.

![toolsmenu][toolsmenu]

4. Search for **ESP8266** and press install button for **ESP8266 by ESP8266 Community**

![boardsmanager][boardsmanager]

5. Well done!. **ESP8266** libraries should be installed in you Arduino IDE.

![installed][installed]

### Test the installation
Follow the steps below:

1. Connect your ESP8266 board to your computer through micro-USB cable. Make sure the power LED turns on.

2. Start Arduino IDE and navigate to `Tools>Boards>/<Select your ESP8266 board>`

![selectboard][selectboard]

3. Go to `Tools>Port` and select appropriate Port to which you ESP8266 board is connected.

![selectport][selectport]

4. Now let's upload the Blink Program to check if we are able to program our ESP8266 board. Open example sketch from `File>Examples>01.Basics` or run the below program.
```
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```
Note: For more info, go to [Basic LED Blink using ESP8266](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP8266/Basic%20LED%20Blink%20using%20ESP8266)

[filemenu]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-open-preferences.png?w=197&quality=100&strip=all&ssl=1>
[preferences]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-enter-URL.png?w=722&quality=100&strip=all&ssl=1>
[toolsmenu]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-open-boards-manager.png?w=671&quality=100&strip=all&ssl=1>
[boardsmanager]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-search-ESP8266.png?w=786&quality=100&strip=all&ssl=1>
[installed]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/ESP8266-Board-add-on-in-Arduino-IDE-installed.png?w=786&quality=100&strip=all&ssl=1>
[selectboard]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-select-board.png?w=669&quality=100&strip=all&ssl=1>
[selectport]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-select-COM-port.png?w=584&quality=100&strip=all&ssl=1>

## Examples
- [Basic LED Blink using ESP8266](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP8266/Basic%20LED%20Blink%20using%20ESP8266)
- [HTTP Authentication using ESP8266](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP8266/HTTP%20Authentication%20using%20ESP8266)
... and many more.