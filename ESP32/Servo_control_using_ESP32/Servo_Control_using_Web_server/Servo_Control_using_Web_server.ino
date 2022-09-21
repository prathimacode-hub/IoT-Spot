#include <WiFi.h> 
#include <Servo.h>

Servo ObjServo; // Make object of Servo motor from Servo library
// Objects are made for every servo motor,we want to control through this library

static const int ServoGPIO = 13; // define the GPIO pin with which servo is connected

// Variables to store network name and password
const char* ssid = "PTCL-BB"; // Enter your network name
const char* password = "5387c614"; //Enter your network password

// Set the server port nunber to deafualt 80
WiFiServer server(80);

// this variable header stores the HTTP requests data
String header;

// These variables used to store slider position 
String valueString = String(0);
int positon1 = 0;
int positon2 = 0;

