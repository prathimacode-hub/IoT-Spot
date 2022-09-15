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

### **Code Explanation:**

#define LED_BuiltIn 2

-   Define the macro for Pin 2 called  LED_BUILTIN**.**  Defining macros simplifies your program. Whenever the name  LED_BUILTIN  appears in the program, the compiler changes it to pin no. 2 automatically.
-   So to use a pin other than GPIO pin 2, you just have to change the GPIO PIN at one place only i.e, where you have defined the macro for GPIO pin 2.

**Note:** Macros are defined outside the functions and at the beginning of the program.

#### **Inside the void setup() function:**

**Note** **:** The  setup() function is called as soon as the program starts executing. It is used to initialize variables and set the mode of the GPIO pins. Setup() function is executed only once.

 pinMode(LED_BuiltIn,OUTPUT);

-   Here, we are initializing the mode of the  LED_BuiltIn  GPIO pin as OUTPUT.

Serial.begin(115200);

-   Serial.begin() function starts the serial data communication between the Arduino board and the Arduino IDE.
-   The argument of the  Serial.begin()  function sets the data rate in bits per second (baud) for serial data transmission. Here we are setting the data rate as 115200 bits per second.
-   **Supported baud rates**  are 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600, and 115200.

delay(1000); 
Serial.println("ESP32 Touch sensor value");

-   The  delay()  function is used to stop/pause the execution of the program for 1000 milliseconds (1 second). In order to wait for the serial monitor to start.
-   And the  Serial.println()  function is used to print the data to the serial port in the human-readable ASCII format followed by a return character ("\r”) and a newline character ("\n”).
-   Here, I am printing the string "ESP32 Touch sensor value” on the serial monitor of Arduino.
-   To open the serial monitor, go to  **Tools>Serial monitor** or press **Ctrl+Shift+M**. Then select the baud rate 115200 from the drop-down menu present at the bottom right corner of the serial monitor.

**Note:**  Make sure the Arduino board is connected to the PC and right COM port is selected.

#### **Inside the void loop() function:**

**Note:** After the execution of the  setup()  function, the execution loop() function begins. Its function is to continuously run the code written inside of it in an infinite loop. That’s why it’s called a  void loop().

Serial.println(touchRead(15));
delay(1000);

-   Serial.println()  function prints the value returned by the  touchRead()  function.
-   As explained earlier, the  touchRead()  function is used to read the value of the touch sensor by accepting the GPIO pin number as the argument. And with the increase in touch-force on the wire, the value returned by the  touchRead()  increases.
-   The  delay()  function stops the program for 1 second (1000 milliseconds).

if (touchRead(15)<40)
{.....}

-   **if-else** statements are called conditional statements.
-   If the condition inside the **()**  bracket is true, the statements inside the  **if {}**  block is executed.
-   If the condition inside the **()**  bracket is false, the compiler skips the code/statement inside the  **if {}**  block.
-   In the program given above, when the  touchRead()  function returns a value greater than 40, statements inside the  **if{}**  block is executed.

##### **Statements inside the if() block:**

digitalWrite(LED_BuiltIn,HIGH); 
delay(500); 
digitalWrite(LED_BuiltIn,LOW); 
delay(500);

-   It’s a simple LED blinking program. First, the  digitalWrite()  function turns ON the inbuilt LED.
-   Then there is a delay of 500 milliseconds.
-   The  digitalWrite()  function turns OFF the inbuilt LED.
-   Again there is a delay of 500 milliseconds.

![Turning LED ON using ESP32 touch sensor ](https://www.etechnophiles.com/wp-content/uploads/2021/03/result_touch._800x425.jpg?ezimgfmt=rs:714x379/rscb40/ng:webp/ngcb40)

Turning LED ON using the ESP32 touch sensor

**Step 6** **:** Touch the jumper wire connected to the respective GPIO pin and observe the readings on the serial monitor.

So the outcome of this project is: when you touch the jumper wire connected to the GPIO pin 15, the inbuilt LED of the esp32 board lights up.