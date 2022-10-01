

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
}

void loop() {
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(10, LOW);
  
  digitalWrite(11, HIGH);
  delay(500);
  digitalWrite(11, LOW);
 
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  
  digitalWrite(14, HIGH);
  delay(500);
  digitalWrite(14, LOW);
  
}
