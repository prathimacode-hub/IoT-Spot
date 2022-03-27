#include<IRremote.h>
int ldr=A0;
int ldr_value;
int RECV_PIN = 2;
int recv1=3;
int recv2=4;
IRrecv irrecv(RECV_PIN);
decode_results results;
IRrecv rec1(recv1);
IRrecv rec2(recv2);
decode_results rs1,rs2;
void setup()
{
  pinMode(ldr,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  irrecv.enableIRIn();
  rec1.enableIRIn();
  rec2.enableIRIn();
}
void loop()
{
  if(irrecv.decode(&results))
  {
    Serial.println(results.value,HEX);
    irrecv.resume();
  	long unsigned int g=results.value;
    ldr_value=analogRead(ldr);
  if(ldr_value<=512)
  {
    if(g==16582903)//(digitalRead(2)==HIGH&& digitalRead(3)==HIGH && digitalRead(4)==HIGH)
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
    }
    else if(g==16615543)//(digitalRead(2)==HIGH && digitalRead(3)==HIGH)
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
    }
    else if(g==16599223)//(digitalRead(3)==HIGH && digitalRead(4)==HIGH)
    {
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
    }
    else if(g==16591063)//(digitalRead(2)==HIGH && digitalRead(4)==HIGH)
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
    }
    else if(g==16623703)//(digitalRead(2)==HIGH)
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
    else if(g==16607383)//(digitalRead(3)==HIGH)
    {
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
    }
    else if(g==16586983)//(digitalRead(4)==HIGH)
    {
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
    }
    else if(g==16619623)
    {
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
  }
  else
  {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  
  }
  
}
