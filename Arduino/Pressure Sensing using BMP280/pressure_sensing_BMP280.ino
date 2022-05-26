#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)
int led = 8;

//Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  while ( !Serial ) delay(100);   // wait for native usb
  Serial.println(F("BMP Test initialized"));
    if (bmp.begin(0x56))
     {
       Serial.println(F("Bmp280 wired successfully!"));
     }else
     {
      Serial.println(F("Check wiring or try different address for bmp280"));
      while(1);
     }
}

void loop() {
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");

    if(bmp.readPressure()> 100000){
      digitalWrite(led,HIGH);
      delay(500);
    }else{
      digitalWrite(led,LOW);
    }

    Serial.println();
    delay(1000);
}