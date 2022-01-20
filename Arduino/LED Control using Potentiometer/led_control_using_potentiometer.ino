void setup()
{
  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);                 //reading value of voltage across potentiometer
  int ledValue = map(value, 0, 1024, 0, 255); //converting value to suitable format
  analogWrite(LED_BUILTIN, ledValue);         //giving modified value as input to the led
}