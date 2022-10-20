#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
char receivedChar;// received value will be stored as CHAR in this variable

const char turnON ='ON';
const char turnOFF ='OFF';
const int LEDpin = 2;

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
