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