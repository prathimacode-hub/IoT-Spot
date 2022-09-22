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

void setup() 
{
Serial.begin(115200); //define serial commuination with baud rate of 115200
ObjServo.attach(ServoGPIO); // it will attach the ObjServo to ServoGPIO pin which is 13 
Serial.print("Making connection to "); // it will display message on serial monitor
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
// These lines prints the IP address value on serial monitor 
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin(); // It will start the servo motor with given position value. 
}

void loop(){
WiFiClient client = server.available(); // Listen for incoming clients

if (client)
{ // If a new client connects,

String header = client.readStringUntil('\r');
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println("Connection: close");
client.println();

// Display the HTML web page
client.println("<!DOCTYPE html><html>");
client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
client.println("<link rel=\"icon\" href=\"data:,\">");
// CSS to style the on/off buttons 
// Feel free to change the background-color and font-size attributes to fit your preferences
client.println("<style>body { text-align: center; font-family: \"Trebuchet MS\", Arial; margin-left:auto; margin-right:auto;}");
client.println(".slider { width: 300px; }</style>");
client.println("<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>");

// Web Page
client.println("</head><body><h1>ESP32 with Servo</h1>");
client.println("<p>Position: <span id=\"servoPos\"></span></p>"); 
client.println("<input type=\"range\" min=\"0\" max=\"180\" class=\"slider\" id=\"servoSlider\" onchange=\"servo(this.value)\" value=\""+valueString+"\"/>");

client.println("<script>var slider = document.getElementById(\"servoSlider\");");
client.println("var servoP = document.getElementById(\"servoPos\"); servoP.innerHTML = slider.value;");
client.println("slider.oninput = function() { slider.value = this.value; servoP.innerHTML = this.value; }");
client.println("$.ajaxSetup({timeout:1000}); function servo(pos) { ");
client.println("$.get(\"/?value=\" + pos + \"&\"); {Connection: close};}</script>");

client.println("</body></html>"); 

//GET /?value=180& HTTP/1.1
if(header.indexOf("GET /?value=")>=0) 
{
positon1 = header.indexOf('=');
positon2 = header.indexOf('&');
valueString = header.substring(positon1+1, positon2);

//Rotate the servo
ObjServo.write(valueString.toInt());
Serial.println(valueString); 
} 

header = "";
client.stop();
Serial.println("Client disconnected.");
Serial.println("");
}
}