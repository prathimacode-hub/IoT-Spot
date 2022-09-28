# ESP32/ESP8266 HTTP Authentication Web Server (Username and Password Protected)

In this tutorial, we will learn how to add HTTP authentication in our ESP32/ESP8266 web servers build with the ESPAsyncWebServer library. User can only access the web server with an IP address if he has a correct username and IP password.

![ESP32 ESP8266 HTTP Authentication Web Server](https://microcontrollerslab.com/wp-content/uploads/2021/06/ESP32-ESP8266-HTTP-Authentication-Web-Server.jpg)


## HTTP Authentication Introduction

As we have seen in our previous projects that the ESP32 and ESP8266 Web servers are accessible through an IP address which anyone can get access to. Therefore, password protection is extremely vital to make your webpage secure otherwise anyone can access your server.

If want to make your web server confidential by adding password login information, this tutorial will help you to add the password to your web server. It will make your web server protected and will be accessible through a password and user name only.

To make our project easy to understand, we will create a simple web server to control the onboard LED of ESP32/ESP8266 in Arduino IDE. Password protection and logout features will be included through HTTP authentication.

## Prerequisites

You should have the latest version of Arduino IDE. Additionally, you also need to install the ESP32 and the ESP8266 plugin. If your IDE does not have the plugins installed you can visit the link below:


Moreover, you can also have a look at previously uploaded tutorials regarding webservers in ESP32/ESP8266 using Arduino IDE.

## Project Overview – HTTP Authentication Web Server

In this tutorial, we will add password protection to an asynchronous web server. The webserver will consist of a title ESP WEB SERVER, a logout button, text representing the state of the onboard LED and a sliding button to toggle the LED.

![ESP32 ESP8266 HTTP Authentication Web Server (Username and Password Protected)](https://microcontrollerslab.com/wp-content/uploads/2021/06/ESP32-ESP8266-HTTP-Authentication-Web-Server-Username-and-Password-Protected.jpg)

-   Firstly, we will upload our Arduino sketch to our ESP board.
-   Then, we will receive an IP address in our serial monitor.
-   Secondly, we will copy that IP address in a web browser and press enter. Previously, without any password protection, the webserver would have loaded but not this time. This time we will receive a window that will ask for the username and password.
-   Upon entering the correct credentials, we will get access to the web page.
-   Inside the web page, you will also find a logout button. By clicking it you will be redirected to the logout page.
-   To access the webserver again you will need to log in again.
-   The web server can be accessed on multiple devices only through a correct set of user name and password.

![ESP password protected web page PROJECT OVERVIEW](https://microcontrollerslab.com/wp-content/uploads/2021/06/ESP-password-protected-web-page-PROJECT-OVERVIEW.png)

## Setting up Arduino IDE

### Installing ESPAsyncWebServer Library and Async TCP/ ESP Async TCP Library

We will need two libraries to build our web server.

-   ESPAsyncWebServer & AsyncTCP for ESP32.
-   ESPAsyncwebServer & ESPAsyncTCP for ESP8266.

The ESPAsyncWebServer library will help us in creating our web server easily. With this library, we will set up an asynchronous HTTP server. AsyncTCP (for ESP32 only) and ESPAsyncTCP (for ESP8266 only) library will also be incorporated as it a dependency for the ESPAsyncWebServer library. All of these libraries are not available in the Arduino library manager. Therefore, we will have to download and load them on our ESP32/ESP8266 board ourselves.

#### For ESP32 Only

-   To install the Async TCP library for free,  [click here to download](https://github.com/me-no-dev/AsyncTCP/archive/master.zip). You will download the library as a .zip folder which you will extract and rename as ‘AsyncTCP.’ Then, transfer this folder to the installation library folder in your Arduino IDE.


Likewise, you can also go to  **Sketch > Include Library > Add .zip Library** inside the IDE to add the libraries as well. After installation of the libraries, restart your IDE.