
#include "HX711.h"
#include <LiquidCrystal.h>

#define calibration_factor 18029.57 // This value is obtained using the SparkFun_HX711_Calibration sketch
#define IN1 4
#define IN2 5
#define DOUT 3
#define CLK 2

#define Bstart 6
#define Bstop 7
float weight;
#define Bstopage 1
HX711 scale;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);