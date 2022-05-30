
#include <ESP8266WiFi.h> //Include Libraries

WiFiClient client; // Calling function

WiFiServer server(80);

#define LED_Red D5 // defining red pin
#define LED_Yellow D6 // defining yellow pin
#define LED_Green D7 // defining green pin

void setup()
{

    Serial.begin(9600); // initialising serial port

    // WiFi.begin(Wifi SSID, Wifi Password);
    WiFi.begin("ABCD", "ABCD123");
    while (WiFi.status() != WL_CONNECTED) // running until connection is established

    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("NodeMCU is Connected");
    Serial.println(WiFi.localIP());
    server.begin();
    // setting led as output pins
    pinMode(LED_Red, OUTPUT);
    pinMode(LED_Yellow, OUTPUT);
    pinMode(LED_Green, OUTPUT);
}

void loop()
{

    client = server.available(); // checking for availability of server
    if (client == 1)
    {

        String request = client.readStringUntil('\n');
        Serial.println(request);
        request.trim();
        // requesting for red led's
        if (request == "GET /LED_Red HTTP/1.1")

        {

            digitalWrite(LED_Red, HIGH);
            digitalWrite(LED_Yellow, LOW);
            digitalWrite(LED_Green, LOW);
        }
        // requesting for yellow led's
        if (request == "GET /LED_Yellow HTTP/1.1")

        {

            digitalWrite(LED_Red, LOW);
            digitalWrite(LED_Yellow, HIGH);
            digitalWrite(LED_Green, LOW);
        }
        // requesting for green led's
        if (request == "GET /LED_Green HTTP/1.1")

        {

            digitalWrite(LED_Red, LOW);
            digitalWrite(LED_Yellow, LOW);
            digitalWrite(LED_Green, HIGH);
        }
    }
}
