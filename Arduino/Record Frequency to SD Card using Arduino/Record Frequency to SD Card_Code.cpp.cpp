//Include Libraries
#include <LiquidCrystal.h>
#include <SPI.h> // To communicate with SPI devices
#include <SD.h> // For Reading and Writing to SD cards
File myFile; // Declaring file name
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

// Definibg parameters required for calculating SD Card
long microSecs;
long freq;
int lastBit;
int nowVal;
long secs;
long maxHz;
long minHz;
long minmax;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Loading...");
  pinMode(A1,INPUT);
  pinMode(A5,OUTPUT);
  microSecs = micros();
  freq = 0;
  lastBit = 0;
  nowVal =0;
  maxHz=0;
  minHz=0;
  minmax=0;
  secs = millis();
  Serial.begin(9600);// Initializing Serial Port
  Serial.print("Initializing SD card...");// Initializing SD Card
if (!SD.begin(10)) {
Serial.println("Initialization failed!");
while (1);
}
Serial.println("Initialization done.");
// open the file. note that only one file can be open at a time,
// so you have to close this one before opening another.
myFile = SD.open("test.txt", FILE_WRITE);
// if the file opened okay, write to it:
if (myFile) {
Serial.print("Writing to test.txt...");
myFile.close();// close the file:
Serial.println("Done.");
} else {
// if the file didn't open, print an error:
Serial.println("Error opening test.txt");
}
}

int x=0;
void loop() {


  if ((microSecs+20)<micros()){
      nowVal=digitalRead(A1);//Reading input from pin A1 for calculating frequency
 
      if (lastBit!=nowVal) {
        lastBit=nowVal;
        freq=freq+1;
      }
      if (freq>maxHz){
        maxHz=freq;
      }
      if (freq<minHz){
        minHz=freq;
      }
     
      microSecs = micros();
  }
  if (secs+1000<millis()){

    if (minmax+300000<millis())
    {
      minmax=millis();
      minHz=freq;
      maxHz=freq;
      
    }
      
      lcd.clear();
      lcd.print("FREQ. : ");
      lcd.print((freq/2));
       myFile.println((freq/2));// Adding frequency to '.txt' file
      lcd.print("hz");
 
      
      freq=0;
      secs=millis();
      
  }

}