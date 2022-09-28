#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>



// Replace with your network credentials
const char* ssid = "PTCL-BB";
const char* password = "44332211";

const char* http_username = "admin";
const char* http_password = "admin";

const char* PARAM_INPUT_1 = "state";

const int output = 2;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

 
// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if(var == "BUTTONPLACEHOLDER"){
    String buttons ="";
    String outputStateValue = outputState();
    buttons+= "<p><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"output\" " + outputStateValue + "><span class=\"slider\"></span></label></p>";
    return buttons;
  }
  if (var == "STATE"){
    if(digitalRead(output)){
      return "ON";
    }
    else {
      return "OFF";
    }
  }
  return String();
}

String outputState(){
  if(digitalRead(output)){
    return "checked";
  }
  else {
    return "";
  }
  return "";
}