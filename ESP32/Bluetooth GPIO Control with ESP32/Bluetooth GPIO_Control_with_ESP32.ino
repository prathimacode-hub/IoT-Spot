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