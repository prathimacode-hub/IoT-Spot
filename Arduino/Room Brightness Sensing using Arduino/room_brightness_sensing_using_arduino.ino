int sensorPin = A0;  // initializing pin A0 as input for the photoresistor
int ledPin = 13;     // initializing pin 13 for the LED output
int sensorValue = 0; // variable to store the value coming from the sensor

void setup()
{
    // declare the ledPin as an OUTPUT:
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // read the value from the photoresistor:
    sensorValue = analogRead(sensorPin);
    // turn the ledPin on
    digitalWrite(ledPin, HIGH);
    // stop the program for <sensorValue> milliseconds:
    delay(sensorValue);
    // turn the ledPin off:
    digitalWrite(ledPin, LOW);
    // stop the program for for <sensorValue> milliseconds:
    delay(sensorValue);
}