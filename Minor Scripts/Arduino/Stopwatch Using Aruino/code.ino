#include <LiquidCrystal.h>             //library for lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // pin setup for lcd

void setup()
{
    lcd.begin(16, 2); // begin lcd
    lcd.clear();

    Serial.begin(9600); // begin serial monitor

    // setting push button pins

    pinMode(8, INPUT);
    digitalWrite(8, HIGH);
    pinMode(9, INPUT);
    digitalWrite(9, HIGH);
}

// declaring variables

double i = 0;
double a = millis();
double c;

void loop()
{
    // clear lcd
    lcd.clear();
    // displaying initial message
    lcd.print("press start");
    delay(100);

    //
    if (digitalRead(8) == LOW)
    {
        lcd.clear();
        a = millis();
        while (digitalRead(9) == HIGH)
        {
            // if one push button at 8 is not pressed but at 9 is pressed
            c = millis();
            i = (c - a) / 1000;
            lcd.print(i);
            lcd.setCursor(7, 0);
            lcd.print("Sec");
            lcd.setCursor(0, 0);
            Serial.println(c);
            Serial.println(a);
            Serial.println(i);
            Serial.println("......");
            delay(100);
        }

        if (digitalRead(9) == LOW)
        {
            // if one push button at 9 is not pressed but at 8 is pressed
            while (digitalRead(8) == HIGH)
            {
                lcd.setCursor(0, 0);
                lcd.print(i);
                lcd.setCursor(11, 0);
                lcd.print("");
                lcd.setCursor(0, 0);
                delay(100);
            }
        }
    }
}
