//In this Project we are going to make RC Car Circuit.
// For this the components used will be 2 DC Motor, Arduino UNO R3, BreadBoard, L293D Motor Driver.
/* If we give the input:
   F- Forward, Both Motor will rotate in clockwise direction.
   B- Backward, Both Motor will rotate in anti clockwise direction.
   L- Left, Left motor will rotate in anticlockwise dirction and Right motor will rotate in clockwise direction.
   R- Right, Right motor will rotate in anticlockwise direction and Left motor will rotate in clockwise dirction
   S- Stop, Both motor will stop rotating.*/
// Input1 of L239D -- 6
// Input2 of L239D -- 7
// Input3 of L293D -- 13
// Input4 of L293D -- 12

void setup()
{
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
  {
    char val = Serial.read();
    if(val == 'F')
    {
        digitalWrite(6,0);
        digitalWrite(7,1);
        digitalWrite(13,0);
        digitalWrite(12,1);
    }
    else if(val == 'B')
    {
        digitalWrite(6,1);
        digitalWrite(7,0);
        digitalWrite(13,1);
        digitalWrite(12,0);
    }
    else if(val == 'L')
    { 
        digitalWrite(6,1);
        digitalWrite(7,0);
        digitalWrite(13,0);
        digitalWrite(12,1);
    }
    else if(val == 'R')
    {
        digitalWrite(6,0);
        digitalWrite(7,1);
        digitalWrite(13,1);
        digitalWrite(12,0);
    }
    else if(val == 'S')
    { 
        digitalWrite(6,0);
        digitalWrite(7,0);
        digitalWrite(12,0);
        digitalWrite(13,0);
    }
    
  }
}
