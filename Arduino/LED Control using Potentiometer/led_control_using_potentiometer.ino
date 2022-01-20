void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int value=analogRead(A0);
  int ledValue=map(value,0,1024,0,255);
  analogWrite(LED_BUILTIN,ledValue);
}