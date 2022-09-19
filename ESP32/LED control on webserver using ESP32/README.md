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

