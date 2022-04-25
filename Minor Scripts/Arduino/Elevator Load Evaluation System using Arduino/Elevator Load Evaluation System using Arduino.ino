#include "HX711.h"
#include <LiquidCrystal.h>

int IN1 = 4;
int IN2 = 5;
int DOUT = 3;
int CLK = 2;

double cf = 18029.57;

int Bstart = 6;
int Bstop = 7;
int Bstopage = 1;

float weight;

HX711 scale;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);