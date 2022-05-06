#include <Servo.h>

Servo horizontal; // horizontal servo
int servoh = 180;
int servohLimitHigh = 175;
int servohLimitLow = 5;
// 65 degrees MAX

Servo vertical; // vertical servo
int servov = 45;
int servovLimitHigh = 60;
int servovLimitLow = 1;

// LDR pin connections
// name = analogpin;
int ldrlt = A0; // LDR top left - BOTTOM LEFT <--- BDG
int ldrrt = A3; // LDR top rigt - BOTTOM RIGHT
int ldrld = A1; // LDR down left - TOP LEFT
int ldrrd = A3; // ldr down rigt - TOP RIGHT

void setup()
{
  horizontal.attach(9);
  vertical.attach(10);
  horizontal.write(180);
  vertical.write(45);
  delay(2500);
}

void loop()
{
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down right
  int dtime = 10;
  int tol = 90;            // dtime=difference time, tol=tolerance
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right
  int dvert = avt - avd;   // check the diffirence of up and down
  int dhoriz = avl - avr;  // check the diffirence of left and right

  // IF and IF-ELSE statements are defined to loop the program and calculate the average values of the respective LDR’s.
  // Finally, this code helps to change the degree of the servo motor. So that it can be more effective.
  if (-1 * tol > dvert || dvert > tol)
  {
    if (avt > avd)
    {
      servov = ++servov;
      if (servov > servovLimitHigh)
      {
        servov = servovLimitHigh;
      }
    }
    else if (avt < avd)
    {
      servov = --servov;
      if (servov < servovLimitLow)
      {
        servov = servovLimitLow;
      }
    }
    vertical.write(servov);
  }

  if (-1 * tol > dhoriz || dhoriz > tol) // check if the difference is in the tolerance else change horizontal angle
  {
    if (avl > avr)
    {
      servoh = --servoh;
      if (servoh < servohLimitLow)
      {
        servoh = servohLimitLow;
      }
    }
    else if (avl < avr)
    {
      servoh = ++servoh;
      if (servoh > servohLimitHigh)
      {
        servoh = servohLimitHigh;
      }
    }
    else if (avl = avr)
    {
      delay(5000);
    }
    horizontal.write(servoh);
  }

  delay(dtime);
}