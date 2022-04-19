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
