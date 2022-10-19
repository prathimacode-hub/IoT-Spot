# How to use ESP32 Bluetooth module with Arduino IDE | Project

The ESP32 development board has an inbuilt Bluetooth module. In this post, I will show you how to use the  ESP32 Bluetooth module with Arduino IDE. And by the end of this article, you would be able to use the ESP32 Bluetooth module with Arduino IDE to control external LEDs connected to the GPIO pins.

The ESP32 board along with the inbuilt Wi-Fi module also comes with an inbuilt Bluetooth module. This makes communication with mobile devices using the ESP32 Bluetooth module with Arduino IDE quite easy and efficient.

## ESP32 Bluetooth module project details:

In this project, you will  control the external LEDs  connected to one of the GPIO pins of ESP32 using Bluetooth communication  between the ESP32 board and the smartphone.

**Note:**  I am going to use a mobile app called  _Serial Bluetooth terminal_  to control the LEDs.

## **Materials Required:**

-   ESP32 Module
-   Arduino IDE
-   Micro USB cable
-   Jumper Wire
-   1 x 100-ohm resistors
-   1 x LED
-   Bluetooth Serial Monitor App

## **Circuit Diagram:**

![Circuit Diagram to control LED using ESP32 inbuilt Bluetooth module](https://www.etechnophiles.com/wp-content/uploads/2021/04/circuit2.jpg?ezimgfmt=rs:411x481/rscb40/ng:webp/ngcb40)

Circuit Diagram to control LED using ESP32 inbuilt Bluetooth module

**Step 1**:  Connect the ESP32 board to your PC through a micro-USB cable. The inbuilt RED LED on the board is turned on once the board is connected.

**Step 2**: Open up the Arduino application on your PC, go to  **Tools> Board**  from the top menu and click on the “**ESP32 Arduino”** option. Now select the type of ESP32 board you are using. I have selected the  ESP32 dev module.

**Step 3**:  Now go to  **Tools>Port**, and select the port to which the board is connected to the PC (example COM4).

**Step 4**: Paste/write the ESP32 Bluetooth program given below in Arduino IDE.

```c
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
char receivedChar;// received value will be stored as CHAR in this variable

const char turnON ='ON';
const char turnOFF ='OFF';
const int LEDpin = 15;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Bluetooth"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("To turn ON send: ON");//print on serial monitor  
  Serial.println("To turn OFF send: OFF"); //print on serial monitor 
  pinMode(LEDpin, OUTPUT);
}
void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    receivedChar =(char)SerialBT.read();
    SerialBT.print("Received:");// write on BT app
    SerialBT.println(receivedChar);// write on BT app      
    Serial.print ("Received:");//print on serial monitor
    Serial.println(receivedChar);//print on serial monitor  
    delay(10);  
    if(receivedChar == turnON)
    {
     SerialBT.println("LED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     digitalWrite(LEDpin, HIGH);// turn the LED ON 
     delay(20);
    }
    if(receivedChar == turnOFF)
    {
     SerialBT.println("LED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpin, LOW);// turn the LED off 
      delay(20);
    }    
  }
}
```
**Step 6**: Click the upload option to upload the code. Don’t forget to press and hold the BOOT button during the uploading process.

**Step 7:**  Open the serial monitor on the Arduino IDE by going to  **Tool>Serial Monitor**  or by pressing  **Ctrl+Shift+M**.

**Step 8:** Press the  RESET button  on the ESP32 board.

**Step 9:**  Now it’s time to switch to the mobile device that we are going to use to control the LED. Download the  [Bluetooth Serial Terminal App](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en_IN&gl=US).

![Bluetooth Serial Terminal App](https://www.etechnophiles.com/wp-content/uploads/2021/04/app-title.png?ezimgfmt=rs:709x235/rscb40/ng:webp/ngcb40)

Bluetooth Serial Terminal App

**Step 10:**  Next pair up the ESP32 board with the mobile device.

![Pairing up the ESP32 board with mobile device using bluetooth module](https://www.etechnophiles.com/wp-content/uploads/2021/04/pairup1.jpg?ezimgfmt=rs:335x577/rscb40/ng:webp/ngcb40)

Pairing up the ESP32 board with mobile device

**Step 11:** Now open up the  [Bluetooth Serial Terminal App](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en_IN&gl=US)  and go to  **Menu> Devices**.

![Browse to Menu>Devices in bluetooth Serial Terminal app](https://www.etechnophiles.com/wp-content/uploads/2021/04/app.jpg?ezimgfmt=rs:714x287/rscb40/ng:webp/ngcb40)

Browse to Menu>Devices in Bluetooth Serial Terminal app

**Step 12:**  Select the name of the ESP32 board that you want to connect. I am going to select “ESP32 Bluetooth”.

![Select the ESP32 board in the Bluetooth Terminal App](https://www.etechnophiles.com/wp-content/uploads/2021/04/device-select.jpg?ezimgfmt=rs:434x635/rscb40/ng:webp/ngcb40)

Select the ESP32 board in the Bluetooth Terminal App

**Step 13:** Now as the ESP32 board is connected with the mobile device, we can communicate with it by sending serial data.

-   Send “ON”: To turn ON the LED
-   Send “OFF”: To turn OFF the LED
