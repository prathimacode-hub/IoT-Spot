#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <Adafruit_NeoPixel.h>
#define neoPixel1 0 // Player 1
#define neoPixel2 1// Player 2
#define LEDs 1

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(LEDs, neoPixel1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(LEDs, neoPixel2, NEO_GRB + NEO_KHZ800);

//Start, pause button
#define start 13
// Player1 up push button pin
#define P1U 6
// Player1 down push button pin
#define P1D 7
// Player2 up push button pin
#define P2U 8
// Player2 down push button pin
#define P2D 9
// buzz electric crystal pin
#define buzz 10

//pad1
byte pad1[16] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};// array to hold pad1 LCD row-0&1 values
byte player1_1[8] = {0, 0, 0, 0, 0, 0, 1, 1};// array to hold pad1 LCD row-0 values
byte player1_2[8] = {1, 1, 0, 0, 0, 0, 0, 0};// array to hold pad1 LCD row-1 values

//pad2
byte pad2[16] = {0, 0, 0, 0, 0, 0, 16, 16, 16, 16, 0, 0, 0, 0, 0, 0};// array to hold pad2 LCD row-0&1 values
byte player2_1[8] = {0, 0, 0, 0, 0, 0, 16, 16};// array to hold pad2 LCD row-0 values
byte player2_2[8] = {16, 16, 0, 0, 0, 0, 0, 0};// array to hold pad2 LCD row-1 values

//ball
byte ball[16] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};// array to hold ball LCD row-0&1 values
byte ball1[8] = {0, 0, 0, 0, 0, 0, 0, 1};// array to hold ball LCD row-0 values
byte ball2[8] = {0, 0, 0, 0, 0, 0, 0, 0};// array to hold ball LCD row-1 values

/*
	x 			- cursor for ball
    bounce 		- status of bounce (0 - ball moves down, 1 - ball moves up)
    direction 	- direction of ball (L - left, R - right)
    v1, v2 & v3 - variables used to check whether the ball hits the paddles or not
    scr1 		- score of player1
    scr2 		- score of player2
    game		- start/stop (0 - stop, 1 - start)
*/

int x = 0, bounce = 0, v1 = 0, v2 = 0, v3 = 0;
char direction = 'L';
int scr1 = 0, scr2 = 0;
boolean game = 0;
int a = 0;

