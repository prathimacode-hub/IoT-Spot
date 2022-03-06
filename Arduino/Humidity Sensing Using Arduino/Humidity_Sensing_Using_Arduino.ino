#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Starting the sensor...");
  delay(1500);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();// To Read temperature as Fahrenheit, add (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Cannot read from DHT Sensor attached..."));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float heat_index_f = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float heat_index_c = dht.computeHeatIndex(t, h, false);

  Serial.println(F("humidity-"));
  Serial.print(h);
  Serial.println(F("temperature-"));
  Serial.print(t);
  Serial.print(F("degree centigrade-"));
  Serial.println(f);

  delay(2000);
}
