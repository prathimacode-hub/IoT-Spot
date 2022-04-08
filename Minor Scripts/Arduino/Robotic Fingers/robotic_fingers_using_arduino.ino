#include <Servo.h>
// This library allows an Arduino board to control RC (hobby) servo motors

// Initializing Servo objects for five fingers of the robotic hand
Servo thumb;
Servo index;
Servo middle;
Servo ring;
Servo pinky;

void setup()
{
  thumb.attach(3);  // Attaching digital PIN 3 to thumb micro servo
  index.attach(5);  // Attaching digital PIN 5 to index micro servo
  middle.attach(6); // Attaching digital PIN 6 to middle micro servo
  ring.attach(10);  // Attaching digital PIN 10 to ring micro servo
  pinky.attach(11); // Attaching digital PIN 11 to pinky micro servo
}

void loop()
{
  // Reading values (direction) of the real hand from the flex sensors via analogRead
  int thumbS = analogRead(A0);
  int indexS = analogRead(A1);
  int middleS = analogRead(A2);
  int ringS = analogRead(A3);
  int pinkyS = analogRead(A4);

  // Mapping values from analog to digital
  thumbS = map(thumbS, 59, 256, 0, 180);
  indexS = map(indexS, 59, 256, 0, 180);
  middleS = map(middleS, 59, 256, 0, 180);
  ringS = map(ringS, 59, 256, 0, 180);
  pinkyS = map(pinkyS, 59, 256, 0, 180);

  // Writing values of flex sensors to the servos, controlling the shafts accordingly,
  // setting the angle of the shaft (in degrees), moving the shaft to that orientation of the respective flex sensors.
  thumb.write(thumbS);
  index.write(indexS);
  middle.write(middleS);
  ring.write(ringS);
  pinky.write(pinkyS);

  delay(10);
}