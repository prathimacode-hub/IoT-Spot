#include <LiquidCrystal.h>    //Library for LCD screen
#include <Keypad.h>          //Library for keypad

const byte rows = 4;          //defining rows
const byte cols = 4;          //defining columns

char keys[rows][cols] = {     //matrix of keys on keypad

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

//Setting Pins

byte rowPins[rows] = { 0, 1, 2, 3 };
byte colPins[cols] = { 4, 5, 6, 7 }; 

//Mapping keypad keys 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols ); 

//Setting lcd  pins
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//defining variables
 long Num1,Num2,total;
 char key,action;
 boolean result = false;
 

 //Setting up
void setup() {
lcd.begin(16, 2);               // start lcd
 lcd.setCursor(0, 1);  
   delay(2000); 
    lcd.clear();  
}

void loop() {
  

key = kpd.getKey();       //getting input from keypad
if (key!=NO_KEY)          //If key is pressed run detectbuttons function
DetectButtons();

if (result==true)         //If above function return true, run resultcal and resultdis functions
resultcal();

resultdis();   
}

void DetectButtons()            //DetectButtons function
{ 
     lcd.clear();     
    if (key=='*')               // if '*' is pressed, set operands to 0. i.e. reset
    { 
        
        total=Num1=Num2=0; result=false;
        
    }

    //For keys from 1 to 9.
    //If respective key is detected, it will get add to a variable total.
    //For multiple digit numbers, we are multiplying total by 10 and adding the given key in it.
    
     if (key == '1')            
    { 


    if (total==0)
    total=1;
    else
    total = (total*10) + 1; 


    }
    
     if (key == '4') 
    {


    if (total==0)
    total=4;
    else
    total = (total*10) + 4; 


    }
    
     if (key == '7') 
    {


    if (total==0)
    total=7;
    else
    total = (total*10) + 7; 


    } 
  

    if (key == '0')
    { 


    if (total==0)
    total=0;
    else
    total = (total*10) + 0; 
    }
    


     if (key == '2') 
    {
     if (total==0)
    total=2;
    else
    total = (total*10) + 2; 
    }
    


     if (key == '5')
    {
     if (total==0)
    total=5;
    else
    total = (total*10) + 5; 
    }
    


     if (key == '8')
    {
     if (total==0)
    total=8;
    else
    total = (total*10) + 8; 
    }   
  



    if (key == '#')
    { 
    Num2=total;
    result = true;
    }
    


     if (key == '3')
    {
     if (total==0)
    total=3;
    else
    total = (total*10) + 3; 
    }
    


     if (key == '6')
    { 
    if (total==0)
    total=6;
    else
    total = (total*10) + 6; 
    }
    


     if (key == '9')
    {
    if (total==0)
    total=9;
    else
    total = (total*10) + 9; 
    }  


    //Setting remaining keys for operators.


      if (key == 'A' || key == 'B' || key == 'C' || key == 'D') 
  {
    Num1 = total;    
    total =0;
    if (key == 'A') action = '+';
    if (key == 'B') action = '-';
    if (key == 'C') action = '*';
    if (key == 'D') action = '/';

    delay(100);
  }
  
}


   //If operator keys are pressed , respective action will occur. 
void resultcal()
{
  if (action=='+')
    total = Num1+Num2;


  if (action=='-')
    total = Num1-Num2;


  if (action=='*')
    total = Num1*Num2;


  if (action=='/')
    total = Num1/Num2;

}


//function to display result on lcd screen


void resultdis()
{



  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print(Num1); lcd.print(action); lcd.print(Num2); 
  


 
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(total); //Display the result
}