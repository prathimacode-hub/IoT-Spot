 int ledArray[] = {12, 9, 5, 2};// ledArray[0] is green, ledArray[1] is red, ledArray[2] is yellow, and ledArray[3] is blue. 
 int buttonArray[] = {13, 10, 6, 3};// buttonArray[0] is green, buttonArray[1] is red, buttonArray[2] is yellow, and buttonArray[3] is blue. 
 int pinCount = 4; //both ledArray and buttonArray have same pinCount --> use this for both buttons and leds
 int buzzer = 8;
 
 int ledState = 0;
 int gameState = 0;

 #define NUMBERTOWIN 5 //Number of lights you have to match to win --> You can change this number to make the game more or less challenging to win
 int gameValues[NUMBERTOWIN];
 int roundNum = 0;

 unsigned long previousMillis = 0; //need this for pre-game state for flashing lights without delay --> if you use delay your button push to start game may not be noticed
 unsigned long interval1 = 500; //need this for time between blinks
 
//declare functions
void setLed(int ledNum);
void displayClue(int roundNum);
boolean waitForInput(int buttonNum);
 
void setup () {
Serial.begin(9600);

Serial.println("setup");
 
  for(int Pin = 0; Pin < pinCount; Pin++) // initial pin is zero which corresponds to green, if the pin is less than 4 (pinCount) then add one, which would make the pin number 1 and correspond to red etc...
  {
  //set all leds to output
  pinMode(ledArray[Pin], OUTPUT);
  }
    
  for(int Pin = 0; Pin < pinCount; Pin++)
  {
  //set all buttons to input using pullup resistor built into board 
  //I decided to add 10K resistors to the buttons after writing the code, you can change the code to use the external resistors, but it's not necessary
  pinMode(buttonArray[Pin], INPUT_PULLUP);
  }
 
 //if analog input pin 0 is unconnected
 //random analog noise will cause the call to randomSeed() to generate
 //different seed numbers each time the sketch runs
 //randomSeed() will shuffle the random function that we call during gameplay
 randomSeed(analogRead(0));
 }

void loop () {
  
  if (gameState == 0)
  {
     int button0 = digitalRead(buttonArray[0]);
     int button1 = digitalRead(buttonArray[1]);  
     int button2 = digitalRead(buttonArray[2]); 
     int button3 = digitalRead(buttonArray[3]); 
     
    //if no buttons are pressed (since button input is pullup we show all buttons pressed) then play pre_game
    if (button0 && button1 && button2 && button3)
    {
      pre_game();
    }
    // if a button is pressed set up for the game
    else
    {
      Serial.println("button Pressed"); 
      //turn leds off before starting game --> function setLed() states that if ledNum is <0 led is LOW
      setLed(-1);
      //set the round number to zero so you start on the first round
      roundNum = 0;
      delay (1000);
      //set gameState to 1 
      gameState = 1;
    }
  }

  if (gameState == 1)
  {
    gamePlay();
  }
  
  if (gameState == 2)
  {
    //You win!! - play winning sound and scroll through leds (winDisplay)3 times followed by lose display once for good transition.
    //delay to give player time to release button press before winning sound plays
    delay(500);
    winning_sound();
    winDisplay();
    winDisplay();
    winDisplay();
    loseDisplay();
    Serial.println("winDisplay");
    //delay briefly before running pre_game
    delay (1000);
    //reset gameState to zero to call pre_game
    gameState = 0;
  }
  
  if (gameState == 3)
  {
    //You lose :( - play losing sound and flash leds (loseDisplay)3 times for good transition.
    //delay to give player time to release button press before losing sound plays
    delay(500);
    losing_sound();
    loseDisplay();
    loseDisplay();
    loseDisplay();
    Serial.println("loseDisplay");
     //delay briefly before running pre_game
    delay (1000);
    //reset gameState to zero to call pre_game
    gameState = 0;
  } 
}

//pre_game
void pre_game()
{
  //Check if enough time has elapsed between leds lighting up
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval1)
  {
  //if enough time has elapsed update lights
  if (ledState == 0)
  {
    Serial.println("pre green");
    setLed(0);
    ledState = 1;
  }
  else if (ledState == 1)
  {
    Serial.println("pre red");
    setLed(1);
    ledState = 2;
  }
  else if (ledState == 2)
  {
    Serial.println("pre yellow");
    setLed(2);
    ledState = 3;
  }
  else if (ledState == 3)
  {
    Serial.println("pre blue");
    setLed(3);
    ledState = 0;
  }
  //reset time 
  previousMillis = currentMillis;
  }
}

//function for while game is playing
void gamePlay()
{
  Serial.println("gamePlay");
  //pre-load array with random numbers for game
  for ( int i=0; i<NUMBERTOWIN; i++)
  {
    //use floor to round number down to nearest integer and random to choose random numbers from 0 to 3 to put in the gameValues array.
    gameValues[i] = floor(random(0,4));
    Serial.println(gameValues[i], DEC);
  }

  
  Serial.print("Starting Round ");
  Serial.println(roundNum, DEC);
  for (int r=0; r<NUMBERTOWIN; r++)
  {
    displayClue(roundNum);
  
    for (int i=0; i<=roundNum; i++)
    {      
      Serial.print("Wainting for input ");
      Serial.print(i+1, DEC);
      Serial.print(" of ");
      Serial.print(roundNum+1, DEC);
      Serial.println("");
  
      //wait for user input and see if they're correct, if correct wait for next input etc.. if not correct, fail
      if (waitForInput(gameValues[i]))
      {
        //correct input
        if (i==roundNum)
        {
          Serial.println("Correct");
          //check if final round 
          if (roundNum == NUMBERTOWIN-1)
          {
            Serial.println("You Win!");
           // you won! 
           // set gameState to 2 to run winning fuction
           gameState = 2;
           return;
          }
          else 
          {
            Serial.println("Continue");
          }
        }
      }
      else 
      {
        //incorrect input
        Serial.println("You Lose!");

        // you lost :(
        // set gameState to 3 to run losing function
        gameState = 3;
        return;
      }
    }
    //User made it through the round, increment round number to continue
    roundNum++;
    //Delay briefly so user has time to see start of next clue
    delay(1000);
  }
}

