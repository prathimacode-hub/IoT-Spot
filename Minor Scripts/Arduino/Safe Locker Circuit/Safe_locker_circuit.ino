#include<Servo.h>
Servo myServo; // creating an object of Servo class.
int pass1; // creating variable for getting the value from potentionmeter so that we can convert it into password.
int pass2;
int pass3;
int pass4;
String password; // creating variable for storing the password that we will set.
String passwordCheck; // creating variable for storing the password during rechecking.
int buttonState=0; // for buttonstate of password set button.
int buttonStateCheck=0; // for buttonstate of recheck password button.
void setup(){
  myServo.attach(9);
  pinMode(A0, INPUT); // intialzing every pin with there state is it for output or input.
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
  myServo.write(0); // setting the angle of shaft of servo motor at 0 degree.
  // This while loop run until we don't set the password and press the set password button.
  while (buttonState==0){
  pass1=analogRead(A0);
  pass2=analogRead(A1);
  pass3=analogRead(A2);
  pass4=analogRead(A3);
  buttonState=digitalRead(3);
  Serial.print("ButtonState:");
  Serial.println(buttonState);
  }
  // Once we set the password we will store in into password variable by type casting each value that we get from potentiometer.
  if (buttonState==1){
  password=String(pass1)+String(pass2)+String(pass3)+String(pass4);
  Serial.print("Password:");
  Serial.println(password);
  }
  
  
}

void loop()
{

  // This while loop run until we don't set the recheck password and press the recheck password button.
  while (buttonStateCheck==0){
  pass1=analogRead(A0);
  pass2=analogRead(A1);
  pass3=analogRead(A2);
  pass4=analogRead(A3);
  buttonStateCheck=digitalRead(4);
  }
  
  Serial.println(buttonStateCheck);
  // Once we set the recheck password we will store in into passwordCheck variable by type casting each value that we get from potentiometer.
  if (buttonStateCheck==1){
  passwordCheck=String(pass1)+String(pass2)+String(pass3)+String(pass4);
  Serial.print("Password Recheck:");
  Serial.println(passwordCheck);
  /* Here password and password will be compare to each other if it is true then green light will turn on and servo motor will rotate by 180 degree. If it false buzzer will sound
   ,red light will turn on and servo motor will rotate back and comes at 0 degree. */
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
