#include "HX711.h"
#include <LiquidCrystal.h>

int IN1 = 4;
int IN2 = 5;
int DOUT = 3;
int CLK = 2;

double cf = 18029.57; // Calibration Factor

int Bstart = 6;
int Bstop = 7;
int Bstopage = 1;

float weight;

HX711 scale;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

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
