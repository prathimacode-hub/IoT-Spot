// Signal Lights 1
const int g1 = 2;
const int y1 = 3;
const int r1 = 4;

// Signal Lights 2
const int g2 = 5;
const int y2 = 6;
const int r2 = 7;

// Signal Lights 3
const int g3 = A4;
const int y3 = 9;
const int r3 = 10;

// Signal Lights 4
const int g4 = 11;
const int y4 = 12;
const int r4 = 13;

const int pRed = A2;
const int pgreen = A3;
const int pIN = 8;

void setup()

{
  // Defining PinModes
  pinMode(r1, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);

  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);

  pinMode(r3, OUTPUT);
  pinMode(y3, OUTPUT);
  pinMode(g3, OUTPUT);

  pinMode(r4, OUTPUT);
  pinMode(y4, OUTPUT);
  pinMode(g4, OUTPUT);

  pinMode(pRed, OUTPUT);
  pinMode(pgreen, OUTPUT);
  pinMode(pIN, INPUT);

  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  digitalWrite(pRed, HIGH);
}

void loop()
{

  int crossIn = digitalRead(pIN);

  if (crossIn == HIGH)
  {
    WalkCycle();
  }
  else
  {
    delay(100);
    digitalWrite(r1, LOW);
    digitalWrite(g1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);
    delay(4000);
  }

  int crossIn2 = digitalRead(pIN);

  if (crossIn2 == HIGH)
  {
    WalkCycle();
  }
  else
  {
    digitalWrite(g1, LOW);

    digitalWrite(y1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);
    delay(2000);
  }

  int crossIn3 = digitalRead(pIN);

  if (crossIn3 == HIGH)
  {
    WalkCycle();
  }
  else
  {
    digitalWrite(y1, LOW);
    digitalWrite(r2, LOW);

    digitalWrite(r1, HIGH);
    digitalWrite(g2, HIGH); // 2nd light
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);
    delay(4000);
  }

  int crossIn4 = digitalRead(pIN);

  if (crossIn4 == HIGH)
  {
    WalkCycle();
  }
  else
  {
    digitalWrite(g2, LOW);

    digitalWrite(y2, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);
    delay(2000);
  }

  int crossIn5 = digitalRead(pIN);

  if (crossIn5 == HIGH)
  {
    WalkCycle();
  }
  else
  {
    digitalWrite(y2, LOW);
    digitalWrite(r3, LOW);

    digitalWrite(g3, HIGH); // 3rd light
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r4, HIGH);
    delay(4000);
  }

  int crossIn6 = digitalRead(pIN);

  if (crossIn6 == HIGH)
  {
    WalkCycle();
  }
  else
  {
    digitalWrite(g3, LOW);

    digitalWrite(y3, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r4, HIGH);
    delay(2000);
  }

  int crossIn7 = digitalRead(pIN);

  if (crossIn7 == HIGH)
  {
    WalkCycle();
  }
  else
  {
    digitalWrite(y3, LOW);
    digitalWrite(r3, LOW);
    digitalWrite(r4, LOW);

    digitalWrite(g4, HIGH); // 4th light
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    delay(4000);
  }

  int crossIn8 = digitalRead(pIN);

  if (crossIn8 == HIGH)
  {
    WalkCycle();
  }
  else
  {
    digitalWrite(g4, LOW);
    digitalWrite(r4, LOW);

    digitalWrite(y4, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    delay(2000);
  }
  digitalWrite(y4, LOW);
  digitalWrite(r4, LOW);
  digitalWrite(r1, LOW);
}

void WalkCycle()
{
  delay(350);

  digitalWrite(g1, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(g3, LOW);
  digitalWrite(g4, LOW);

  digitalWrite(y1, LOW);
  digitalWrite(y2, LOW);
  digitalWrite(y3, LOW);
  digitalWrite(y4, LOW);

  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);

  digitalWrite(pgreen, HIGH);
  digitalWrite(pRed, LOW);
  delay(3000);
  digitalWrite(pgreen, LOW);

  // digitalWrite(pIN, LOW);  // Turn off green Pedestrian Light

  delay(250);

  for (int x = 0; x < 5; x++)
  { // Flash green Ped LED 5X
    digitalWrite(pgreen, HIGH);
    delay(250);
    digitalWrite(pgreen, LOW);
    delay(250);
  }

  digitalWrite(pRed, HIGH);
}