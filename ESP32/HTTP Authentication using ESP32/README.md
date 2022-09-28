# ESP32/ESP8266 HTTP Authentication Web Server (Username and Password Protected)

In this tutorial, we will learn how to add HTTP authentication in our ESP32/ESP8266 web servers build with the ESPAsyncWebServer library. User can only access the web server with an IP address if he has a correct username and IP password.

![ESP32 ESP8266 HTTP Authentication Web Server](https://microcontrollerslab.com/wp-content/uploads/2021/06/ESP32-ESP8266-HTTP-Authentication-Web-Server.jpg)


## HTTP Authentication Introduction

As we have seen in our previous projects that the ESP32 and ESP8266 Web servers are accessible through an IP address which anyone can get access to. Therefore, password protection is extremely vital to make your webpage secure otherwise anyone can access your server.

If want to make your web server confidential by adding password login information, this tutorial will help you to add the password to your web server. It will make your web server protected and will be accessible through a password and user name only.

To make our project easy to understand, we will create a simple web server to control the onboard LED of ESP32/ESP8266 in Arduino IDE. Password protection and logout features will be included through HTTP authentication.