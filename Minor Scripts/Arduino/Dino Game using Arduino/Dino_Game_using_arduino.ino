#include <LiquidCrystal.h> //Library for LCD Module

// Defining Pinouts for LCD Module and Arduino Board
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Bitmap Array for the Dino Character
byte dino[8] = {
    0b00000,
    0b00111,
    0b00111,
    0b10110,
    0b11111,
    0b01010,
    0b01010,
    0b00000};

// Bitmap Array for the tree character
byte tree[8] = {
    0b00100,
    0b00101,
    0b10101,
    0b10101,
    0b10111,
    0b11100,
    0b00100,
    0b00000};

const int BUTTON_ENTER = 8;
const int BUTTON_SELECT = 9;

const int MENU_SIZE = 2;
const int LCD_COLUMN = 16;

const int TREE_CHAR = 6;
const int DINO_CHAR = 7;

const String ALPHABET[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

boolean isPlaying = false;
boolean isShowScore = false;
boolean isDinoOnGround = true;

int currentIndexMenu = 0;
int score = 0;
int scoreListSize = 0;
String scoreList[20];

void setup()
{
  // Initialising the LCD Module
  lcd.begin(16, 2);

  // Creating the Dino and the Tree Characters in LCD
  lcd.createChar(DINO_CHAR, dino);
  lcd.createChar(TREE_CHAR, tree);

  Serial.begin(9600);

  // Defining PinModes for the Buttons
  pinMode(BUTTON_ENTER, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
}

void loop()
{
  lcd.clear();
  handleMenu();

  delay(300);
}

void handleMenu()
{
  String menu[MENU_SIZE] = {"START", "SCORE"};

  for (int i = 0; i < MENU_SIZE; i++)
  {
    if (i == currentIndexMenu)
    {
      lcd.setCursor(0, i);
      lcd.print("-> ");
    }

    lcd.setCursor(3, i);
    lcd.print(menu[i]);
  }

  if (digitalRead(BUTTON_SELECT) == LOW)
  {
    currentIndexMenu = currentIndexMenu == 0 ? 1 : 0;
  }

  if (digitalRead(BUTTON_ENTER) == LOW)
  {
    currentIndexMenu == 0 ? startGame() : showScore();
  }
}

void showScore() // Function to show the score of the player
{
  isShowScore = true;
  delay(200);

  int currentIndex = 0;
  const int lastIndex = scoreListSize - 1;

  printScore(currentIndex, lastIndex); // To print the score of the player

  while (isShowScore)
  {
    if (digitalRead(BUTTON_SELECT) == LOW) // Check the button state
    {
      currentIndex = currentIndex < lastIndex ? currentIndex + 1 : 0;
      printScore(currentIndex, lastIndex);
    }

    if (digitalRead(BUTTON_ENTER) == LOW)
    {
      isShowScore = false;
    }

    delay(200);
  }
}

void printScore(int index, int lastIndex)
{
  lcd.clear();

  if (lastIndex == -1)
  {
    lcd.print("NO SCORE");
  }
  else
  {
    lcd.print(scoreList[index]);

    if (index < lastIndex)
    {
      lcd.setCursor(0, 1);
      lcd.print(scoreList[index + 1]);
    }
  }
}

void startGame() // Function to Start the game
{
  isPlaying = true;

  while (isPlaying)
  {
    handleGame();
  }
}

void handleGame()
{
  lcd.clear();

  int buttonPressedTimes = 0;

  int secondPosition = random(4, 9);
  int thirdPosition = random(4, 9);
  int firstTreePosition = LCD_COLUMN;

  const int columnValueToStopMoveTrees = -(secondPosition + thirdPosition);

  for (; firstTreePosition >= columnValueToStopMoveTrees; firstTreePosition--)
  {

    lcd.setCursor(13, 0);
    lcd.print(score);

    defineDinoPosition();

    int secondTreePosition = firstTreePosition + secondPosition;
    int thirdTreePosition = secondTreePosition + thirdPosition;

    showTree(firstTreePosition);
    showTree(secondTreePosition);
    showTree(thirdTreePosition);

    if (isDinoOnGround)
    {
      if (firstTreePosition == 1 || secondTreePosition == 1 || thirdTreePosition == 1)
      {
        handleGameOver();
        delay(5000);
        break;
      }
      buttonPressedTimes = 0;
    }
    else
    {
      if (buttonPressedTimes > 3)
      {
        score -= 3;
      }

      buttonPressedTimes++;
    }

    score++;
    delay(500);
  }
}

void handleGameOver() // Function to handle game over event
{
  lcd.clear();
  lcd.print("GAME OVER");

  lcd.setCursor(0, 1);
  lcd.print("SCORE: ");
  lcd.print(score);

  delay(2000);
  saveScore();
}

void saveScore() // Function to save the player score
{
  lcd.clear();

  String nick = "";
  int nameSize = 0;
  int alphabetCurrentIndex = 0;

  lcd.print("Your Name: ");

  while (nameSize != 3)
  {
    lcd.setCursor(nameSize, 1);
    lcd.print(ALPHABET[alphabetCurrentIndex]);

    if (digitalRead(BUTTON_SELECT) == LOW)
    {
      alphabetCurrentIndex = alphabetCurrentIndex != 25 ? alphabetCurrentIndex + 1 : 0;
    }

    if (digitalRead(BUTTON_ENTER) == LOW)
    {
      nick += ALPHABET[alphabetCurrentIndex];

      nameSize++;
      alphabetCurrentIndex = 0;
    }

    delay(300);
  }

  scoreList[scoreListSize] = nick + " " + score;
  scoreListSize++;

  isPlaying = false;
  score = 0;
}

void showTree(int position) // Function to display the tree character and simulate motion
{
  lcd.setCursor(position, 1);
  lcd.write(TREE_CHAR);

  // clean the previous position
  lcd.setCursor(position + 1, 1);
  lcd.print(" ");
}

void defineDinoPosition()
{
  int buttonState = digitalRead(BUTTON_ENTER);
  buttonState == HIGH ? putDinoOnGround() : putDinoOnAir();
}

void putDinoOnGround() // To set the dino character on the ground
{
  lcd.setCursor(1, 1);
  lcd.write(DINO_CHAR);
  lcd.setCursor(1, 0);
  lcd.print(" ");

  isDinoOnGround = true;
}

void putDinoOnAir() // To move the dino character to air, when the corresponding button state changes
{
  lcd.setCursor(1, 0);
  lcd.write(DINO_CHAR);
  lcd.setCursor(1, 1);
  lcd.print(" ");

  isDinoOnGround = false;
}