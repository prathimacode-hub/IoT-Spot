int led1=12;
int pot=A0;
int val=0;

void setup()
{
    pinMode(led1,OUTPUT);
    pinMode(pot,INPUT);
}
void loop()
{
    val= analogRead(pot);
    analogWrite(led1,val/4);
    delay(100);
}
