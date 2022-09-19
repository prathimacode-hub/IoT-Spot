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