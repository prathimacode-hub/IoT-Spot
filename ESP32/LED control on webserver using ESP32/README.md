# ESP32 Web Server in Arduino IDE: Control LEDs

In this tutorial, we will learn to create a simple web server with ESP32 using Arduino IDE. This ESP32 web server controls GPIO pins or LEDs whenever it receives an HTTP GET request from a web client ( web browser). To access the web server, ESP32 should be connected with the same WiFi network to which your mobile or computer is connected.

[![ESP32 Web server demo](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-Web-server-demo-1024x485.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-Web-server-demo.jpg)

## Setting up Arduino IDE

We will be using Arduino IDE to program our ESP32 development board. Before we move ahead, make sure you have the latest version of Arduino installed on your computer. Moreover, you should also have an ESP32 add-on in Arduino IDE. You can check this tutorial:

## ESP32 Web Server Project Overview

You will learn the following in this ESP32 web server tutorial:

-   Learn to make a web server using ESP32 and Arduino IDE
-   How to make a web server to control LEDs from a local network using an ESP32
-   What is a web server? How to use ESP32 as a Web server
-   How an ESP32 web server can serve HTML, CSS, and Javascript files to web clients by acting as a server.

## Introducing Web server?

When we talk about web server in the context of the internet of things, the web server is nothing but the location where our website files stores and Web server process these files to clients based on the request of a client. Website files are web pages of any site. Like you are using this website to read an article on how to make an EPS32 web server, this webpage is stored in a server of our hosting company. So when you click on the link to open this article, you request a client to a server of our hosting company.

After receiving this particular page request, our hosting company server processes this request to display this webpage. Similarly, we can use ESP32 as a host for storing web pages, and when someone requests a web page through a local network, esp32 will serve this webpage. The picture below provides a view of client-server based communication.

[![client and server](https://microcontrollerslab.com/wp-content/uploads/2019/03/client-and-server.png)](https://microcontrollerslab.com/wp-content/uploads/2019/03/client-and-server.png)

### Web Serve and Client Communication

This is a basic idea of server and client-based communication over the internet. Now the question is how can we establish communication between client and Web server? HTTP which is also known as hypertext transfer control is a protocol that is used to transfer data between the web client and Web server. The web server in this tutorial will be ESP32 and the web client will be any web browser or Android application. Whenever a web client needs to access any web files, it starts an HTTP GET request to the web server.

### How Does a Web Server respond to a Client Request?

After receiving HTTP GET request, the server responds with web pages. The web server also responds through the HTTP protocol. If web files are not available on Server or it is down due to some technical reasons, you will see a message of error 404 on the web browser. In the above figure, there is only one client and one server. But a server can connect to multiple web clients and service requests through HTTP protocol. Web server is also known as Server host which listen to other web clients and service the requests.

## ESP32 modes of operations

Many people think that It can be used as station mode only where it can connect to an existing network. But This WiFi module has very important features to use a soft access point mode, station mode and both modes at the same time. In this tutorial, I will talk about station mode only. In the next tutorials, I will also write about how to use this board in soft access mode. Lets now see the difference between the station mode and the soft access mode.

### Station mode or STA

In this mode, ESP32 board connects to your WiFi network through a router. So the medium of communication between the web client and ESP32 is the router. It gets the IP address from the Wifi router. With this IP address, web clients can access the Web server through an existing local network.

![ESP32 ESP8266 station mode](https://microcontrollerslab.com/wp-content/uploads/2021/04/ESP32-ESP8266-station-mode.jpg)

### Soft access point mode

In this mode, ESP32 used to create its own wireless WiFi network similar to your existing WiFi router. In this mode, we do not need to connect ESP2 to WiFi network. Up to 5 devices can connect to this Wifi network created by this WiFi board.


![ESP32 ESP8266 Soft access point](https://microcontrollerslab.com/wp-content/uploads/2021/04/ESP32-ESP8266-Soft-access-point.jpg)

## How to use ESP32 as a Web Server in station mode

So now I will explain how to it as a station mode to create a web server. We can turn any computer windows or Linux into a web server. But your computer should remain connected to the internet all the time. Similarly, we can use the ESP32 development board as a host server.

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-webserver-as-server-host.jpg)

### Getting IP Address

We can have multiple clients and a single host server like ESP32 or any IOT development board. So now the question is how a web client can access the ESP32 based web server? When we connect any device to the network, the IP address is assigned to it. So we can use this assigned IP address to refer to this device. For example, when we connect ESP32 development board to network, the IP address will be given to it. We will use this IP address to access the ESP32 server over the web browser.

[![ESP32 IP address](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-IP-address.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-IP-address.jpg)

### How to Access the Web Page?

To access ESP32 web pages, we need to get its IP address which is assigned to it when it connects to the internet. In the programming part, I will show you how to get its IP address.

After getting the IP address, simply place it in a web browser, you will get the response from the ESP32 host server. For example, the web files which we stored in ESP32 are like the one shown below. It will show this web file in your web browser.

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-webserver-web-page.jpg)

Uptill now, we have learned about web server and how ESP32 can be used as web server.

## ESP32 Web Server To Control GPIOs

Now we see how to control three light-emitting diodes or LEDs over a web server. We can access this server on any web browser installed on the personal computer, laptop, mobile device or tablet. Now we will be controlling two LEDs through a web browser. We will be using three light emitting diodes in this tutorial. Now make this schematic shown below on breadboard. Connection diagram shows which general-purpose input-output pins we have used. But you can use any GPIO pin you want. Remember this tutorial is for demonstration only, in the actual project, you will use  [relays](https://microcontrollerslab.com/electromechanical-relays-interfacing-with-microcontrollers/)  to control ac devices, like  [home automation project](https://microcontrollerslab.com/ethernet-based-home-automation-project/). Project on home automation will also be published on our blog in the coming article.

### Schematic Diagram

[![ESP32 web server controlling LEDs circuit diagram](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-web-server-controlling-LEDs-circuit-diagram-1024x452.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-web-server-controlling-LEDs-circuit-diagram.jpg)

### Components list

To make this schematic, you will need the following components :

-   Breadboard
-   ESP32 board ( we are using ESP32 devkit DOIT 30 pin version)
-   three 100 ohm resistors
-   Jumper wires
-   3 LEDs

In the schematic, we are using GPIO pins 15, 22, and 23 as digital output pins. These pins are connected with  light-emitting diodes through current limiting resistors. For more information about how to interface LED with this board, you can check  LED blinking with ESP32 article. LED1 is connected with GPIO pin 23. LED2 is connected with GPIO pin 22 and LED3 is connected with GPIO pin fifteen.

### ESP32 Web server Arduino Code

Now, let’s move to the main part of the ESP32 web server tutorial, the programming section. Remember in this tutorial we are using this Wifi module in station mode. This Arduino code controls three LEDs with separate on and off buttons. After building the circuit diagram upload this code to Arduino IDE.

```c
#include <WiFi.h>

const char* WIFI_NAME= "PTCL-BB"; 
const char* WIFI_PASSWORD = "5387c614"; 
WiFiServer server(80);

String header;

String LED_ONE_STATE = "off";
String LED_TWO_STATE = "off";
String LED_THREE_STATE = "off";


const int GPIO_PIN_NUMBER_22 = 22;
const int GPIO_PIN_NUMBER_23 = 23;
const int GPIO_PIN_NUMBER_15 = 15;


void setup() {
Serial.begin(115200);
pinMode(GPIO_PIN_NUMBER_22, OUTPUT);
pinMode(GPIO_PIN_NUMBER_23, OUTPUT);
pinMode(GPIO_PIN_NUMBER_15, OUTPUT);

digitalWrite(GPIO_PIN_NUMBER_22, LOW);
digitalWrite(GPIO_PIN_NUMBER_23, LOW);
digitalWrite(GPIO_PIN_NUMBER_15, LOW);


Serial.print("Connecting to ");
Serial.println(WIFI_NAME);
WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print("Trying to connect to Wifi Network");
}
Serial.println("");
Serial.println("Successfully connected to WiFi network");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin();
}

void loop(){
WiFiClient client = server.available(); 
if (client) { 
Serial.println("New Client is requesting web page"); 
String current_data_line = ""; 
while (client.connected()) { 
if (client.available()) { 
char new_byte = client.read(); 
Serial.write(new_byte); 
header += new_byte;
if (new_byte == '\n') { 
         
if (current_data_line.length() == 0) 
{
            
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();
            
if (header.indexOf("LED0=ON") != -1) 
{
Serial.println("GPIO23 LED is ON");
LED_ONE_STATE = "on";
digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
} 
if (header.indexOf("LED0=OFF") != -1) 
{
Serial.println("GPIO23 LED is OFF");
LED_ONE_STATE = "off";
digitalWrite(GPIO_PIN_NUMBER_22, LOW);
} 
if (header.indexOf("LED1=ON") != -1)
{
Serial.println("GPIO23 LED is ON");
LED_TWO_STATE = "on";
digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
}
if (header.indexOf("LED1=OFF") != -1) 
{
Serial.println("GPIO23 LED is OFF");
LED_TWO_STATE = "off";
digitalWrite(GPIO_PIN_NUMBER_23, LOW);
}
if (header.indexOf("LED2=ON") != -1) 
{
Serial.println("GPIO15 LED is ON");
LED_THREE_STATE = "on";
digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
}
if(header.indexOf("LED2=OFF") != -1) {
Serial.println("GPIO15 LED is OFF");
LED_THREE_STATE = "off";
digitalWrite(GPIO_PIN_NUMBER_15, LOW);
}
            
client.println("<!DOCTYPE html><html>");
client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
client.println("<link rel=\"icon\" href=\"data:,\">");
client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
client.println(".button { background-color: #4CAF50; border: 2px solid #4CAF50;; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; }");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}"); 
// Web Page Heading
client.println("</style></head>");
client.println("<body><center><h1>ESP32 Web server LED controlling example</h1></center>");
client.println("<center><h2>Web Server Example Microcontrollerslab.com</h2></center>" );
client.println("<center><h2>Press on button to turn on led and off button to turn off LED</h3></center>");
client.println("<form><center>");
client.println("<p> LED one is " + LED_ONE_STATE + "</p>");
// If the PIN_NUMBER_22State is off, it displays the ON button 
client.println("<center> <button class=\"button\" name=\"LED0\" value=\"ON\" type=\"submit\">LED0 ON</button>") ;
client.println("<button class=\"button\" name=\"LED0\" value=\"OFF\" type=\"submit\">LED0 OFF</button><br><br>");
client.println("<p>LED two is " + LED_TWO_STATE + "</p>");
client.println("<button class=\"button\" name=\"LED1\" value=\"ON\" type=\"submit\">LED1 ON</button>");
client.println("<button class=\"button\" name=\"LED1\" value=\"OFF\" type=\"submit\">LED1 OFF</button> <br><br>");
client.println("<p>LED three is " + LED_THREE_STATE + "</p>");
client.println ("<button class=\"button\" name=\"LED2\" value=\"ON\" type=\"submit\">LED2 ON</button>");
client.println ("<button class=\"button\" name=\"LED2\" value=\"OFF\" type=\"submit\">LED2 OFF</button></center>");
client.println("</center></form></body></html>");
client.println();
break;
} 
else 
{ 
current_data_line = "";
}
} 
else if (new_byte != '\r') 
{ 
current_data_line += new_byte; 
}
}
}
// Clear the header variable
header = "";
// Close the connection
client.stop();
Serial.println("Client disconnected.");
Serial.println("");
}
}
```

### Uploading Code to ESP32

Follow these steps to upload code after copying this code to Arduino IDE.

-   First of all, you need to add the name of your WiFi network and password to the following two lines:

```c
const char* WIFI_NAME= "Enter your WiFi name here"; 
const char* WIFI_PASSWORD = "Enter password of WiFi here";
```

You don’t need to make any other changes in the code. Now first compile your code by clicking on the verify button on the Arduino IDE. ESP32 codes usually take more time to compile than other microcontrollers, so don’t worry about it and wait for a while. After it’s done with compilation, it will show the following message in the compilation window.

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-webserver-code-compilation.jpg)

Now click on upload button to upload this code into ESP32 WROOM chip.

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/UPLOAD-BUTTON-ARDUINO-IDE.jpg)

Before uploading the program, make sure you should have select the right COM port to which your board is connected.

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/Selecting-COM-PORT-ESP32.jpg)

Also, you should select the ESP32 dev module from the tools and boards menu as shown below:

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-dev-module-selection-for-webserver.jpg)

After you see the message of done uploading on Arduino IDE, open the serial monitor by clicking on the serial monitor option. Select the baud rate of 115200 in the serial monitor window.

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/SERIAL-MONITOR-ARDUINO-IDE.jpg)

After the code will be upload successfully, you will see this message :

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/after-upload-ESP32-server-code.jpg)

