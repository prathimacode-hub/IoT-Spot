int const trigPin = 9;
int const echoPin = 10;
int const buzzPin = 0;
void setup()
{
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzer
}
void loop()
{
// Duration will be the input pulse width and distance will be the distance
// to the obstacle in centimeters
int duration, distance;
// Output pulse with 1ms width on trigPin
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
// Measure the pulse input in echo pin
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration divided by 29.1 
distance = (duration/2) / 29.1;
// if distance less than 0.5 meter and more than 0 (0 or less means over range)
// Change the distance depending on your sensor
if (distance <= 100 && distance >= 0) {
// Buzzer will be on
digitalWrite(buzzPin, HIGH);
} else {
digitalWrite(buzzPin, LOW);
}
delay(60);
}