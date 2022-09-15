# How to use ESP32 Touch Sensor

ESP32 Touch and Hall effect sensor are built-in inside the ESP Wroom 32 microcontroller chip. Both the sensors are easy to program and can be used in small projects. So by the end of this article, you would be able to use and  **program the ESP32 Touch and Hall effect Sensor**  with Arduino IDE.

![Touch and Hall-effect sensor are inside this chip!](https://www.etechnophiles.com/wp-content/uploads/2021/03/ESP32-animated.jpg?ezimgfmt=ng%3Awebp%2Fngcb40%2Frs%3Adevice%2Frscb40-1)

Touch and Hall-effect sensor are inside this chip!

## **ESP32 Touch Sensor Project:**

The ESP32 board comes with  **10 capacitive touch sensors** connected to GPIO pins as shown in the  [ESP32 Pinout](https://www.etechnophiles.com/esp32-dev-board-pinout-specifications-datasheet-and-schematic/)  figure given below:

![esp32 Board Pinout with 30 pins Pinout](https://www.etechnophiles.com/wp-content/uploads/2021/03/esp32-Board-with-30-pins-Pinout.png?ezimgfmt=rs:714x465/rscb40/ng:webp/ngcb40)

_ESP32 GPIO pins having a touch sensor_

**Note:**  ESP32 boards with 30,36 and 38 pins have the same number of touch sensor pins i.e, 10.

These GPIO pins(having a touch sensor) when touched can sense variations in objects that conduct electricity. Like the human skin. So, when you touch the GPIO pin with your finger, it generates some variations. And these variations are read by the sensor.

To read analog values from the touch sensor, an inbuilt function "**touchRead()**"  is used. This function accepts the GPIO pin number as the argument.

**Syntax** **–** touchRead(GPIO_pin);

### **Materials Required:**

-   ESP32 Module
-   Arduino IDE
-   Micro USB cable
-   Jumper Wires

![Jumper wire connected to GPIO Pin 15](https://www.etechnophiles.com/wp-content/uploads/2021/03/circuit_800x487.jpg?ezimgfmt=rs:690x420/rscb40/ng:webp/ngcb40)

Jumper wire connected to GPIO Pin 15

**Step 1** **:**  Connect the ESP32 module to the computer through a micro-USB cable. The RED LED on the board lights up once the board is powered.

**Step 2** **:**  Connect one end of the jumper wire to the GPIO Pin 15. And leave the other end as it is(unconnected). I am using GPIO 15 here. You may use any other GPIO pin having a built-in touch sensor.

**Step 3** **:**  Go to  **Tools> Board**  from the top menu and click on the "**ESP32 Arduino”** option. Now select the ESP32 board type you are using. I have selected the  ESP32 dev module.

**Step 4** **:**  Now go to  **Tools>Port**, and select the port to which the board is connected.

**Step 5** **:** Paste/write the ESP32 touch sensor program given below in Arduino IDE.

**Step 6** **:** Click the upload option to upload the code. Don’t forget to press and hold the BOOT button during the uploading process.

### **Program to use ESP32 Touch Sensor:**
```c
#define LED_BuiltIn 2
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BuiltIn,OUTPUT);
  Serial.begin(115200);
  delay(1000); // stop the execution for 1 sec
  Serial.println("ESP32 Touch sensor value");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(touchRead(15));
  delay(1000);
  if (touchRead(15)<40)
  {
    digitalWrite(LED_BuiltIn,HIGH);
    delay(500);
    digitalWrite(LED_BuiltIn,LOW);
  }
}
```
**OBJECTIVE** **:**  When the jumper wire connected to the GPIO pin 15 is touched, the inbuilt LED of the esp32 board lights up.

