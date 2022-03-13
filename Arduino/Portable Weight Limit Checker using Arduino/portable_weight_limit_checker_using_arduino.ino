void setup()
{
  pinMode(9, OUTPUT); // Buzzer as output
  pinMode(A0, INPUT); // Taking analog input
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0); // Input of Force Sensor
  Serial.println(sensorValue);
  if (sensorValue > 300)
    digitalWrite(9, HIGH); // Turn on Buzzer
  else
    digitalWrite(9, LOW); // Turn off Buzzer
}