### Getting IP address

Now, open the serial monitor and click on the reset button of the ESP32 dev kit board. you will see the message ” trying to connect to a WiFi network” and after some time you will see the message “successfully connected to WiFi network” and also the IP address as shown in the figure below:

![](https://microcontrollerslab.com/wp-content/uploads/2019/03/ESP32-webserver-IP-address.jpg)

### Accessing ESP32 Web Server

Now we will see how to open the web page which is stored in ESP32 board. To access the web server, paste the IP address which we noted in the last step in any web browser. You will find this web page in your browser.[![accessing ESP32 webserver](https://microcontrollerslab.com/wp-content/uploads/2019/03/accessing-ESP32-webserver-1024x549.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/accessing-ESP32-webserver.jpg)

### How ESP32 Web server works?

After accessing a web page through a web browser, you can check the serial monitor where you will see the web page HTTP GET request from a client over HTTP protocol. You will see this message on the serial monitor.

New Client is requesting web page
GET / HTTP/1.1
Host: 192.168.10.47
Connection: keep-alive
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.121 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8
Accept-Encoding: gzip, deflate
Accept-Language: en-US,en;q=0.9
AlexaToolbar-ALX_NS_PH: AlexaToolbar/alx-4.0.3

This is a message which defines the operating parameters for the transaction of an HTTP request by the client and for the service of the web page by the station. But we don’t need to worry about this. The actual concept which we need to understand is what happens when someone presses on/off buttons to trigger LED on and off. So now let’s see what happens on the browser and what message goes to the ESP32 board which we display on a serial monitor.

#### Controlling LEDs from web page

When you press an LED0 button, you will see that the IP address will now contain an additional text “/?LED0=ON” and this message will be sent to the ESP32 board. you will also see the message in the string “GET /?LED0=ON HTTP/1.1″ . So ESP32 will receive this request from the web client and turn on the LED0 which we specified in the code given above. I will explain this part in the section ” How code works”. you also notice the state of LED will be shown on the web page. Similarly, you can test other buttons and check the same response.

[![Webserver LED0 ON](https://microcontrollerslab.com/wp-content/uploads/2019/03/Webserver-LED0-ON-1024x846.jpg)](https://microcontrollerslab.com/wp-content/uploads/2019/03/Webserver-LED0-ON.jpg)

So you should follow these points while testing web server.

-   First, you should press each button and check if you see the same message in the URL and also on the serial monitor of Arduino IDE.
-   Also check, if the state of the LED message is changing according to the button you pressed on the web page.
-   Also see, if the respective LED is toggling according to the pressed button.

