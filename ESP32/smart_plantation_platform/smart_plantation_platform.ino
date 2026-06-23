#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"
#include <Crypto.h>
#include <SHA256.h>
#include "time.h"   // ✅ Added for real-time date & time
#include <WebServer.h>  // ✅ For receiving manual/auto control updates
#include <ArduinoJson.h>  // ✅ For parsing JSON

// --- Wi-Fi Credentials ---
const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";

// --- Backend API URL ---
const char* serverName = "http://YOUR_SERVER_IP:5000/api/sensors"; 

// --- Sensors & Pins ---
#define DHTPIN 4
#define DHTTYPE DHT22
#define SOIL_PIN 34
#define RAIN_PIN 35
#define LDR_PIN 32
#define FLOAT_PIN 25
#define RELAY_PIN 12   // ✅ Relay control pin

DHT dht(DHTPIN, DHTTYPE);
SHA256 sha256;
String previousHash = "GENESIS";  // First block

// --- Time Config (for India GMT+5:30) ---
const long gmtOffset_sec = 19800;
const int daylightOffset_sec = 0;

// --- Pump Control Variables ---
bool pumpOn = false;          // manual mode pump
bool automationOn = false;    // auto mode toggle
int moistureThreshold = 2000; // threshold for automation
WebServer server(80);         // local control server

// --- Setup ---
void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(FLOAT_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // ✅ relay OFF initially (active HIGH)

  Serial.println("🌿 Smart Plantation Blockchain Logger Starting...");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // --- Initialize NTP Time ---
  configTime(gmtOffset_sec, daylightOffset_sec, "pool.ntp.org", "time.nist.gov");
  Serial.println("⏳ Syncing time with NTP...");
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("❌ Failed to obtain time");
  } else {
    Serial.println("✅ Time synchronized successfully!");
  }

  // ✅ Setup local API endpoint for control updates
  server.on("/control", HTTP_POST, []() {
    String body = server.arg("plain");
    StaticJsonDocument<256> doc;
    DeserializationError err = deserializeJson(doc, body);

    if (!err) {
      pumpOn = doc["pumpOn"];
      automationOn = doc["automationOn"];
    }

    Serial.println("\n--- Control Update Received ---");
    Serial.print("Automation: "); Serial.println(automationOn ? "ON" : "OFF");
    Serial.print("Manual Pump: "); Serial.println(pumpOn ? "ON" : "OFF");

    server.send(200, "text/plain", "Control Updated");
  });

  server.begin();
  Serial.println("🌐 Control endpoint ready at /control");
}

// --- Hash Generator ---
String calculateHash(String data) {
  sha256.reset();
  sha256.update((const uint8_t*)data.c_str(), data.length());

  uint8_t hashResult[32];
  sha256.finalize(hashResult, sizeof(hashResult));

  String hashString = "";
  for (int i = 0; i < 32; i++) {
    if (hashResult[i] < 16) hashString += "0";
    hashString += String(hashResult[i], HEX);
  }
  return hashString;
}

// --- Main Loop ---
void loop() {
  server.handleClient(); // ✅ Handle control requests

  // Read sensors
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soil = analogRead(SOIL_PIN);
  int rain = analogRead(RAIN_PIN);
  int light = analogRead(LDR_PIN);
  int waterLevel = digitalRead(FLOAT_PIN);

  // --- Pump Logic (✅ Active HIGH) ---
  if (automationOn) {
    if (soil > moistureThreshold) {
      digitalWrite(RELAY_PIN, HIGH);  // ✅ turn pump ON
      Serial.println("🌧 Soil dry → Pump ON");
    } else {
      digitalWrite(RELAY_PIN, LOW);   // ✅ turn pump OFF
      Serial.println("💧 Soil wet → Pump OFF");
    }
  } else {
    digitalWrite(RELAY_PIN, pumpOn ? HIGH : LOW);  // ✅ manual mode
  }

  // --- Get Real-Time Date & Time ---
  struct tm timeinfo;
  char dateStr[20], timeStr[20];
  if (getLocalTime(&timeinfo)) {
    strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &timeinfo);
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);
  } else {
    strcpy(dateStr, "Unknown");
    strcpy(timeStr, "Unknown");
  }

  // Combine readings for hash generation
  String dataString = "Temp:" + String(temp) +
                      ",Hum:" + String(hum) +
                      ",Soil:" + String(soil) +
                      ",Rain:" + String(rain) +
                      ",Light:" + String(light) +
                      ",Water:" + String(waterLevel) +
                      ",PrevHash:" + previousHash;

  String currentHash = calculateHash(dataString);

  // Print all data
  Serial.println("---- Sensor Readings ----");
  Serial.printf("Temperature: %.2f °C\n", temp);
  Serial.printf("Humidity: %.2f %%\n", hum);
  Serial.printf("Soil Moisture: %d\n", soil);
  Serial.printf("Rain Intensity: %d\n", rain);
  Serial.printf("Light Intensity: %d\n", light);
  Serial.printf("Water Level: %s\n", waterLevel ? "HIGH" : "LOW");
  Serial.println("Previous Hash: " + previousHash);
  Serial.println("Current Hash:  " + currentHash);
  Serial.printf("Date: %s  Time: %s\n", dateStr, timeStr);
  Serial.println("--------------------------\n");

  // --- Create JSON data for MongoDB schema ---
  String jsonData = "{";
  jsonData += "\"Soil Moisture\":" + String(soil) + ",";
  jsonData += "\"Temperature\":" + String(temp) + ",";
  jsonData += "\"Humidity\":" + String(hum) + ",";
  jsonData += "\"Light Intensity\":" + String(light) + ",";
  jsonData += "\"Water Level\":" + String(waterLevel) + ",";
  jsonData += "\"Rain\":" + String(rain) + ",";
  jsonData += "\"Previous Hash\":\"" + previousHash + "\",";
  jsonData += "\"Current Hash\":\"" + currentHash + "\",";
  jsonData += "\"Date\":\"" + String(dateStr) + "\",";
  jsonData += "\"Time\":\"" + String(timeStr) + "\"";
  jsonData += "}";

  // --- Send Data to Server ---
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      Serial.printf("📤 Data sent! Response Code: %d\n", httpResponseCode);
      String response = http.getString();
      Serial.println("Server Response: " + response);
    } else {
      Serial.printf("❌ Failed to send data. Error: %s\n", http.errorToString(httpResponseCode).c_str());
    }

    http.end();
  } else {
    Serial.println("⚠️ WiFi Disconnected!");
  }

  // Update previous hash
  previousHash = currentHash;

  delay(5000);  // Send every 5 seconds
}
