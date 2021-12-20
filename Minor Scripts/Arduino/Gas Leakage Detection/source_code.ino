// Source code for Gas Leakage Detection
// Assigning variables and constants that will be used later in the code
int buz=7;	// digital pin connected to the positive of the pieze buzzer
int gs=A0;	// Analog pin connected to the A2/output of the gas sensor
int gasLevel=0;	// pre assigned variable where the gas levels will be stored	
void setup()
{
//Assigning pinmodes
  pinMode(buz, OUTPUT);
  pinMode(gs,INPUT);

}

void loop()
{
  digitalWrite(buz,LOW); // Initially Setting buzzer to low
  gasLevel = analogRead(gs); // reading gas levels
  if(gasLevel>=100){		//Check if gas level is more than a 100.
  	digitalWrite(buz,HIGH);	//Setting the buzzer on.
  }
  
}
