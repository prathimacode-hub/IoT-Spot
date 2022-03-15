/**********************
 * Included the header file of LCD
 * *******************
 */
#include <LiquidCrystal.h>
/**********************
*Connecting LCD to the circuit
Connecting 2nd pin to RS
Connecting 3th pin to EN
Connecting 4th pin to D4
Connecting 5th pin to D5
Connecting 6th pin to D6 
***********************
*/
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
/*********************
  *Conecting to TCS3200 Sensor
***********************
*/
#define outPin 8
#define s0 9
#define s1 10
#define s2 11
#define s3 12

boolean DEBUG = true;

// Variables
int red, grn, blu;
String color ="";
long startTiming = 0;
long elapsedTime =0;

void setup(){
  Serial.begin(9600);
 
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); //out from sensor becomes input to arduino

  // Setting frequency scaling to 100%
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor (3,0);
  lcd.print("Welcome To");
  lcd.setCursor (1,1);
  lcd.print("Color Detector");
  delay(2000);  
  lcd.clear();  
  startTiming = millis();
}

void loop(){
  getColor();
   
  if(DEBUG){
     printData(); 
    elapsedTime = millis()-startTiming; 
  }if (elapsedTime > 1000) {
     showDataLCD();
    startTiming = millis();
  }
}

/*************** 
Read RGB components
****************
 */
void readRGB(){
  red = 0,
  grn=0,
  blu=0;
  int n = 10;
  for (int i = 0; i < n; ++i){
    /***********************
     * If S2 & S3 is kept to LOW 
     * Photodiode gives RED as result
     */ 
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    red = red + pulseIn(outPin, LOW);
  
    /***********************
     * If S2 & S3 is kept to HIGH 
     * Photodiode gives GREEN as result
     */ 
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    grn = grn + pulseIn(outPin, LOW);
    
     /***********************
     * If S2 is kept to HIGH & S3 is kept to LOW 
     * Photodiode gives GREEN as result
     */ 
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    blu = blu + pulseIn(outPin, LOW);
  }
  red = red/n;
  grn = grn/n;
  blu = blu/n;
}

/***************************************************
* Showing captured data at Serial Monitor
****************************************************/
void printData(void){
  Serial.print("red= ");
  Serial.print(red);
  Serial.print("   green= ");
  Serial.print(grn);
  Serial.print("   blue= ");
  Serial.print(blu);
  Serial.print (" - ");
  Serial.print (color);
  Serial.println (" detected!");
}

/****************************************************
* Showing capured data at LCD
/****************************************************/
void showDataLCD(void){
lcd.clear();
lcd.setCursor (0,0);
lcd.print("R");
lcd.print(red);
lcd.setCursor (6,0);
lcd.print("G");
lcd.print(grn);
lcd.setCursor (12,0);
lcd.print("B");
lcd.print(blu);  

lcd.setCursor (0,1);
lcd.print("Color: ");  
lcd.print(color);  
}


void getColor(){
    /***********************************************
     * Taking results from readRGB() and here we are taking the readings for detection of the color
     * ********************************
    */  
  readRGB();

  if(red>7  && red<11  && grn>17 && grn<23 && blu>13 && blu<18){
       color = "RED";
  }else if(red>17 && red<21  && grn>11 && grn<15 && blu>12 && blu<18){
       color = "GREEN";
  }else if(red>22 && red<28  && grn>11 && grn<16 && blu>6  && blu<10){
       color = "BLUE";
  }else if(red>4  && red<8   && grn>6  && grn<10 && blu>9  && blu<13){
       color = "YELLOW";
  }else if(red>5  && red<8   && grn>4  && grn<8  && blu>3  && blu<7){
       color = "WHITE";
  }else if(red>28 && red<36  && grn>25 && grn<34 && blu>20 && blu<29){
       color = "BLACK";
  }else{
       color = "NO_COLOR";
  }   
}