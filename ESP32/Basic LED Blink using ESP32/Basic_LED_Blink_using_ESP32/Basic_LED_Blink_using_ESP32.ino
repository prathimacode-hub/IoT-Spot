void setup()
{
pinMode(22, OUTPUT); // Set GPIO22 as digital output pin
}

void loop() 
{
digitalWrite(22, HIGH); // Set GPIO22 active high
delay(1000);  // delay of one second
digitalWrite(22, LOW); // Set GPIO22 active low
delay(1000); // delay of one second
}