void setup() {

  strip1.begin();
  strip1.show();
  strip2.begin();
  strip2.show();

  pinMode(P1U, INPUT);
  pinMode(P1D, INPUT);
  pinMode(P2U, INPUT);
  pinMode(P2D, INPUT);
  pinMode(start, INPUT);
  pinMode(buzz, OUTPUT);

  buzz_sound(50);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Arduino UNO");
  lcd.setCursor(1, 1);
  lcd.print("Ping Pong Game");
  delay(1500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("from:");
  lcd.setCursor(0, 1);
  lcd.print("IOT SPOT");
  delay(3000);
}

void loop() {

  while (game == 0) {
    for (a; a < 1; a++) {
      for (int i = 0; i < 16; i++) {
        if (6 <= i && i <= 9) {
          pad1[i] = 1;
          pad2[i] = 16;
        }
        else {
          pad1[i] = 0;
          pad2[i] = 0;
        }
        if (i == 7)ball[i] = 1;
        else ball[i] = 0;
      }
      x = 8;// set ball cursor to 8
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Press start");
      lcd.setCursor(3, 1);
      lcd.print("button   ->");
    }
    // check whether the start button is pressed
    if (digitalRead(start) == HIGH) {
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("Player");
      lcd.setCursor(0, 1);
      lcd.print("1");
      lcd.setCursor(15, 1);
      lcd.print("2");
      delay(2000);

      for (int i = 3; i > 0; i--) {
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Be ready!");
        lcd.setCursor(8, 1);
        lcd.print(i);
        if (i == 1)buzz_sound(100);
        delay(1000);
      }
      a = 0;
      game = 1;// set game to 1, exits the while loop and starts the game
    }
    delay(100);
  }
  // game starts
  //when P1U is pressed, the pad1 moves up
  if (digitalRead(P1U) == HIGH) {
    pad1Up();
    delay(50);
  }
  //when P1D is pressed, the pad1 moves down
  if (digitalRead(P1D) == HIGH) {
    pad1Down();
    delay(50);
  }
  //when P2U is pressed, the pad2 moves up
  if (digitalRead(P2U) == HIGH) {
    pad2Up();
    delay(50);
  }
  //when P2D is pressed, the pad2 moves down
  if (digitalRead(P2D) == HIGH) {
    pad2Down();
    delay(50);
  }
  //split pad1 array into 2 arrays, pad11 and pad12
  for (int i = 0; i <= 7; i++) {
    player1_1[i] = pad1[i];
  }

  for (int i = 0, j = 8; i <= 7, j <= 15; i++, j++) {
    player1_2[i] = pad1[j];
  }
  //split pad2 array into 2 arrays, pad21 and pad22
  for (int i = 0; i <= 7; i++) {
    player2_1[i] = pad2[i];
  }

  for (int i = 0, j = 8; i <= 7, j <= 15; i++, j++) {
    player2_2[i] = pad2[j];
  }
  //split ball array into 2 arrays, ball11 and ball12
  for (int i = 0; i <= 7; i++) {
    ball1[i] = ball[i];
  }
  for (int i = 0, j = 8; i <= 7, j <= 15; i++, j++) {
    ball2[i] = ball[j];
  }
  //create custom shapes for pad1, pad2 and ball
  lcd.createChar(0, player1_1);
  lcd.createChar(1, player1_2);
  lcd.createChar(2, player2_1);
  lcd.createChar(3, player2_2);
  lcd.createChar(4, ball1);
  lcd.createChar(5, ball2);

  //print pad1, pad2 and ball
  lcd.clear();
  lcd.setCursor(0, 0);// position of scr1
  lcd.print(scr1);
  lcd.setCursor(0, 1);// position of scr2
  lcd.print(scr2);

  lcd.setCursor(3, 0);// position of player1_1
  lcd.write(byte(0));
  lcd.setCursor(3, 1);// position of player1_2
  lcd.write(byte(1));
  lcd.setCursor(15, 0);// position of player2_1
  lcd.write(byte(2));
  lcd.setCursor(15, 1);// position of player2_2
  lcd.write(byte(3));
  lcd.setCursor(x, 0);// position of ball1, x is changed to move the ball on the display
  lcd.write(byte(4));
  lcd.setCursor(x, 1);// position of ball2, x is changed to move the ball on the display
  lcd.write(byte(5));

  // checks whether the ball hits the pad1
  if (x == 3) {
    for (int b = 0; b < 16; b++) {
      if (ball[b] != 0) {
        v1 = ball[b];
        v2 = pad1[b];
      }
    }
    // if ball hits pad1, change direction of ball to R (right)
    if (v1 == v2) {
      direction = 'R';
      scr1 += 1;
      buzz_sound(10);
    }
    // else display the winner
    else {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Game End!");
      lcd.setCursor(4, 1);
      lcd.print("P2 won!");

      // green LED glows for winner and red for looser with buzz electric crystal sound
      for (int i = 0; i < 3; i++) {
        strip1.setPixelColor(0, 255, 0, 0);
        strip1.show();
        strip2.setPixelColor(0, 0, 255, 0);
        strip2.show();
        buzz_sound(500);
        delay(500);
        strip1.setPixelColor(0, 0, 0, 0);
        strip1.show();
        strip2.setPixelColor(0, 0, 0, 0);
        strip2.show();
        delay(500);
      }
      // set scores to 0 and restart the game
      scr1 = scr2 = 0;
      delay(1000);
      game = 0;
    }
  }
  // checks whether the ball hits the pad2
  if (x == 15) {
    for (int b = 0; b < 16; b++) {
      if (ball[b] != 0) {
        v1 = ball[b];
        v3 = pad2[b];
      }
    }
    // if ball hits pad2, change direction of ball to L (left)
    if (v1 == v3) {
      direction = 'L';
      scr2 += 1;
      buzz_sound(10);
    }
    // else display the winner
    else {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Game Ends!");
      lcd.setCursor(4, 1);
      lcd.print("P1 won!");

      // green LED glows for winner and red for looser with buzz electric crystal sound
      for (int i = 0; i < 3; i++) {
        strip1.setPixelColor(0, 0, 255, 0);
        strip1.show();
        strip2.setPixelColor(0, 255, 0, 0);
        strip2.show();
        buzz_sound(500);
        delay(500);
        strip1.setPixelColor(0, 0, 0, 0);
        strip1.show();
        strip2.setPixelColor(0, 0, 0, 0);
        strip2.show();
        delay(500);
      }
      // set scores to 0 and restart the game
      scr1 = scr2 = 0;
      delay(1000);
      game = 0;
    }
  }
  // if direction is L (left), move ball to left
  if (direction == 'L') {
    for (int b = 0; b < 16; b++)
      if (ball[b] == 16) x -= 1;

    if (bounce == 0)
      move_leftDown();
    else
      move_leftUp();
  }
  // if direction is R (right), move ball to right
  if (direction == 'R') {
    for (int b = 0; b < 16; b++)
      if (ball[b] == 1) x += 1;

    if (bounce == 0)
      move_rightDown();
    else
      move_rightUp();
  }
}
//pad1Up function
void pad1Up() {
  if (pad1[0] != 1) {
    int temp = pad1[0], i;
    for (i = 0; i < 16; i++)
      pad1[i] = pad1[i + 1];
    pad1[i] = temp;
  }
}
//pad1Down function
void pad1Down() {
  if (pad1[15] != 1) {
    int temp = pad1[15], i;
    for (i = 15; i > 0; i--)
      pad1[i] = pad1[i - 1];
    pad1[i] = temp;
  }
}
//pad2Up function
void pad2Up() {
  if (pad2[0] != 16) {
    int temp = pad2[0], i;
    for (i = 0; i < 16; i++)
      pad2[i] = pad2[i + 1];
    pad2[i] = temp;
  }
}
//pad2Down function
void pad2Down() {
  if (pad2[15] != 16) {
    int temp = pad2[15], i;
    for (i = 15; i > 0; i--)
      pad2[i] = pad2[i - 1];
    pad2[i] = temp;
  }
}
//move_leftDown function
void move_leftDown() {

  if (ball[15] == 0) {
    int temp = ball[15], i;
    for (i = 15; i > 0; i--)
      ball[i] = ball[i - 1];
    ball[i] = temp;
    move_left();
  }
  else {
    bounce = 1;
    buzz_sound(10);
  }
}
//move_leftUp function
void move_leftUp() {

  if (ball[0] == 0) {
    int temp = ball[0], i;
    for (i = 0; i < 15; i++)
      ball[i] = ball[i + 1];
    ball[i] = temp;
    move_left();
  }
  else {
    bounce = 0;
    buzz_sound(10);
  }
}
//move_rightDown function
void move_rightDown() {

  if (ball[15] == 0) {
    int temp = ball[15], i;
    for (i = 15; i > 0; i--)
      ball[i] = ball[i - 1];
    ball[i] = temp;
    move_right();
  }
  else {
    bounce = 1;
    buzz_sound(10);
  }
}
//move_rightUp function
void move_rightUp() {

  if (ball[0] == 0) {
    int temp = ball[0], i;
    for (i = 0; i < 15; i++)
      ball[i] = ball[i + 1];
    ball[i] = temp;
    move_right();
  }
  else {
    bounce = 0;
    buzz_sound(10);
  }
}
// move_right function
void move_right() {
  for (int b = 0; b < 16; b++) {
    if (ball[b] != 0) {
      if (ball[b] == 16)ball[b] = 8;
      else if (ball[b] == 8) ball[b] = 4;
      else if (ball[b] == 4) ball[b] = 2;
      else if (ball[b] == 2) ball[b] = 1;
      else if (ball[b] == 1) ball[b] = 16;
    }
  }
}
// move_left function
void move_left() {
  for (int b = 0; b < 16; b++) {
    if (ball[b] != 0) {
      if (ball[b] == 1)ball[b] = 2;
      else if (ball[b] == 2) ball[b] = 4;
      else if (ball[b] == 4) ball[b] = 8;
      else if (ball[b] == 8)ball[b] = 16;
      else if (ball[b] == 16)ball[b] = 1;
    }
  }
}
//buzz_sound function
void buzz_sound(int d) {
  analogWrite(buzz, 20);
  delay(d);
  analogWrite(buzz, 0);
}