#include<LiquidCrystal.h>   //library for lcd

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //initializing lcd pins to analog pins

//initializing button pins
int S1=7;
int S2=6;
int S3=5;
int S4=4;
int S5=3;
//initial vote for each four canidates.
int vote1 = 0;
int vote2 = 0;
int vote3 = 0;
int vote4 = 0;
void setup()
{
    //for taking input from buttons
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  //starting lcd
  lcd.begin(16, 2);
  lcd.print("EVM ");

  delay(4000);
  // initially setting buttons to high state
 digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  digitalWrite(S4, HIGH);
  digitalWrite(S5, HIGH);
  lcd.clear();
  //printing candidate names on lcd
  lcd.setCursor(1, 0);  lcd.print("A");
  lcd.setCursor(5, 0); lcd.print("B");
  lcd.setCursor(9, 0);  lcd.print("C");
  lcd.setCursor(13, 0);  lcd.print("D");
}
void loop()
{
    //displaying candidate name and number of votes(below names)
  lcd.setCursor(1, 0);  lcd.print("A");
  lcd.setCursor(1, 1); lcd.print(vote1);
  lcd.setCursor(5, 0); lcd.print("B");
  lcd.setCursor(5, 1); lcd.print(vote2);
  lcd.setCursor(9, 0); lcd.print("C");
  lcd.setCursor(9, 1); lcd.print(vote3);
  lcd.setCursor(13, 0); lcd.print("D");
  lcd.setCursor(13, 1); lcd.print(vote4);
  //when the button is pressed incresing respective vote amount by one
  if (digitalRead(S1) == 0)
    vote1++; 
  while (digitalRead(S1) == 0);
  if (digitalRead(S2) == 0)
    vote2++;
  while (digitalRead(S2) == 0);
  if (digitalRead(S3) == 0)
    vote3++;
 while (digitalRead(S3) == 0);
  if (digitalRead(S4) == 0)
    vote4++;
 while (digitalRead(S4) == 0);
 //when result button is pressed
  if (digitalRead(S5) == 0)
  {
      //total votes
    int vote = vote1 + vote2 + vote3 + vote4;
    // if voting is done
    if (vote)
    {
        //if voting for A candidate is grater than other 
        // Him as a winner will be printed on lcd
      if ((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
      {
        lcd.clear();
        lcd.print("A is Winner");
        delay(3000);
        lcd.clear();
      }
      //if voting for B candidate is grater than other 
        // Him as a winner will be printed on lcd
      else if ((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
      {
        lcd.clear();
        lcd.print("B is Winner");
        delay(3000);
        lcd.clear();
      }
      //if voting for C candidate is grater than other 
        // Him as a winner will be printed on lcd
      else if ((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
      {
        lcd.clear();
        lcd.print("C is Winner");
        delay(3000);
        lcd.clear();
      }
      //if voting for D candidate is grater than other 
        // Him as a winner will be printed on lcd
      else if (vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
      {
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("D is Winner");
        delay(3000);
        lcd.clear();
      }
        //in other cases it will be a tie
      else
      {
        lcd.clear();
        lcd.print(" Tie ");
        lcd.clear();
      }

    }
    //else
    else
    {
      lcd.clear();
      lcd.print("No Voting");
      delay(3000);
      lcd.clear();
    }
    vote1 = 0; vote2 = 0; vote3 = 0; vote4 = 0, vote = 0;
    lcd.clear();
  }
}