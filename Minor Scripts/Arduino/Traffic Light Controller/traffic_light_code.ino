   void setup() {
  // configure the output pins
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}
 
void loop() 
{
  digitalWrite(2,1); //enables the yellow lights
  digitalWrite(7,1);   
  digitalWrite(10,1);
  digitalWrite(4,0);
  digitalWrite(3,0);  
  digitalWrite(6,0);
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(5,0);
  delay(1000);
 
  digitalWrite(3,1); //enables the 1st set of signals
  digitalWrite(6,0);
  digitalWrite(2,0); 
  digitalWrite(7,1);
  digitalWrite(10,1);
  delay(5000);
 
  digitalWrite(4,1); //enables the yellow lights
  digitalWrite(5,0);
  digitalWrite(10,0);
  digitalWrite(2,0);
  digitalWrite(3,0);  
  digitalWrite(6,0);
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(7,1);
  delay(1000);
 
  digitalWrite(9,1); //enables the 2nd set of signals
  digitalWrite(7,1);  
  digitalWrite(8,0);
  digitalWrite(10,0);
  digitalWrite(5,0);  
  digitalWrite(4,1);
  delay(5000); 
   
  digitalWrite(8,0);  //enables the yellow lights
  digitalWrite(4,1); 
  digitalWrite(7,0);
  digitalWrite(2,0);
  digitalWrite(3,0);  
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(9,0);
  digitalWrite(10,1);
  delay(1000);
 
  digitalWrite(6,1); //enables the 3rd set of signals
  digitalWrite(10,1); 
  digitalWrite(7,0);
  digitalWrite(8,0); 
  digitalWrite(4,1);
  delay(5000);   
}
