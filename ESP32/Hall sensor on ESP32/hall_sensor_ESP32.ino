int magnetic_value=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  magnetic_value=hallRead();
  Serial.print("ESP32 Hall effect sensor value value: ");
  Serial.println(magnetic_value);
  delay(2000);
}