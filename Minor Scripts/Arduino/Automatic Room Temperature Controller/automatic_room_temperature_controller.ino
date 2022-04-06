// Here LED is uses as HEATER and DC MOTOR is uses as Cooler.
const int temp_trans_pin = A0;
const int Heater_pin = 13;
const int FAN_pin = 6;
float Eqv_volt , SensorTemp;
// Setting the range of the desire tempersture

float MinTemp = 20, MaxTemp = 35; // Room temp [20-35]

#include<LiquidCrystal.h>

LiquidCrystal LCD(12,11,5,4,3,2);

void setup(){
  // Initializing LCD Display
  LCD.begin(16,2);
  Serial.begin(9600);
  pinMode(Heater_pin, OUTPUT);
  pinMode(FAN_pin, OUTPUT);
  
  LCD.print("Room Temp(C): ");
  LCD.setCursor(1,0);
  LCD.print(MinTemp); LCD.print(" - "); LCD.print(MaxTemp);
  
  delay(2000);
}

void loop(){
  // Converting the analog value into volt.
  Eqv_volt=analogRead(temp_trans_pin)*5.0/1023;
  // Converting the Eqv_volt into temperature.
  SensorTemp = 100.0*Eqv_volt-50.0;
  
  LCD.clear();
  // Printing the Sensor Reading on LCD Display and Serial Monitor with temperature.
  LCD.print("Sensor Reading: ");
  Serial.print("Sensor Reading: ");
  LCD.setCursor(1,0);
  LCD.print(SensorTemp); LCD.print(" C");
  Serial.print(SensorTemp); Serial.print(" C");
  Serial.println();
  
  delay(2000);
  
  // If sensortemp > Maximum temperature then FAN will turn on means motor will rotate in our simulation and some statement will get print on the LCD display after some time once the temperature gets in normal condition the fan will turn off.
  if (SensorTemp>MaxTemp){
    LCD.clear();
    LCD.print("Temp is HIGHER!");
    LCD.setCursor(0,1); LCD.print("Turn on FAN!");
    for (int i=0; i<=255; i++){
      analogWrite(FAN_pin, i);
    }
    delay(2000);
    
    LCD.clear();
    LCD.print("Now Temp is OK!");
    LCD.setCursor(0,1);
    LCD.print("Turn off FAN!");
    for (int i=255; i>=0; i--){
      analogWrite(FAN_pin, i);
    }
    delay(2000);
  }
  // If sensortemp < Minimum temperature then Heater will turn on means LED will glow in our simulation and some statement will get print on the LCD display after some time once the temperature gets in normal condition the LED will turn off.
  else if(SensorTemp<MinTemp){
    LCD.clear();
    LCD.print("Temp is LOWER!");
    LCD.setCursor(0,1); 
    LCD.print("Turn on the Heater!");
    
    digitalWrite(Heater_pin, HIGH);
    delay(3000);
    
    LCD.clear();
    LCD.print("Temp is LOWER!");
    LCD.setCursor(0,1); 
    LCD.print("Turn off the Heater!");
    delay(1000);
    digitalWrite(Heater_pin, LOW);
    LCD.clear();
  }
  
  else if(SensorTemp>MinTemp && SensorTemp<MaxTemp){
    LCD.clear();
    LCD.print("Temp is NORMAL!");
    LCD.setCursor(0,1); 
    LCD.print("Turn off all!");
    delay(1000);
    LCD.clear();
  }
  else{
    LCD.clear();
    LCD.print("Something went wrong!");
    LCD.setCursor(0,1); 
    LCD.print("Wrong in the circuit!");
    delay(1000);
    LCD.clear();
    
  }

  delay(1000);
}
