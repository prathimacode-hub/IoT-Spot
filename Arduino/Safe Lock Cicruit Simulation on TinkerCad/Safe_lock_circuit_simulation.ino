#include<Servo.h>
Servo myServo;
int pass1;
int pass2;
int pass3;
int pass4;
String password;
String passwordCheck;
int buttonState=0;
int buttonStateCheck=0;
void setup(){
  myServo.attach(9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  
  Serial.begin(9600);
  myServo.write(0);
  while (buttonState==0){
  pass1=analogRead(A0);
  pass2=analogRead(A1);
  pass3=analogRead(A2);
  pass4=analogRead(A3);
  buttonState=digitalRead(3);
  Serial.print("ButtonState:");
  Serial.println(buttonState);
  }
  if (buttonState==1){
  password=String(pass1)+String(pass2)+String(pass3)+String(pass4);
  Serial.print("Password:");
  Serial.println(password);
  }
  
  
}

void loop()
{

  
  while (buttonStateCheck==0){
  pass1=analogRead(A0);
  pass2=analogRead(A1);
  pass3=analogRead(A2);
  pass4=analogRead(A3);
  buttonStateCheck=digitalRead(4);
  }
  
  Serial.println(buttonStateCheck);
  
  if (buttonStateCheck==1){
  passwordCheck=String(pass1)+String(pass2)+String(pass3)+String(pass4);
  Serial.print("Password Recheck:");
  Serial.println(passwordCheck);
  if (password==passwordCheck){
    myServo.write(180);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(8,LOW);
    
  }else{
    myServo.write(0);
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(8,HIGH);
  }
  }
  buttonStateCheck=0;
  
  
  
}
