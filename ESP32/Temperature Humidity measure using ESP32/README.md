# ESP32 - Temperature and Humidity measure using DHT22

This tutorial shows how to use the DHT11 and DHT22 temperature and humidity sensors with the ESP32 using Arduino IDE. We’ll go through a quick introduction to these sensors, pinout, wiring diagram, and finally the Arduino sketch.

![ESP32 with DHT11 DHT22 Temperature and Humidity Sensor using Arduino IDE](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/ESP32-with-DHT11DHT22-Temperature-and-Humidity-Sensor-using-Arduino-IDE.jpg?resize=828%2C466&quality=100&strip=all&ssl=1)

Learn how to display temperature and humidity readings on a web server using the ESP32 or ESP8266 boards:


## DHT11 and DHT22 Temperature and Humidity Sensors

The DHT11 and DHT22 sensors are used to measure temperature and relative humidity. These are very popular among makers and electronics hobbyists.

![DHT11/DHT22 Temperature and Humidity Sensor using Arduino IDE](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/DHT11-DHT22-Temperature-Humidity-Sensor.jpg?resize=750%2C442&quality=100&strip=all&ssl=1)

These sensors contain a chip that does analog to digital conversion and spit out a digital signal with the temperature and humidity. This makes them very easy to use with any microcontroller.

If you’re looking to use these sensors with the Arduino board, you can read the following tutorial:

