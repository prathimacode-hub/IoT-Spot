int button = 7;
void setup()
{
    // put your setup code here, to run once:
    pinMode(LED_BUILTIN, OUTPUT); //to initialise built-in LED pin 13 as output
    pinMode(button, INPUT);       //to initialize pin 7 as input of pushbutton switch
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (digitalRead(button) == HIGH)
        digitalWrite(LED_BUILTIN, HIGH);
    else
        digitalWrite(LED_BUILTIN, LOW);
}