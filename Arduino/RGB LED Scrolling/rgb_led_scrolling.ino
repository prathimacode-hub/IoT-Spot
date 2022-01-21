void setup()
{
    // put your setup code here, to run once:
    pinMode(11, OUTPUT); //Initiating pin 11 as output of the Red terminal
    pinMode(10, OUTPUT); //Initiating pin 10 as output of the Blue terminal
    pinMode(9, OUTPUT);  //Initiating pin 9 as output of the Green terminal
}

void loop()
{
    // put your main code here, to run repeatedly:

    //To make the red color glow
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(9, 0);
    delay(1000);

    //To make the blue color glow
    analogWrite(11, 0);
    analogWrite(10, 255);
    analogWrite(9, 0);
    delay(1000);

    //To make the green color glow
    analogWrite(11, 0);
    analogWrite(10, 0);
    analogWrite(9, 255);
    delay(1000);
}