
//Include all libraries
#include<LiquidCrystal.h>
//Servo motor library
#include<Servo.h>
//defining pin 10 as servo pin
#define pinServo 10 
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo S1;//creating object for servo motor
int potPos1;         //BPM Potentiometer
int potPos2;         //Volume Potentiometer
int deg=0;           //initialize motor degree to '0'

void setup(){
  lcd.begin(16,2);//setting lcd display
  lcd.clear();//clearing lcd
  lcd.setCursor(3,0);//pointing cursor
  lcd.print("Emergency");
  lcd.setCursor(3,1);
  lcd.print("Ventilator");
  delay(1000);
  lcd.clear();
  S1.attach(pinServo);//setting servo pin
  Serial.begin(9600);//initializing serial port
  S1.write(0);           //setting 0 degree.
  delay(1000);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);   //setting pin for buzzer
}

void loop(){
  potPos1 = map(analogRead(A0), 0, 1023, 0, 100);//Read value for BPM
  potPos2 = map(analogRead(A1), 0, 1023, 0, 180);//Read value for volume
  Serial.print(potPos2);    //displaying values in serial port
  Serial.print(":");
  Serial.print(potPos1);
  Serial.println("units");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BPM:");
  lcd.print(potPos1);
  lcd.setCursor(9,0);
  lcd.print("SpO2:--");
  lcd.setCursor(0,1);
  lcd.print("VOL:");
  lcd.print(potPos2);
  lcd.print("cu.");
  delay(500);
  S1.write(0);
  if (potPos2==0){       //When volume is 'zero'
    tone(13, 1000, 500); //Buzzer will activate
    if(potPos1==0){      //When BPM is 'zero'
      tone(13, 1000, 500);//switching on buzzer
      S1.write(0);
    delay(10);
      S1.write(0);
    delay(15);
    }
   //delay(50);  
}
 else if((potPos2>0)&&(potPos2<=18)){   //When only 10% of volume is present buzzer
                                    //will activate with less frequency
    tone(13, 500, 300);
   if ((potPos1>=0)&&(potPos1<=5)){   //When BPM is less than expected
    S1.write(0);
   delay(1000);
   tone(13, 500, 300);//switching on buzzer
   S1.write(75);
   delay(1500);
} 
  else if ((potPos1>5)&&(potPos1<=11)){
    S1.write(0);
    delay(1000);
    tone(13, 250, 300);//switching on buzzer
    S1.write(60);
    delay(1500);
}
   else if ((potPos1>11)&&(potPos1<=20)){
    S1.write(0);
    delay(1000);      //No Buzzer as BPM is stable
   S1.write(45);
    delay(1500);
} 
  else if ((potPos1>20)&&(potPos1<=50)){
    S1.write(0);
   delay(1000);
    tone(13, 500, 200);//switching on buzzer
    S1.write(30);
    delay(1500);
} 
  else if ((potPos1>50)&&(potPos1<=100)){
    S1.write(0);
    delay(1000);
    tone(13, 750, 300);//switching on buzzer
    S1.write(20);
    delay(1500);
}
  //delay(100);
}
  else if((potPos2>18)&&(potPos2<=180)){
    
  if ((potPos1>=0)&&(potPos1<=5)){
    S1.write(0);
   delay(1000);
   tone(13, 500, 300);//switching on buzzer
   S1.write(75);
   delay(1500);
} 
  else if ((potPos1>5)&&(potPos1<=11)){
    S1.write(0);
    delay(1000);
    tone(13, 250, 300);//switching on buzzer
    S1.write(60);
    delay(1500);
}
   else if ((potPos1>11)&&(potPos1<=20)){
    S1.write(0);
    delay(1000);
   S1.write(45);
    delay(1500);
} 
  else if ((potPos1>20)&&(potPos1<=50)){
    S1.write(0);
   delay(1000);
    tone(13, 500, 200);//switching on buzzer
    S1.write(30);
    delay(1500);
} 
  else if ((potPos1>50)&&(potPos1<=100)){
    S1.write(0);
    delay(1000);
    tone(13, 750, 300);//switching on buzzer
    S1.write(20);
    delay(1500);
}
  //delay(100);
  }
}

