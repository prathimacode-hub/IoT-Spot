/* In Ultrasonic sensor there are two pin one is trig and another one is echo pin
 *  so in this progarm we firstly send the wave through trig pin and after a delay of 2 microsecond we will 
 *  low it and take the duration of time it takes to bounce back from the object using pulseIn() function  and echopin
 *  after that we will calculate the distance using formula and print it on serial monitor.
 */


const int trigPin = 7;
const int echoPin = 6;

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin , HIGH);
  distance = (duration*0.034)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
}
