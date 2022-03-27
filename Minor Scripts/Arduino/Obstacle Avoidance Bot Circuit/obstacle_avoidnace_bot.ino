// In this code we are making the Obstacle Avoidance Circuit.
// We firstly declare the variables like trigPin for triggerpin of ultrasonic sensor and echoPin for echopin of ultrasonic sensor
// and input1, input2, input3 and input4 for motor driver for two motors.


const int trigPin=5;
const int echoPin=6;
const int input1=3;
const int input2=2;
const int input3=11;
const int input4=12;
long distance;

void setup()
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  pinMode(input3,OUTPUT);
  pinMode(input4,OUTPUT);
  Serial.begin(9600);
}

// In obstacle avoidance bot the main logic in this code is firstly we will calculate the distance of obstacle using ultrasoic sensor if the 
// distance is less than 57 cm then bot will stop for 1 sec and print "Stop" on serial monitor. After that bot will move backward for 2 sec and
// print "Moving Backward". In this way bot has succesfully avoid the obstacle so we will print it on serial monitor "Avoid the obstacle 
// succefully". After that the code will print the distance again. Now the distane is greater than 57 cm so bot will turn left for 1 sec 
// and printing "Moving Left". After this bot will move forward and print "Moving Forward!".

void loop()
{
  digitalWrite(trigPin,LOW);
  delay(2);
  digitalWrite(trigPin,HIGH);
  delay(2);
  digitalWrite(trigPin,LOW);
  long time=pulseIn(echoPin,HIGH);
  distance=(0.0343*time)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance<57){
    
    digitalWrite(input1,LOW);
    digitalWrite(input2,LOW);
    digitalWrite(input3,LOW);
    digitalWrite(input4,LOW);
    
    Serial.println("STOP");
    delay(1000);
    
    digitalWrite(input1,LOW);
    digitalWrite(input2,HIGH);
    digitalWrite(input3,LOW);
    digitalWrite(input4,HIGH);

    Serial.println("Moving Backward");
    delay(2000);

    
    Serial.println("Avoid the Ostacle Succesfully");
    
    digitalWrite(input1,LOW);
    digitalWrite(input2,HIGH);
    digitalWrite(input3,HIGH);
    digitalWrite(input4,LOW);
    
    Serial.println("Moving Left");
    delay(1000);
    
    digitalWrite(trigPin,LOW);
    delay(2);
    digitalWrite(trigPin,HIGH);
    delay(2);
    digitalWrite(trigPin,LOW);
    long time=pulseIn(echoPin,HIGH);
    distance=(0.0343*time)/2;
    Serial.print("Distance: ");
    Serial.println(distance);

  }
  
  else{
    
    digitalWrite(input1,HIGH);
    digitalWrite(input2,LOW);
     digitalWrite(input3,HIGH);
    digitalWrite(input4,LOW);
    
    Serial.println("Moving Forward!");
    distance=0;
  }
}
