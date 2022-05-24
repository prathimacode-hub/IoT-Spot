#include <LiquidCrystal.h>                    //Library for LCD screen
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);        //Setting LCD pins

#include <IRremote.h>                         //Library for IR sensor and remote
const int RECV_PIN = 6;                       //Setting receiver pin. To take receive input from user
IRrecv irrecv(RECV_PIN);                   
decode_results results;
unsigned long key_value = 0;                  //Setting key value variable to store input value to zero


//Setting up Pin , LCd and serial monitor
void setup()
{
    Serial.begin(9600);
    pinMode(2, INPUT);
    irrecv.enableIRIn();
    irrecv.blink13(true);
    lcd.begin(16, 2);
}

void loop()
{
    if (irrecv.decode(&results))              //If any button is pressed
    {
        lcd.clear();
        if (results.value == 0XFFFFFFFF)      //If nothing is pressed 
        {
            results.value = key_value;       //Set result valur as key_vaue.
        }

        switch (results.value)
        {
            //If input button has the value same as in the cases mentioned below. 
            //Then print the corresponding values.
        case 0xFD00FF:                       
            lcd.print("POWER ON/OFF");       
            break;
        case 0xFD40BF:
            lcd.print("FUNC/STOP");
            break;
        case 0xFD708F:
            lcd.print("ST/REPT");
            break;
        case 0xFD10EF:
            lcd.print("CH-");
            break;
        case 0xFD50AF:
            lcd.print("CH+");
            break;
        case 0xFD20DF:
            lcd.print("|<<");
            break;
        case 0xFD609F:
            lcd.print(">>|");
            break;
        case 0xFDA05F:
            lcd.print(">||");
            break;
        case 0xFD906F:
            lcd.print("-");
            break;
        case 0xFD807F:
            lcd.print("+");
            break;
        case 0xFDB04F:
            lcd.print("EQ");
            break;
        case 0xFD30CF:
            lcd.print("0");
            break;
        case 0xFD08F7:
            lcd.print("1");
            break;
        case 0xFD8877:
            lcd.print("2");
            break;
        case 0xFD48B7:
            lcd.print("3");
            break;
        case 0xFD28D7:
            lcd.print("4");
            break;
        case 0xFDA857:
            lcd.print("5");
            break;
        case 0xFD6897:
            lcd.print("6");
            break;
        case 0xFD18E7:
            lcd.print("7");
            break;
        case 0xFD9867:
            lcd.print("8");
            break;
        case 0xFD58A7:
            lcd.print("9");
            break;
        }
        key_value = results.value;
        irrecv.resume();
    }
}