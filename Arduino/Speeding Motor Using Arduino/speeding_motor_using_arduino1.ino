int potentioPin = A0;
int motorPin = 9;
int potentioValue = 0;
int motorValue = 0;

void setup() {
 Serial.begin(9600);
}

void loop() {
 potentioValue = analogRead(potentioPin);  
 motorValue = map(potentioValue, 0, 1023, 0, 255);
 analogWrite(motorPin, motorValue);  
 Serial.print("potentiometer = " );     
 Serial.print(potentioValue);
 Serial.print(" motor value = ");
 Serial.println(motorValue);
 delay(2);    
}