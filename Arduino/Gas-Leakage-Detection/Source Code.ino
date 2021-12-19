// C++ code
//
int buz=7;
int gs=A0;
int gasLevel=0;
void setup()
{
  pinMode(buz, OUTPUT);
  pinMode(gs,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(buz,LOW);
  gasLevel = analogRead(gs);
  Serial.print(gasLevel);
  if(gasLevel>=100){
  	digitalWrite(buz,HIGH);
  }
  
}