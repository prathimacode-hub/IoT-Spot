// C++ code
//
int WaterLevel = 0;

int echoPin = 0;
int triggerPin = 0;

//Function to read and return ultrasonic sensor values
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);  // Sets the trigger pin to HIGH state for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH); // Reads the echo pin, and returns the sound wave travel time in microseconds
}

void setup()
{
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  //Setting the echo and triggerpin to digital pins 3 & 2 respectively.
  echoPin = 3;
  triggerPin = 2;
  
  WaterLevel = 0.01723 * readUltrasonicDistance(2, 3);
  
  Serial.println("Medium level");
  Serial.println(WaterLevel);
  
  // Condition for checking the water level
  if (WaterLevel <= 40) {
    Serial.println("Tank is FULL");
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    // tone(pin, frequency, duration)
    tone(5, 17, 1000); // play tone  (C# = 17 Hz)
    
  }
  
  if (WaterLevel >= 300) {
    Serial.println("Tank is EMPTY");
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  delay(10); // Adding delay to improve simulation performance
}