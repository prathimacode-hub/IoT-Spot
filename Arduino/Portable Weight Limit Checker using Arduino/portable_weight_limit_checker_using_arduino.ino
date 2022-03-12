void setup()
{
  pinMode(9, OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue=analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue>300)
    digitalWrite(9,HIGH);
  else
    digitalWrite(9,LOW);
}