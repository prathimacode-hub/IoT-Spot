// Declare and initialize the pins used on the Arduino board.
int buzzer = 3;
int pir = 7;
int red_light_pin = 9;
int green_light_pin = 11;
int blue_light_pin = 10;
void setup()
{
  // set the pin modes for the PIR sensor pin, buzzer pin, and LED pins connected to the Arduino board.
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

  // Using the digitalWrite() function set the above mentioned to LOW state.
  digitalWrite(pir, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(red_light_pin, LOW);
  digitalWrite(green_light_pin, LOW);
  digitalWrite(blue_light_pin, LOW);
}
void loop()
{

  // using the if-else condition, set the RGB LED to glow in blue colour when the PIR sensor reads the high value.
  if (digitalRead(pir) == HIGH)
  {
    digitalWrite(buzzer, HIGH);
    RGB_color(0, 0, 255); // blue
    while (digitalRead(pir) == HIGH)
      ;
  }
  // Set the LED to glow in magenta colour, otherwise.
  else
  {
    digitalWrite(buzzer, LOW);
    RGB_color(255, 0, 255); // Magenta
  }
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  // assign a variable to every colour pin of the RGB LEDs.
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}