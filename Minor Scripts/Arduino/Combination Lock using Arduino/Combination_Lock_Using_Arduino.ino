const int b1 = 2;       // first button is on pin 8
const int b2 = 3;       // second is on pin 9
const int b3 = 4;       // third is pin 10
const int b4 = 5;       // fourth is pin 11
const int b5 = 6;       // third is pin 10
const int b6 = 7;       // fourth is pin 11
const int Red = 8;      // red LED is on pin 4
const int greenLed = 9; // green LED is pin 12

int code[] = {6, 5, 5, 4, 3, 2};
int entered[7];
const int LED[] = {14, 15, 16, 17, 18, 19};

void checkEntered1(int button);

void setup()
{                       // run once at sketch startup
    Serial.begin(9600); // begin Serial

    pinMode(b1, INPUT); // button 1 is an input
    pinMode(b2, INPUT); // button 2 is an inputMi
    pinMode(b3, INPUT); // button 3 is an input
    pinMode(b4, INPUT); // button 4 is an input
    pinMode(b5, INPUT); // button 3 is an input
    pinMode(b6, INPUT); // button 4 is an input

    pinMode(Red, OUTPUT);      // the red LED is an output
    pinMode(greenLed, OUTPUT); // the green LED is an output

    digitalWrite(Red, HIGH); // turn the red LED on

    for (int i = 0; i < 6; i++)
    {                               // work through numbers 0-3
        Serial.println(code[i]);    // print each digit of the code
        Serial.println(entered[i]); // print each element of the entered[]
                                    // array (this was for me to check that it started at 0
        pinMode(LED[i], OUTPUT);
    }
}

void loop()
{ // run repeatedly
    if (digitalRead(b1) == LOW)
    {                     // if b1 is pressed
        checkEntered1(1); // call checkEntered and pass it a 1

        delay(250); // wait, needed for correct functioning, otherwise
                    // buttons are deemed to be pressed more than once
    }
    else if (digitalRead(b2) == LOW)
    {                     // if b2 is pressed
        checkEntered1(2); // call checkEntered1 and pass it a 2

        delay(250); // wait
    }
    else if (digitalRead(b3) == LOW)
    {                     // if b3 is pressed
        checkEntered1(3); // call checkEntered1 and pass it a 3

        delay(250); // wait
    }
    else if (digitalRead(b4) == LOW)
    {                     // if b4 is pressed
        checkEntered1(4); // call checkEntered1 and pass it a 4

        delay(250); // wait
    }
    else if (digitalRead(b5) == LOW)
    {                     // if b4 is pressed
        checkEntered1(5); // call checkEntered1 and pass it a 4

        delay(250); // wait
    }
    else if (digitalRead(b6) == LOW)
    {                     // if b4 is pressed
        checkEntered1(6); // call checkEntered1 and pass it a 4

        delay(250); // wait
    }
}

void checkEntered1(int button)
{ // check the first element of the entered[] array
    digitalWrite(LED[button - 1], HIGH);
    if (entered[0] != 0)
    {                          // if it is not a zero, i.e. it has already been inputted
        checkEntered2(button); // move on to checkEntered2, passing it "button"
    }

    else if (entered[0] == 0)
    {                        // if it is zero, i.e. if it hasn't been defined with a button yet
        entered[0] = button; // set the first element as the button that has been pressed
        Serial.print("1: ");
        Serial.println(entered[0]); // for debugging
    }
}

void checkEntered2(int button)
{ // check the second element of the entered[] array
    digitalWrite(LED[button - 1], HIGH);
    if (entered[1] != 0)
    {                          // if it is not a zero, i.e. it has already been inputted
        checkEntered3(button); // move on to checkEntered3, passing it "button"
    }

    else if (entered[1] == 0)
    {                        // if it is zero, i.e. if it hasn't been defined with a button yet
        entered[1] = button; // set the second element as the button that has been pressed
        Serial.print("2: ");
        Serial.println(entered[1]); // for debugging
    }
}

void checkEntered3(int button)
{ // check the third element of the entered[] array
    digitalWrite(LED[button - 1], HIGH);
    if (entered[2] != 0)
    {                          // if it is not a zero, i.e. it has already been inputted
        checkEntered4(button); // move on to checkEntered4, passing it "button"
    }

    else if (entered[2] == 0)
    {                        // if it is zero, i.e. if it hasn't been defined with a button yet
        entered[2] = button; // set the third element as the button that has been pressed
        Serial.print("3: ");
        Serial.println(entered[2]); // for debugging
    }
}

void checkEntered4(int button)
{ // check the third element of the entered[] array
    digitalWrite(LED[button - 1], HIGH);
    if (entered[3] != 0)
    {                          // if it is not a zero, i.e. it has already been inputted
        checkEntered5(button); // move on to checkEntered4, passing it "button"
    }

    else if (entered[3] == 0)
    {                        // if it is zero, i.e. if it hasn't been defined with a button yet
        entered[3] = button; // set the third element as the button that has been pressed
        Serial.print("4: ");
        Serial.println(entered[3]); // for debugging
    }
}

void checkEntered5(int button)
{ // check the third element of the entered[] array
    digitalWrite(LED[button - 1], HIGH);
    if (entered[4] != 0)
    {                          // if it is not a zero, i.e. it has already been inputted
        checkEntered6(button); // move on to checkEntered4, passing it "button"
    }

    else if (entered[4] == 0)
    {                        // if it is zero, i.e. if it hasn't been defined with a button yet
        entered[4] = button; // set the third element as the button that has been pressed
        Serial.print("5: ");
        Serial.println(entered[4]); // for debugging
    }
}

void checkEntered6(int button)
{ // check the fourth element of the entered[] array
    digitalWrite(LED[button - 1], HIGH);
    if (entered[5] == 0)
    {                        // if it is zero, i.e. if it hasn't been defined with a button yet
        entered[5] = button; // set the final element as the button that has been pressed
        Serial.print("6: ");
        Serial.println(entered[5]); // for debugging
        delay(100);                 // allow time for processing
        compareCode();              // call the compareCode function
    }
}

void compareCode()
{ // checks if the code entered is correct by comparing the code[] array with the entered[] array
    for (int i = 0; i < 6; i++)
    { // these three lines are for debugging
        Serial.println(entered[i]);
    }
    if ((entered[0] == code[0]) && (entered[1] == code[1]) && (entered[2] == code[2]) && (entered[3] == code[3]) && (entered[4] == code[4]) && (entered[5] == code[5]))
    {                                 // if all the elements of each array are equal
        digitalWrite(Red, LOW);       // turn the red LED off
        digitalWrite(greenLed, HIGH); // turn the green LED on
        delay(1000);                  // wait for a bit
        digitalWrite(greenLed, LOW);  // turn the green LED off

        for (int i = 0; i < 7; i++)
        { // this next loop is for debugging
            entered[i] = 0;
        }

        loop(); // return to loop() (not really necessary)
    }

    else
    { // if you (or the intruder) get the code wrong

        digitalWrite(Red, HIGH);
        delay(1000);
        digitalWrite(Red, LOW);
        Serial.println("Red OFF");
        for (int i = 0; i < 7; i++)
        { // this next loop is for debugging
            entered[i] = 0;
        }
    }
    close_all();
}

void close_all()
{
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], LOW);
    digitalWrite(LED[3], LOW);
    digitalWrite(LED[4], LOW);
    digitalWrite(LED[5], LOW);
}