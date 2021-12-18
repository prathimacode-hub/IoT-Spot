// Setting the pin configuration of motor and potentiometer
int potentioPin = A0;
int motorPin = 9;

// Setting the initial values of motor and potentiometer
int potentioValue = 0;
int motorValue = 0;

void setup() {
 Serial.begin(9600);
}

void loop() {
 potentioValue = analogRead(potentioPin);      // Reading the input of potentiometer (0-1023)
 motorValue = map(potentioValue, 0, 1023, 0, 255);  // Scaling the motor values to range (0-255)
 analogWrite(motorPin, motorValue);              // Output the PWM signal to motorpin
 Serial.print("potentiometer = " );     
 Serial.print(potentioValue);                // Printing the potentiometer value on serial monitor
 Serial.print(" motor value = ");
 Serial.println(motorValue);                 // Printing the motor value on serial monitor
 delay(2);                                   // Time delay to overcome motor inertia
}