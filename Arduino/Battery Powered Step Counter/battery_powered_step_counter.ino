// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int digitalInPin = 7; // to take input of tilt sensor
int sensorValue = 0;
int olda = 0;
int oldtilt = 0;

void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Steps Count:");
    int a = 0, b = 0, c = 0;
}

void loop()
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    int a = 0, b = 0, c = 0;

    sensorValue = digitalRead(digitalInPin);
    c = sensorValue;
    b = oldtilt;
    // count steps only when the tilt sensor changes position
    if (oldtilt == 1)
    {
        sensorValue = 0;
    }
    oldtilt = c;
    delay(1);

    a = olda + sensorValue; // total count
    // Print total step count
    lcd.print(a);
    olda = a;
}
