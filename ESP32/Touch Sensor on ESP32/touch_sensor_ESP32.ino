#define LED_BuiltIn 2
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BuiltIn,OUTPUT);
  Serial.begin(115200);
  delay(1000); // stop the execution for 1 sec
  Serial.println("ESP32 Touch sensor value");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(touchRead(15));
  delay(1000);
  if (touchRead(15)<40)
  {
    digitalWrite(LED_BuiltIn,HIGH);
    delay(500);
    digitalWrite(LED_BuiltIn,LOW);
  }
}