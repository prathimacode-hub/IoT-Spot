# Controlling LED using Nodemcu ESP8266 in Blynk 2.0

This project demonstrates how to control LEDs using the Nodemcu ESP8266 microcontroller and the Blynk 2.0 app. The code is written in Arduino and uses the Blynk library for communication.

## Hardware Setup

1. Connect the LEDs to the relay pins defined in the code (`light1` and `light2`).
2. Connect a WiFi indicator LED to the `wifiLed` pin.
3. Flash the code to your Nodemcu ESP8266.

## Blynk App Setup

1. Visit the [Blynk website](https://blynk.io/) and create an account.
2. In the Blynk web dashboard, select the hardware as **ESP8266**.
3. Create a virtual pin datastream for LED control:
   - Set the pin to **V0**.
   - Choose the datatype as **Integer**.

4. Create another virtual pin datastream for the second LED:
   - Set the pin to **V1**.
   - Choose the datatype as **Integer**.

5. Create a switch in the web dashboard:
   - Open the switch settings.
   - Under **Datastream**, select **led 1** for the first switch.
   - Set the ON and OFF values as **0** and **1** respectively.
   - Repeat the process for the second switch but choose **led 2**.

## Blynk Mobile App Setup

1. Download and install the Blynk 2.0 app on your smartphone.

2. Log in to the app.

3. Create a new project.

4. Add two buttons to control `light1` and `light2`:
   - For button 1, change the datastream to **led 1**.
   - For button 2, change the datastream to **led 2**.

## Arduino Code Explanation

### Libraries
```ino
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
```

### Pin Definitions
```ino
#define light1 D1
#define light2 D2
#define wifiLed D0
```
#### Define relay and WiFi indicator pin numbers.

### Blynk Authentication
```ino
char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";
```
#### Replace `Your_Blynk_Auth_Token`, `Your_WiFi_Name`, and `Your_WiFi_Password` with your Blynk authentication token and WiFi credentials.

### Button Controls
```ino
BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  if (value1 == 1) {
    digitalWrite(light1, LOW);
  } else {
    digitalWrite(light1, HIGH);
  }
}

BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  if (value2 == 1) {
    digitalWrite(light2, LOW);
  } else {
    digitalWrite(light2, HIGH);
  }
}

```
#### Handle button press events for controlling light1 and light2.

### Setup Function
```ino
void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(wifiLed, OUTPUT);
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  digitalWrite(wifiLed, HIGH);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}
```
#### Initialize pins, turn off the LEDs, and start Blynk with WiFi credentials.

### Loop Function
```ino
void loop() {
  Blynk.run();
}
```
#### Run the Blynk library in the loop.

---
This explains, how the code works and how to set up the Blynk app for LED control with your Nodemcu ESP8266. Feel free to modify the code and app to suit your specific needs.