void setLed(int ledNum)
{
  //if the led number is less than zero turn all the leds off
  if (ledNum<0)
  {
   for (int i = 0; i<pinCount; i++)
   {
   digitalWrite(ledArray[i], LOW);
   }
  }
  else
  {
    //turn on the specified led, turn off the other leds
    //turn one and only one led on - if i is the same as the number passed in from pre-game then turn on that light, if it is not the same turn off that light 
    for (int i = 0; i<pinCount; i++)
    {
      if (i == ledNum)
      {
        digitalWrite(ledArray[i], HIGH);
      }
      else 
      {
        digitalWrite(ledArray[i], LOW);
      }
    }
  }
 }


 void displayClue(int roundNum)
 {
  //turn all lights off
  setLed(-1);
  for (int i=0; i<=roundNum; i++)
  {
    //turn on led that matches current round
    setLed(gameValues[i]);
    delay(750);
    setLed(-1);
    delay(250);
  }
 }

boolean waitForInput(int buttonNum)
{
  //read all the buttons continuously until a button is pressed, if a button is pressed check if it's correct and if so return true. if not, return false. 
  while(true) 
  {
   int button0 = digitalRead(buttonArray[0]);
   int button1 = digitalRead(buttonArray[1]);  
   int button2 = digitalRead(buttonArray[2]); 
   int button3 = digitalRead(buttonArray[3]); 
   
   //because we are using input_pullup ! indicted a button is pressed --> if any button is pressed go to the rest of the code
   if (!button0 || !button1 || !button2 || !button3)
   {
      //Delay briefly to avoid double counting button press
      delay(250);

      //light up the corresponding led when a button is pressed
      if (buttonNum == 0)
      {
        digitalWrite(ledArray[0], HIGH);
        delay(250);
        digitalWrite(ledArray[0], LOW);
      }
      else if (buttonNum == 1)
      {
        digitalWrite(ledArray[1], HIGH);
        delay(250);
        digitalWrite(ledArray[1], LOW);
      }
      else if (buttonNum == 2)
      {
        digitalWrite(ledArray[2], HIGH);
        delay(250);
        digitalWrite(ledArray[2], LOW);
      }
      else if (buttonNum == 3)
      {
        digitalWrite(ledArray[3], HIGH);
        delay(250);
        digitalWrite(ledArray[3], LOW);
      }
      
      //check if correct button was pressed
      if (buttonNum == 0 && button0 == 0)
      {
        Serial.println("0 Pressed");
        return true;
      }
      else if (buttonNum == 1 && button1 == 0)
      {
        Serial.println("1 Pressed");
        return true;
      }
      else if (buttonNum == 2 && button2 == 0)
      {
        Serial.println("2 Pressed");
        return true;
      }
      else if (buttonNum == 3 && button3 == 0)
      {
        Serial.println("3 Pressed");
        return true;
      }
      else
      {
        return false;
      }
    }
  }
}

//after win - have lights scroll quickly
void winDisplay()
{
digitalWrite(ledArray[0], HIGH);
delay(75);
digitalWrite(ledArray[0], LOW);
delay(75);
digitalWrite(ledArray[1], HIGH);
delay(75);
digitalWrite(ledArray[1], LOW);
delay(75);
digitalWrite(ledArray[2], HIGH);
delay(75);
digitalWrite(ledArray[2], LOW);
delay(75);
digitalWrite(ledArray[3], HIGH);
delay(75);
digitalWrite(ledArray[3], LOW);
delay(75);
digitalWrite(ledArray[2], HIGH);
delay(75);
digitalWrite(ledArray[2], LOW);
delay(75);
digitalWrite(ledArray[1], HIGH);
delay(75);
digitalWrite(ledArray[1], LOW);
delay(75);
digitalWrite(ledArray[0], HIGH);
delay(75);
digitalWrite(ledArray[0], LOW);
delay(75);
}

void winning_sound(void)
{
  //tone (pin number, frequency - I looked this up online to find the frequency for the notes I wanted, duration of tune)
  Serial.println("buzzer1");
  tone(buzzer, 294, 250);
  delay(200);
  tone(buzzer, 294, 250);
  delay(200);
  tone(buzzer, 294, 250);
  delay(200);
  tone(buzzer, 392, 500);
  delay(500);
  Serial.println("second 392");
  tone(buzzer, 392, 250);
  delay(200);
  tone(buzzer, 440, 250);
  delay(200);
  tone(buzzer, 392, 250);
  delay(200);
  tone(buzzer, 440, 250);
  delay(200);
  tone(buzzer, 494, 500);
}


void loseDisplay()
{
  digitalWrite(ledArray[0], HIGH);
  digitalWrite(ledArray[1], HIGH);
  digitalWrite(ledArray[2], HIGH);
  digitalWrite(ledArray[3], HIGH);
  delay(200);
  digitalWrite(ledArray[0], LOW);
  digitalWrite(ledArray[1], LOW);
  digitalWrite(ledArray[2], LOW);
  digitalWrite(ledArray[3], LOW);
  delay(200);
}

void losing_sound(void)
{
  Serial.println("losing_sound");
  tone(buzzer, 98, 250);
  delay(250);
   tone(buzzer, 93, 250);
  delay(250);
   tone(buzzer, 87, 250);
  delay(250);
}