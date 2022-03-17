#include <SPI.h>    // For SD Card
#include <DHT.h>    // For DHT Sensor
 
File file_data;
 
#define DHTPIN 6    // DHT11  is connected to pin 6 on arduino
#define DHTTYPE DHT11   // DHT11 sensor is used
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT library
 
void setup() {
  Serial.begin(9600); //Set baud rate to 9600 bauds
  while (Serial.available == 0){}

  Serial.print("Initializing SD card!");

  if (!SD.begin()) {
    Serial.println("Failed to Initialize!");
    while True{}
  }
  Serial.println("Initialization Successful!");
  delay(1500);
}
 
uint16_t line = 1;
 
void loop() {

  delay(1000);
  
  byte RH = dht.readHumidity(); // To Read humidity
  byte Temp = dht.readTemperature();//To Read temperature in degree Celsius
  
  file_data = SD.open("DHT11_Data.txt", FILE_WRITE);
  
  if (file_data) { //If the file opens
    Serial.print(line);
    Serial.print(":    Temperature = ");
    Serial.print(Temp);
    Serial.print("°C,    Humidity = ");
    Serial.print(RH);
    Serial.println("%");

    // Writing the readings to SD card file (DHT11_Data.txt)
    file_data.print(line++);
    file_data.print(":    Temperature = ");
    file_data.print(Temp);
    file_data.print("°C,    Humidity = ");
    file_data.print(RH);
    file_data.println("%");
    file_data.close();
    
  } 
  else { //if file doesn't open
    Serial.println("Couldn't open the requested file.");
  }
}