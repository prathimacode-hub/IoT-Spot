# ESP32 - Temperature and Humidity measure using DHT22(Serial Monitor)

## [Simulation Link](https://wokwi.com/projects/342713692783116883)

## [Video Link](https://youtu.be/tDdL5urWvH4)

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

----
----

# ESP32 - Temperature and Humidity measure using DHT22(Web Server)
## [Video Link](https://youtu.be/tDdL5urWvH4)

In this project, you’ll learn how to build an asynchronous ESP32 web server with the DHT11 or DHT22 that displays temperature and humidity using Arduino IDE.

![ESP32 DHT11/DHT22 Web Server - Temperature and Humidity using Arduino IDE](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/ESP32-DHT11-DHT22-Web-Server-Arduino-IDE-featured-image-1.jpg?resize=828%2C466&quality=100&strip=all&ssl=1)

The web server we’ll build updates the readings automatically without the need to refresh the web page.

With this project you’ll learn:

-   How to read temperature and humidity from DHT sensors;
-   Build an asynchronous web server using the  [ESPAsyncWebServer library](https://github.com/me-no-dev/ESPAsyncWebServer);
-   Update the sensor readings automatically without the need to refresh the web page.

For a more in-depth explanation on how to use the DHT22 and DHT11 temperature and humidity sensors with the ESP32, read our complete guide:  [ESP32 with DHT11/DHT22 Temperature and Humidity Sensor using Arduino IDE](https://randomnerdtutorials.com/esp32-with-dht11-dht22-temperature-and-humidity-sensor-using-arduino-ide/)

## Watch the Video Tutorial

You can watch the video tutorial or keep reading this page for the written instructions.

## Asynchronous Web Server

To build the web server we’ll use the  [ESPAsyncWebServer library](https://github.com/me-no-dev/ESPAsyncWebServer)  that provides an easy way to build an asynchronous web server. Building an asynchronous web server has several advantages as mentioned in the library GitHub page, such as:

-   “Handle more than one connection at the same time”;
-   “When you send the response, you are immediately ready to handle other connections while the server is taking care of sending the response in the background”;
-   “Simple template processing engine to handle templates”;
-   And much more.

Take a look at the  [library documentation on its GitHub page](https://github.com/me-no-dev/ESPAsyncWebServer).

## Parts Required

![ESP32 DHT11 DHT22 Temperature and Humidity Arduino IDE Circuit Schematic](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/dht-web-server-esp32-circuit.jpg?resize=750%2C421&quality=100&strip=all&ssl=1)

To complete this tutorial you need the following parts:

-   [ESP32 development board](https://makeradvisor.com/tools/esp32-dev-board-wi-fi-bluetooth/) (read [ESP32 development boards comparison](https://makeradvisor.com/esp32-development-boards-review-comparison/))
-   [DHT22](https://makeradvisor.com/tools/dht22-temperature-humidity-sensor/) or [DHT11](https://makeradvisor.com/tools/dht11-temperature-humidity-sensor/) Temperature and Humidity Sensor
-   [4.7k Ohm Resistor](https://makeradvisor.com/tools/resistors-kits/)
-   [Breadboard](https://makeradvisor.com/tools/mb-102-solderless-breadboard-830-points/)
-   [Jumper wires](https://makeradvisor.com/tools/jumper-wires-kit-120-pieces/)

## Schematic

Before proceeding to the web server, you need to wire the DHT11 or DHT22 sensor to the ESP32 as shown in the following schematic diagram.

In this case, we’re connecting the data pin to  GPIO 27, but you can connect it to any other digital pin. You can use this schematic diagram for both DHT11 and DHT22 sensors.

[![ESP32 DHT11 DHT22 Temperature and Humidity Arduino IDE Circuit Schematic Diagram](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/ESP32-DHT-wiring_bb.png?resize=417%2C462&quality=100&strip=all&ssl=1)](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/ESP32-DHT-wiring_bb.png?quality=100&strip=all&ssl=1)

_(This schematic uses the ESP32 DEVKIT V1 module version with 36 GPIOs – if you’re using another model, please check the pinout for the board you’re using.)_

**Note:** if you’re using a module with a DHT sensor, it normally comes with only three pins. The pins should be labeled so that you know how to wire them. Additionally, many of these modules already come with an internal pull up resistor, so you don’t need to add one to the circuit.

## Installing Libraries

You need to install a couple of libraries for this project:

-   The  [DHT](https://github.com/adafruit/DHT-sensor-library)  and the  [Adafruit Unified Sensor Driver](https://github.com/adafruit/Adafruit_Sensor)  libraries to read from the DHT sensor.
-   [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)  and  [Async TCP](https://github.com/me-no-dev/AsyncTCP)  libraries to build the asynchronous web server.

Follow the next instructions to install those libraries:

**Installing the DHT Sensor Library**

To read from the DHT sensor using Arduino IDE, you need to install the  [DHT sensor library](https://github.com/adafruit/DHT-sensor-library). Follow the next steps to install the library.

1.  [Click here to download the DHT Sensor library](https://github.com/adafruit/DHT-sensor-library/archive/master.zip). You should have a .zip folder in your  _Downloads_ folder
2.  Unzip the .zip folder and you should get _DHT-sensor-library-master_ folder
3.  Rename your folder from DHT-sensor-library-master to  _DHT_sensor_
4.  Move the  _DHT_sensor_ folder to your Arduino IDE installation libraries folder
5.  Finally, re-open your Arduino IDE

**Installing the Adafruit Unified Sensor Driver**

You also need to install the  [Adafruit Unified Sensor Driver library](https://github.com/adafruit/Adafruit_Sensor)  to work with the DHT sensor. Follow the next steps to install the library.

1.  [Click here to download the Adafruit Unified Sensor library](https://github.com/adafruit/Adafruit_Sensor/archive/master.zip). You should have a .zip folder in your  _Downloads_ folder
2.  Unzip the .zip folder and you should get _Adafruit_sensor-master_ folder
3.  Rename your folder from Adafruit_sensor-master to _Adafruit_sensor_
4.  Move the  _Adafruit_sensor_  folder to your Arduino IDE installation libraries folder
5.  Finally, re-open your Arduino IDE

**Installing the ESPAsyncWebServer library**

Follow the next steps to install the [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) library:

1.  [Click here to download the ESPAsyncWebServer library](https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip). You should have a .zip folder in your Downloads folder
2.  Unzip the .zip folder and you should get  _ESPAsyncWebServer-master_  folder
3.  Rename your folder from ESPAsyncWebServer-master to  _ESPAsyncWebServer_
4.  Move the  _ESPAsyncWebServer_ folder to your Arduino IDE installation libraries folder

**Installing the Async TCP Library for ESP32**

The [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) library requires the [AsyncTCP](https://github.com/me-no-dev/AsyncTCP) library to work. Follow the next steps to install that library:

1.  [Click here to download the AsyncTCP library](https://github.com/me-no-dev/AsyncTCP/archive/master.zip). You should have a .zip folder in your Downloads folder
2.  Unzip the .zip folder and you should get  _AsyncTCP-master_  folder
3.  Rename your folder from AsyncTCP-master to  _AsyncTCP_
4.  Move the  _AsyncTCP_ folder to your Arduino IDE installation libraries folder
5.  Finally, re-open your Arduino IDE

## Code

We’ll program the ESP32 using Arduino IDE, so make sure you have the ESP32 add-on installed before proceeding:

-   [Install ESP32 Board in Arduino IDE (Windows, Mac, and Linux Instructions)](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

Open your Arduino IDE and copy the following code.

```c
/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

#define DHTPIN 27     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readDHTTemperature() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float t = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

String readDHTHumidity() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  }
  else {
    Serial.println(h);
    return String(h);
  }
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
  </style>
</head>
<body>
  <h2>ESP32 DHT Server</h2>
  <p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="dht-labels">Temperature</span> 
    <span id="temperature">%TEMPERATURE%</span>
    <sup class="units">&deg;C</sup>
  </p>
  <p>
    <i class="fas fa-tint" style="color:#00add6;"></i> 
    <span class="dht-labels">Humidity</span>
    <span id="humidity">%HUMIDITY%</span>
    <sup class="units">&percnt;</sup>
  </p>
</body>
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 10000 ) ;
</script>
</html>)rawliteral";

// Replaces placeholder with DHT values
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return readDHTTemperature();
  }
  else if(var == "HUMIDITY"){
    return readDHTHumidity();
  }
  return String();
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  dht.begin();
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTTemperature().c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readDHTHumidity().c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){
  
}

```

[View raw code](https://github.com/RuiSantosdotme/ESP32-Course/raw/master/code/WiFi_Web_Server_DHT/WiFi_Web_Server_DHT.ino)

Insert your network credentials in the following variables and the code will work straight away.

```c
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
```

## How the Code Works

In the following paragraphs we’ll explain how the code works. Keep reading if you want to learn more or jump to the Demonstration section to see the final result.

### Importing libraries

First, import the required libraries. The  WiFi,  ESPAsyncWebServerand the  ESPAsyncTCP  are needed to build the web server. The  Adafruit_Sensor  and the  DHTlibraries are needed to read from the DHT11 or DHT22 sensors.

```c
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <ESPAsyncTCP.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
```

### Setting your network credentials

Insert your network credentials in the following variables, so that the ESP32 can connect to your local network.

```c
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
```

### Variables definition

Define the GPIO that the DHT data pin is connected to. In this case, it’s connected to  GPIO 27.

```c
#define DHTPIN 27  // Digital pin connected to the DHT sensor
```

Then, select the DHT sensor type you’re using. In our example, we’re using the DHT22. If you’re using another type, you just need to uncomment your sensor and comment all the others.

```c
#define DHTTYPE DHT22   // DHT 22 (AM2302)
```

Instantiate a  DHTobject with the type and pin we’ve defined earlier.

```c
DHT dht(DHTPIN, DHTTYPE);
```

Create an  AsyncWebServerobject on port 80.

```c
AsyncWebServer server(80);
```

### Read Temperature and Humidity Functions

We’ve created two functions: one to read the temperature (readDHTTemperature()) and the other to read humidity (readDHTHumidity()).

```c
String readDHTTemperature() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float t = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) { 
    Serial.println("Failed to read from DHT sensor!");
    return "--";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}
```

Getting sensor readings is as simple as using the  readTemperature()  and  readHumidity()methods on the  dht  object.

```c
float t = dht.readTemperature();
```

```c
float h = dht.readHumidity();
```

We also have a condition that returns two dashes (–) in case the sensor fails to get the readings.

```c
if (isnan(t)) {
  Serial.println("Failed to read from DHT sensor!");
  return "--";
}
```

The readings are returned as string type. To convert a float to a string, use the  String()  function.

```c
return String(t);
```

By default, we’re reading the temperature in Celsius degrees. To get the temperature in Fahrenheit degrees, comment the temperature in Celsius and uncomment the temperature in Fahrenheit, so that you have the following:

```c
//float t = dht.readTemperature();
// Read temperature as Fahrenheit (isFahrenheit = true)
float t = dht.readTemperature(true);
```

### Building the Web Page

Proceeding to the web server page.

![ESP32 DHT11 DHT22 Temperature and Humidity web page](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/web-server-labeled.png?resize=600%2C534&quality=100&strip=all&ssl=1)

As you can see in the above figure, the web page shows one heading and two paragraphs. There is a paragraph to display the temperature and another to display the humidity. There are also two icons to style our page.

Let’s see how this web page is created.

All the HTML text with styles included is stored in the  index_html  variable. Now we’ll go through the HTML text and see what each part does.

The following  <meta>  tag makes your web page responsive in any browser.

```html
<meta name="viewport" content="width=device-width, initial-scale=1">
```

The  <link>  tag is needed to load the icons from the fontawesome website.

```html
<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
```

#### Styles

Between the  <style></style>  tags, we add some CSS to style the web page.

```html
<style>
  html {
    font-family: Arial;
    display: inline-block;
    margin: 0px auto;
    text-align: center;
  }
  h2 { font-size: 3.0rem; }
  p { font-size: 3.0rem; }
  .units { font-size: 1.2rem; }
  .dht-labels{
    font-size: 1.5rem;
    vertical-align:middle;
    padding-bottom: 15px;
  }
</style>
```

Basically, we’re setting the HTML page to display the text with Arial font in block without margin, and aligned at the center.

```css
html {
  font-family: Arial;
  display: inline-block;
  margin: 0px auto;
  text-align: center;
}
```

We set the font size for the heading (h2), paragraph (p) and the units(.units) of the readings.

```css
h2 { font-size: 3.0rem; }
p { font-size: 3.0rem; }
.units { font-size: 1.2rem; }
```

The labels for the readings are styled as shown below:

```css
dht-labels{
  font-size: 1.5rem;
  vertical-align:middle;
  padding-bottom: 15px;
}
```

All of the previous tags should go between the  <head>  and  </head>  tags. These tags are used to include content that is not directly visible to the user, like the  <meta>  , the  <link>  tags, and the styles.

#### HTML Body

Inside the  <body></body>  tags is where we add the web page content.

The  <h2></h2>  tags add a heading to the web page. In this case, the “ESP32 DHT server” text, but you can add any other text.

```html
<h2>ESP32 DHT Server</h2>
```

Then, there are two paragraphs. One to display the temperature and the other to display the humidity. The paragraphs are delimited by the  <p>  and  </p>  tags. The paragraph for the temperature is the following:

```html
<p>
  <i class="fas fa-thermometer-half" style="color:#059e8a;"</i> 
  <span class="dht-labels">Temperature</span> 
  <span id="temperature">%TEMPERATURE%</span>
  <sup class="units">°C</sup>
</p>
```

And the paragraph for the humidity is on the following snipet:

```html
<p>
  <i class="fas fa-tint" style="color:#00add6;"></i> 
  <span class="dht-labels">Humidity</span>
  <span id="humidity">%HUMIDITY%</span>
  <sup class="units">%</sup>
</p>
```

The  <i>  tags display the fontawesome icons.

#### How to display icons

To chose the icons, go to the  [Font Awesome Icons website](https://fontawesome.com/icons?d=gallery).

![Font Awesome Icons website](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/fontawesomepage.png?resize=750%2C476&quality=100&strip=all&ssl=1)

Search the icon you’re looking for. For example, “thermometer”.

![Font Awesome Icons website thermometer](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/fontawesome-thermometer.png?resize=750%2C476&quality=100&strip=all&ssl=1)

Click the desired icon. Then, you just need to copy the HTML text provided.

```html
<i class="fas fa-thermometer-half">
```

![Font Awesome Icons website thermometer half](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/fontawesome-thermometer-html.png?resize=750%2C476&quality=100&strip=all&ssl=1)

To chose the color, you just need to pass the style parameter with the color in hexadecimal, as follows:

```html
<i class="fas fa-tint" style="color:#00add6;"></i> 
```

Proceeding with the HTML text…

The next line writes the word “Temperature” into the web page.

```html
<span class="dht-labels">Temperature</span>
```

The TEMPERATURE text between % signs is a placeholder for the temperature value.

```html
<span id="temperature">%TEMPERATURE%</span>
```

This means that this  **%TEMPERATURE%**  text is like a variable that will be replaced by the actual temperature value from the DHT sensor. The placeholders on the HTML text should go between % signs.

Finally, we add the degree symbol.

```html
<sup class="units">°C</sup>
```

The  <sup></sup>  tags make the text superscript.

We use the same approach for the humidity paragraph, but it uses a different icon and the  **%HUMIDITY%**  placeholder.  

```html
<p>
  <i class="fas fa-tint" style="color:#00add6;"></i> 
  <span class="dht-labels">Humidity</span>
  <span id="humidity">%HUMIDITY%</span>
  <sup class="units">%</sup>
</p>
```

### Automatic Updates

Finally, there’s some JavaScript code in our web page that updates the temperature and humidity automatically, every 10 seconds.

Scripts in HTML text should go between the  <script></script>  tags.

```html
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 10000 ) ;
</script>
```

To update the temperature on the background, we have a  setInterval()  function that runs every 10 seconds.

Basically, it makes a request in the  _/temperature_  URL to get the latest temperature reading.

```javascript
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 10000 ) ;
```

When it receives that value, it updates the HTML element whose id is  temperature.

```javascript
if (this.readyState == 4 && this.status == 200) {
  document.getElementById("temperature").innerHTML = this.responseText;
}
```

In summary, this previous section is responsible for updating the temperature asynchronously. The same process is repeated for the humidity readings.

**Important:** since the DHT sensor is quite slow getting the readings, if you plan to have multiple clients connected to an ESP32 at the same time, we recommend increasing the request interval or remove the automatic updates.

### Processor

Now, we need to create the  processor()  function, that will replace the placeholders in our HTML text with the actual temperature and humidity values.

```c
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return readDHTTemperature();
  }
  else if(var == "HUMIDITY"){
    return readDHTHumidity();
  }
  return String();
}
```

When the web page is requested, we check if the HTML has any placeholders. If it finds the  **%TEMPERATURE%**  placeholder, we return the temperature by calling the  readDHTTemperature()  function created previously.

```c
if(var == "TEMPERATURE"){
  return readDHTTemperature();
}
```

If the placeholder is  **%HUMIDITY%**, we return the humidity value.

```c
else if(var == "HUMIDITY"){
  return readDHTHumidity();
}
```

### setup()

In the  setup(),  initialize the Serial Monitor for debugging purposes.

```c
Serial.begin(115200);
```

Initialize the DHT sensor.

```c
dht.begin();
```

Connect to your local network and print the ESP32 IP address.

```c
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.println("Connecting to WiFi..");
}
```

Finally, add the next lines of code to handle the web server.

```c
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/html", index_html, processor);
});
server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", readDHTTemperature().c_str());
});
server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", readDHTHumidity().c_str());
});
```

When we make a request on the root URL, we send the HTML text that is stored on the  index_html  variable. We also need to pass the  processorfunction, that will replace all the placeholders with the right values.

```c
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/html", index_html, processor);
});
```

We need to add two additional handlers to update the temperature and humidity readings. When we receive a request on the  _/temperature_  URL, we simply need to send the updated temperature value. It is plain text, and it should be sent as a char, so, we use the  c_str()  method.

```c
server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", readDHTTemperature().c_str());
});
```

The same process is repeated for the humidity.

```c
server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/plain", readDHTHumidity().c_str());
});
```

Lastly, we can start the server.

```c
server.begin();
```

Because this is an asynchronous web server, we don’t need to write anything in the  loop().

```c
void loop(){

}
```

That’s pretty much how the code works.

## Upload the Code

Now, upload the code to your ESP32. Make sure you have the right board and COM port selected.

After uploading, open the Serial Monitor at a baud rate of 115200. Press the ESP32 reset button. The ESP32 IP address should be printed in the serial monitor.

![Upload the DHT11 DHT22 ESP32 Sketch Code Example](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/ESP32-DHT11-DHT22-Web-Server-Arduino-IDE.png?resize=764%2C577&quality=100&strip=all&ssl=1)

## Web Server Demonstration

Open a browser and type the ESP32 IP address. Your web server should display the latest sensor readings.

Notice that the temperature and humidity readings are updated automatically without the need to refresh the web page.

![ESP32 DHT11/DHT22 Web Server - Temperature and Humidity using Arduino IDE Demonstration](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/03/esp32-web-server-asynchronous-demonstration.jpg?resize=750%2C500&quality=100&strip=all&ssl=1)