// Library for IR remote
#include <IRremote.h>

// Fore receiver pin of IR sensor
const int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);

// a variable to detect if input was given or not
decode_results results;

// Declaring variable for key value input from IR remote //initally zero
unsigned long key_value = 0;

// Declaring a variable to store 0 or 1 for direction of rotation of motor
int rotate = 0;

// Declaring variables for pin numbers
const int pwm = 13;
const int in_1 = 11;
const int in_2 = 9;

// setp function
void setup()
{
    Serial.begin(9600);

    // Setting INPUT and OUTPUT mode for all pins

    pinMode(2, INPUT);
    pinMode(pwm, OUTPUT);
    pinMode(in_1, OUTPUT);
    pinMode(in_2, OUTPUT);

    // Starting IR sensor
    irrecv.enableIRIn();
    irrecv.blink13(true);
}
void loop()
{

    // For clockwise rotation
    if (rotate == -1)
    {
        digitalWrite(in_1, HIGH);
        digitalWrite(in_2, LOW);
        analogWrite(pwm, 255);
    }

    // For anti-clockwise rotation
    else if (rotate == 1)
    {
        digitalWrite(in_1, LOW);
        digitalWrite(in_2, HIGH);
        analogWrite(pwm, 255);
    }

    else if (rotate == 0)
    {
        analogWrite(pwm, 0);
    }

    // if input is given
    if (irrecv.decode(&results))
    {

        if (results.value == 0XFFFFFFFF)
        {
            // repetition of keys
            results.value = key_value;
        }
        switch (results.value)
        {
        case 0xFD20DF: // For Next button
            rotate = -1;
            break;
        case 0xFD609F: // For Previous button
            rotate = 1;
            break;
            ;
        }
        key_value = results.value;
        irrecv.resume();
    }
}