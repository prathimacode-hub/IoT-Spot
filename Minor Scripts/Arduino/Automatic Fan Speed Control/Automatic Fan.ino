#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,8,7,6,5);
int tempPin = A0;   // Output pin LM35
int fan = 10;       // pin 
int led = 6;        // pin LED 
int temp;
int tempMin = 30;   
int tempMax = 60;  
int fanSpeed;
int fanLCD;
int stop = 2;		// pin Interrupt 

void setup() {
  Serial.begin(9600);
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(tempPin, INPUT);
  lcd.begin(16,2);  

  pinMode(stop, INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt (stop), stopfan, HIGH); //digitalPinToInterrupt (stop), HIGH
}

void loop() {  
   temp = readTemp();     	
   if(temp  < tempMin) { 	 
      fanSpeed = 0; 		
      digitalWrite(fan, LOW); 
   } 
   if((temp  >= tempMin) && (temp <= tempMax)) { 		// if temperature is higher than minimum temp 
      fanSpeed = map(temp, tempMin, tempMax, 32, 255);	// the actual speed of fan 
      fanLCD = map(temp, tempMin, tempMax, 0, 102); 	// speed of fan to display on LCD 
      analogWrite(fan, fanSpeed); 						// spin the fan at the fanSpeed speed 
   } 
   if(temp  > tempMax) {        
     digitalWrite(led, HIGH); 	
   } else {                   
     digitalWrite(led, LOW); 
   }
   
   lcd.print("TEMP: ");
   lcd.print(temp);      //Celsius
   lcd.print("C ");
   lcd.setCursor(0,1);   
   lcd.print("FANS: ");
   lcd.print(fanLCD);    
   lcd.print("%");
   delay(200);
   lcd.clear();   
  
  
}

int readTemp() {  Celsius
  temp = analogRead(tempPin);
  return temp * 0.48828125;
}

void stopfan () {			
  lcd.clear();
  digitalWrite (fan, LOW);
  delayMicroseconds(90000000000000000000000);
  //lcd display
  Serial.println("DragonUncaged");
  //initial display for the temperature
  lcd.print("TEMP: --");
  lcd.setCursor(0,1); 
  lcd.print("FANS: 0%");
  
}
  