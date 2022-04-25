#include "HX711.h"
#include <LiquidCrystal.h>

int IN1 = 4; // Motor Pin 1
int IN2 = 5; // Motor Pin 2
int DOUT = 3;
int CLK = 2;

double cf = 18029.57; // Calibration Factor

int Bstart = 6;
int Bstop = 7;
int Bstopage = 1;

float weight;

HX711 scale;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // Defining the LCD pins

void setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    lcd.begin(16, 2);

    pinMode(Bstart, INPUT);
    pinMode(Bstop, INPUT);
    pinMode(Bstopage, INPUT);

    scale.begin(DOUT, CLK);
    scale.set_scale(calibration_factor); // This value is obtained by using the SparkFun_HX711_Calibration sketch
    scale.tare();                        // Assuming there is no weight on the scale at start up, reset the scale to 0
}

void loop()
{
    weight = scale.get_units() / 2;
    lcd.setCursor(0, 0);
    lcd.print("WEIGHT MEASURED");
    lcd.setCursor(6, 1);
    lcd.print(weight, 1);
    lcd.print(" Kg");
    if (weight > 60)
    {
        stopage();
    }
    else
    {
        if (digitalRead(Bstart) == LOW)
        {
            forward();
        }
    }
    reverse();
    m_stopage();
}
void reverse() // reverse movement of the elevator motor function
{
    if (digitalRead(Bstop) == LOW)
    {
        if (weight > 60)
            stopage();
        else
            backward();
    }
}
void m_stopage()
{
    if (digitalRead(Bstopage) == LOW)
        stopage();
}
void forward() // For forward motion of elevator motor
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
}
void backward() // For backward motion of elevator motor
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
}

void stopage() // To stop elevator motor
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}