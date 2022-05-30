//The alarmSetCounter should decrease to sensitivity value to trigger the buzzer

const int sensor= 5;
int sensorStat;//Sensor status (HIGH or LOW)
int alarmSetCounter= 20;//For matching with sensitivity (0 to 20)
const int pot= A0;
const int buzzer= 4;
const int interruptPin= 3;
int sensitivity;//Sensitivity for the alarm
void setup()
{
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin),NoAlarm,CHANGE);
}

void Monitor()//Printing values on monitor
{ Serial.print("Pot val: ");Serial.print(analogRead(pot));
 
 Serial.print(" Sensitivity: ");Serial.print(sensitivity);
 Serial.print(" Alarm Counter: ");Serial.println(alarmSetCounter);delay(1000);
}

void Alarm()
{
  digitalWrite(buzzer, HIGH);delay(10000);//Buzzer for 10 seconds
  for(int i=0;i=100;i++)
  {digitalWrite(2, HIGH);delay(500);digitalWrite(2, LOW);}
}

void NoAlarm()
{
  alarmSetCounter= 20;
  digitalWrite(buzzer, LOW);
  digitalWrite(2, LOW);
}

void loop()
{
  sensitivity= 20*((float) analogRead(pot)/(float) 1024);//Sensitivity for a scale of 1 to 20
  sensorStat= digitalRead(sensor);
  if (sensorStat == 1)
  {
    alarmSetCounter--;
    if (alarmSetCounter == sensitivity)
    {
     Alarm();//alarm will ring
    }
  }
  else
  {
    NoAlarm();//alarm will not ring
  }
  Monitor();
}
