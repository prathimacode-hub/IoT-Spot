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

