/*
  Remotely Control Led on Esp8266 using Blynk app and with web interface. 
*/

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Define the relay pins
#define light1 D1
#define light2 D2
#define wifiLed D0
#define BLYNK_AUTH_TOKEN "" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password

//Get the button values
BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  // Check these values and turn the relay1 ON and OFF
  if (value1 == 1) {
    digitalWrite(light1, LOW);
  } else {
    digitalWrite(light1, HIGH);
  }
}

//Get the button values
BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  // Check these values and turn the relay2 ON and OFF
  if (value2 == 1) {
    digitalWrite(light2, LOW);
  } else {
    digitalWrite(light2, HIGH);
  }
}

void setup() {
   Serial.begin(9600);
  delay(100);
  //Set the relay pins as output pins
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(wifiLed,OUTPUT);

  // Turn OFF the relay
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  digitalWrite(wifiLed,HIGH);

  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
