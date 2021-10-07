int led1=5;
int led2=6;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT); //to initialise 5th pin as output
  pinMode(led2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1,HIGH); //sets the pin at 5V
  digitalWrite(led2,LOW); 
  delay(1000); 
  digitalWrite(led1,LOW); //sets the pin to 0V
  digitalWrite(led2,HIGH); 
  delay(1000);

}