-   [Guide for DHT11/DHT22 Humidity and Temperature Sensor with Arduino](https://randomnerdtutorials.com/complete-guide-for-dht11dht22-humidity-and-temperature-sensor-with-arduino/)

### DHT11 vs DHT22

The DHT11 and DHT22 are very similar, but differ in their specifications. The following table compares some of the most important specifications of the DHT11 and DHT22 temperature and humidity sensors. For a more in-depth analysis of these sensors, please check the sensors’ datasheet.

|   | **DHT11** | **DHT22** |
|---|---|---|
|**Temperature range**| 0 to 50 ºC  +/-2 ºC  | -40 to 80 ºC  +/-0.5ºC |
|   | ![](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/dht11_bb.png?resize=40%2C57&quality=100&strip=all&ssl=1)  |  ![](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/dht22_bb.png?resize=40%2C57&quality=100&strip=all&ssl=1) |
|**Humidity range** | 20 to 90%  +/-5%| 0 to 100%  +/-2%|


The DHT22 sensor has a better resolution and a wider temperature and humidity measurement range. However, it is a bit more expensive, and you can only request readings with 2 seconds interval.

The DHT11 has a smaller range and it’s less accurate. However, you can request sensor readings every second. It’s also a bit cheaper.

Despite their differences, they work in a similar way, and you can use the same code to read temperature and humidity. You just need to select in the code the sensor type you’re using.

## DHT Pinout

DHT sensors have four pins as shown in the following figure. However, if you get your DHT sensor in a breakout board, it comes with only three pins and with an internal pull-up resistor on pin 2.

![DHT22 Temperature and Humidity Sensor using Arduino IDE](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/dht22-pinout.png?resize=138%2C300&quality=100&strip=all&ssl=1)

The following table shows the DHT22/DHT11 pinout. When the sensor is facing you, pin numbering starts at 1 from left to right

**DHT pin**

**Connect to**

**1** -3.3V

**2**-Any digital GPIO; also connect a 10k Ohm pull-up resistor

**3**-Don’t connect

**4**-GND

## Parts Required

To follow this tutorial you need to wire the DHT11 or DHT22 temperature sensor to the ESP32. You need to use a 10k Ohm pull-up resistor.

Here’s a list of parts you need to build the circuit:

-   [ESP32](https://makeradvisor.com/tools/esp32-dev-board-wi-fi-bluetooth/)  (read  [Best ESP32 development boards](https://makeradvisor.com/esp32-development-boards-review-comparison/))
-   [DHT11](https://makeradvisor.com/tools/dht11-temperature-humidity-sensor/) or  [DHT22](https://makeradvisor.com/tools/dht22-temperature-humidity-sensor/) temperature and humidity sensor
-   [10k Ohm resistor](https://makeradvisor.com/tools/resistors-kits/)
-   [Breadboard](https://makeradvisor.com/tools/mb-102-solderless-breadboard-830-points/)
-   [Jumper wires](https://makeradvisor.com/tools/jumper-wires-kit-120-pieces/)


## Schematic Diagram

Wire the DHT22 or DHT11 sensor to the ESP32 development board as shown in the following schematic diagram.

![ESP32 with DHT11/DHT22 Temperature and Humidity Sensor using Arduino IDE](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/dht_esp32_bb.png?resize=714%2C892&quality=100&strip=all&ssl=1)

In this example, we’re connecting the DHT data pin to  GPIO 4. However, you can use any other suitable digital pin.

Learn how to use the ESP32 GPIOs with our guide:  [ESP32 Pinout Reference: Which GPIO pins should you use?](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/)

## Installing Libraries

To read from the DHT sensor, we’ll use the  [DHT library from Adafruit](https://github.com/adafruit/DHT-sensor-library). To use this library you also need to install the  [Adafruit Unified Sensor library](https://github.com/adafruit/Adafruit_Sensor). Follow the next steps to install those libraries.

Open your Arduino IDE and go to  **Sketch** >  **Include Library**  >  **Manage Libraries**. The Library Manager should open.

Search for “**DHT**” on the Search box and install the DHT library from Adafruit.

![Installing Adafruit DHT library](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/adafruit_dht_library.png?resize=750%2C422&quality=100&strip=all&ssl=1)

After installing the DHT library from Adafruit, type “**Adafruit Unified Sensor**” in the search box. Scroll all the way down to find the library and install it.

![Installing Adafruit Unified Sensor driver library](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/adafruit_unified_sensor_library.png?resize=750%2C422&quality=100&strip=all&ssl=1)

After installing the libraries, restart your Arduino IDE.

## ESP32 Reading Temperature and Humidity Sketch

To read temperature and humidity from the DHT sensor, we’ll use an example based on the Adafruit DHT library. Copy the following code to your Arduino IDE.

```c
// Example testing sketch for various DHT humidity/temperature sensors written by ladyada
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}

```

[View raw code](https://github.com/RuiSantosdotme/Random-Nerd-Tutorials/raw/master/Projects/Arduino/ESP32_DHTtester.ino)

There are many comments throughout the code with useful information. So, you might want to take a look at the comments. Continue reading to learn how the code works.

## How the Code Works

First, you need to import the  DHT  library:

```c
#include "DHT.h"
```

Then, define the digital pin that the DHT sensor data pin is connected to. In this case, it’s connected to  GPIO 4.

```c
#define DHTPIN 4     // Digital pin connected to the DHT sensor
```

Then, you need to select the DHT sensor type you’re using. The library supports DHT11, DHT22, and DHT21. Uncomment the sensor type you’re using and comment all the others. In this case, we’re using the DHT22 sensor.

```c
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
```

Create a  DHT  object called  dht  on the pin and with the sensor type you’ve specified previously.

```c
DHT dht(DHTPIN, DHTTYPE);
```

In the  setup(), initialize the Serial debugging at a baud rate of 9600, and print a message in the Serial Monitor.

```c
Serial.begin(9600);
Serial.println(F("DHTxx test!"));
```

Finally, initialize the DHT sensor.

```c
dht.begin();
```

The  loop()  starts with a 2000 ms (2 seconds) delay, because the DHT22 maximum sampling period is 2 seconds. So, we can only get readings every two seconds.

```c
delay(2000);
```

The temperature and humidity are returned in float format. We create float variables  h,  t, and  f  to save the humidity, temperature in Celsius and temperature in Fahrenheit, respectively.

Getting the humidity and temperature is as easy as using the  readHumidity()  and  readTemperature()  methods on the  dht  object, as shown below:

```c
float h = dht.readHumidity();
// Read temperature as Celsius (the default)
float t = dht.readTemperature();
```

If you want to get the temperature in Fahrenheit degrees, you need to pass the  true  parameter as argument to the  readTemperature()  method.

```c
float f = dht.readTemperature(true);
```

There’s also an if statement that checks if the sensor returned valid temperature and humidity readings.

```c
if (isnan(h) || isnan(t) || isnan(f)) {
   Serial.println(F("Failed to read from DHT sensor!"));
   return;
```

After getting the humidity and temperature, the library has a method that computes the heat index. You can get the heat index both in Celsius and Fahrenheit as shown below:

```c
// Compute heat index in Fahrenheit (the default)
float hif = dht.computeHeatIndex(f, h);
// Compute heat index in Celsius (isFahreheit = false)
float hic = dht.computeHeatIndex(t, h, false);
```

Finally, print all the readings on the Serial Monitor with the following commands:

```c
Serial.print(F("Humidity: "));
Serial.print(h);
Serial.print(F("%  Temperature: "));
Serial.print(t);
Serial.print(F("°C "));
Serial.print(f);
Serial.print(F("°F  Heat index: "));
Serial.print(hic);
Serial.print(F("°C "));
Serial.print(hif);
Serial.println(F("°F"));
```

## Demonstration

Upload the code to your ESP32 board. Make sure you have the right board and COM port selected in your Arduino IDE settings.

After uploading the code, open the Serial Monitor at a baud rate of 9600. You should get the latest temperature and humidity readings in the Serial Monitor every two seconds.

![ESP32 DHT11 DHT22 AM2302 AM2301 read temperature humidity sensor](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/temperature_humidity_readings_dht_esp32.png?resize=726%2C376&quality=100&strip=all&ssl=1)