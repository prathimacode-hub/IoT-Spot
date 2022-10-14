
# Welcome to IoT-Spot👋



![Logo](https://github.com/prathimacode-hub/prathimacode-hub/blob/main/Cover%20Photos/IoT-Spot.png)


## 📌Espressif ESP32
ESP32 is a series of low-cost, low-power system on a chip microcontrollers with integrated Wi-Fi and dual-mode Bluetooth. It employs built-in antenna switches, RF Transceiver, power amplifier, low-noise receive amplifier, filters and power management modules.
This repository contains all the basic Arduino Projects one needs to know before working on end-to-end projects.
### Features of ESP32 include:
- 32-bit microprocessor operating at 160 or 240 MHz.
- Ultra low power co-processor.
- 320 KByte of RAM, 448 KByte of ROM.
-  WiFi 802.11 b/g/n.
-  Bluetooth v4.2 and BLE (shared radio with WiFi).
-  34 programmable GPIO pins.
-  12 bit ADC with upto 18 channels.
-  8 bit DAC.
-  10 Touch (capacitive) GPIO pins.
-  4 SPI.
-  2 I^2S and 2I^C interfaces.
-  3 UART channels.
- CAN bus 2.0.
-  PWM (Motor and LED upto 16 channels).
-  Integrated Hall effect sensor.
-  WPA, WPA2, WPA3 and WLAN authentication and Privacy Infrastructure.
-  5μA deep sleep current.
-  Wake up through GPIO, timer, touch interrupts.
## 📍Pin Diagram
![pindiagram](https://lastminuteengineers.b-cdn.net/wp-content/uploads/iot/ESP32-Pinout.png)

Specifications:
- Input only GPIOs: GPIO34, GPIO35, GPIO36 and GPIO39
- ADC Pins: GPIO2, GPIO4, GPIO12-GPIO15, GPIO25-GPIO27, GPIO32-GPIO36, GPIO39
- DAC Pins: GPIO25 and GPIO26
- Touch Pins: GPIO2, GPIO4, GPIO12-GPIO15, GPIO27, GPIO32, GPIO33
- I2C: SCL(GPIO22) and SDA(GPIO21)
- UART Pins: U0_TXD(GPIO1), U0_RXD(GPIO3), U2_TXD(GPIO17), U2_RXD(GPIO16)
- PWM Pins: All GPIO Pins
- Power pins: VIN pin(raw input voltage), 3.3V, GND
- Enable pin: EN
## 📃Documentation

[Documentation provided by Espressif for all ESP32 Series](https://www.espressif.com/en/support/documents/technical-documents)


## 📦Installation

### Prerequisites
Before starting the installation process, make sure you have the latest version of [Arduino IDE][1].

[1]: <https://www.arduino.cc/en/software>

### Installing ESP32 libraries to Arduino IDE
Follow the steps below:
1. In your Arduino IDE, go to `File>Preferences`.
![filemenu][filemenu]

2. Enter the following URL into the "Additional Board Manager URLs" fields:
`https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
Then, click "OK".
![preferences][preferences]

Note: If you already have ESP8266 board URL, you can seperate the URLs with a comma.

3. Open Boards Manager. Go to `Tools>Board>Boards Manager`.
![toolsmenu][toolsmenu]

4. Search for **ESP32** and press install button for **ESP32 by Espressif Systems**
![boardsmanager][boardsmanager]

5. Well done!. **ESP32** libraries should be installed in you Arduino IDE.
![installed][installed]

### Test the installation
Follow the steps below:

1. Connect your ESP32 board to your computer through micro-USB cable. Make sure the power LED turns on.

2. Start Arduino IDE and navigate to `Tools>Boards>/<Select your ESP32 board>`
![selectboard][selectboard]

3. Go to `Tools>Port` and select appropriate Port to which you ESP32 board is connected.

4. Now let's upload the Blink Program to check if we are able to program our ESP32 board. Open example sketch from `File>Examples>01.Basics` or run the below program.
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
Note: For more info, go to [Basic LED Blink using ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/Basic%20LED%20Blink%20using%20ESP32)

[filemenu]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2016/12/arduino-ide-open-preferences.png?w=196&quality=100&strip=all&ssl=1>
[preferences]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2022/04/ESP32-URL-Arduino-IDE.png?w=828&quality=100&strip=all&ssl=1>
[toolsmenu]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/06/boardsManager.png?w=628&quality=100&strip=all&ssl=1>
[boardsmanager]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/06/installing.png?w=786&quality=100&strip=all&ssl=1>
[installed]: <https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/ESP32-Board-add-on-in-Arduino-IDE-installed.png?w=786&quality=100&strip=all&ssl=1>
[selectboard]: <https://circuitdigest.com/sites/default/files/inlineimages/u/Select-ESP32Dev-from-tools.png>

## Examples
- [Basic LED Blink using ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/Basic%20LED%20Blink%20using%20ESP32)
- [HTTP Authentication using ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/HTTP%20Authentication%20using%20ESP32)
- [Hall sensor on ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/Hall%20sensor%20on%20ESP32)
- [LED control on webserver using ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/LED%20control%20on%20webserver%20using%20ESP32)
- [Relay control using Web server on ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/Relay%20control%20using%20Web%20server%20on%20ESP32)
- [Servo_control_using_ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/Servo_control_using_ESP32)
- [Temperature Humidity measure using ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/Temperature%20Humidity%20measure%20using%20ESP32)
- [Touch Sensor on ESP32](https://github.com/prathimacode-hub/IoT-Spot/tree/main/ESP32/Touch%20Sensor%20on%20ESP32)