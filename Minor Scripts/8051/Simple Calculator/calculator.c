#include <reg51.h>
#include <stdio.h>

sbit EN = P3^2; // Enable LCD
sbit RW = P3^3; // Read Write 
sbit RS = P3^4; // Register Select

sbit c4 = P1^0;     // Connecting keypad to Port 1
sbit c3 = P1^1;
sbit c2 = P1^2;
sbit c1 = P1^3;
sbit r4 = P1^4;
sbit r3 = P1^5;
sbit r2 = P1^6;
sbit r1 = P1^7;

// all functions
void init();//initialize lcd
void cmd(unsigned int);//send command to lcd
void write_data(unsigned char);//write no on lcd
void delay(unsigned char );//Function for generation of delay
void msDelay(unsigned int);//provide milli second delay
char process_key(int,int,int,int,char,char,char,char);// Process and check the press of key
void num_generator(char,int *);// generate result and store it in result variable;
void write_result(int,char);//send result to lcd

void main()
{
int i,j,* operand ,operand1=0,operand2=0,result=0;
int arr[4][4] = {{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}};
char key,operator1='a',negative='N';
char carr[4][4] = {{'7','4','1','o'},{'8','5','2','0'},{'9','6','3','='},{'/','*','-','+'}},error[5]={'E','R','R','O','R'};
 P1 = 0xff;
operand = &operand1;//initialize operand pointer to operand1's address
while(1)
{
for(i=0;i<4;i++)//select btn pressed row
 {
   key = process_key(arr[i][0],arr[i][1],arr[i][2],arr[i][3],carr[i][0],carr[i][1],carr[i][2],carr[i][3]);
   if(key=='/'||key=='*'||key=='-'||key=='+')
   {
    operand = &operand2;//shift pointer to operand2
    operator1 = key;//store key value in operator1
   }
   if((key != 'Z')&&(key!= '=')&&(key!= '/')&&(key!= '*')&&(key!= '-')&&(key!= '+'))
   {
    num_generator(key,operand);
   }
   // generate result and store it in result variable;
   if(key == '=')
   {
    if(operator1== '*')
    result = operand1*operand2;
    
    if(operator1== '/')
    if(operand2==0)
    {
     cmd(0xC0);//shift the cursor to 2nd row
     for(j=0;j<10;j++)
     write_data(error[j]);
     msDelay(500);
     init();
    }
    else
     result = operand1/operand2;
    if(operator1== '-')
    {
    if (operand1>operand2)
    result = operand1-operand2;
    else
    {
    result = operand2-operand1;
    cmd(0xC0); //0xco is lcd command which force the cursor to begin with 2nd row
    negative = 'Y';
    }
    }
    
    if(operator1== '+')
    result = operand1+operand2;
    
    write_result(result,negative);//function call
   }
 }
}
}

// LCD initilaizer function
void init()
{
 delay(3500);
 cmd(0x38);//function set 8-bit ,2line,5X7 dots
 delay(3500);
 cmd(0x38);//function set 8-bit ,2line,5X7 dots
 delay(3500);
 cmd(0x38);//function set 8-bit ,2line,5X7 dots
 delay(350);
 cmd(0x38);//function set 8-bit ,2line,5X7 dots
 cmd(0x1C);//Shift entire display right
 cmd(0x0E);//display on , cursor on
 cmd(0x06);//entry mode
 cmd(0x01);//clear display screen
 delay(3500);
 cmd(0x00);
 main();
}

// Sends different commands to LCD
void cmd(unsigned int comm)
{
 RW = 0;
 RS = 0;
 P2 = comm; //stores command in p2 
 EN = 1;
 delay(3500);
 EN = 0;
}

// Process and check the press of key
char process_key(int a,int b,int c,int d,char A,char B,char C,char D)
{
 char ch = 'Z';
 c4 = a;
 c3 = b;
 c2 = c;
 c1 = d;
 
 if(r4==0)
 {
  ch = A;
 }
 if(r3==0)
 {
  ch = B;
 }
 if(r2==0)
 {
  ch = C;
 }
 if(r1==0)
 {
  if (D == 'o')
  init();
  else
   ch = D;
 }
 if(ch!= 'Z')
 {
  write_data(ch);
  msDelay(100);
 }
 return ch;
}

// Used to write data in charactor on LCD
void write_data(unsigned char ch)
{
  RW = 0;
  RS = 1;
  P2 = ch;
  EN = 1;
  delay(3500);
  EN = 0;
}

void num_generator(char ch,int *operand)//convert charactor to int
{
int digit;
digit = ch - '0';
*operand = digit + (*operand*10);
}

void write_result(int num,char neg)//print result on lcd
{
 int i=0,j,rem;
 char rev_num[20];
 cmd(0xC0);
 if(neg == 'Y')//negetive sign for neg number
 {
 write_data('-');
 }
 do
    {
    rem = num%10;
    num = num /10;
    rev_num[i] = (char)rem+'0';
    i++;
    }while(num>0);
  for(j=i-1;j>=0;j--)
    {
      RW = 0;
   RS = 1;
   P2 = rev_num[j];
   EN = 1;
   delay(3500);
   EN = 0;  
    }
}

//Function for generation of delay
void delay(unsigned char c)
{
unsigned int i;
unsigned char j;
for(i=0;i<=3;i++)
{
for(j=0;j<=c;j++); 
}
}

// Generates delay in milli seconds
void msDelay(unsigned int time)
{
 TL0 = 0xEF;     
 TH0 = 0xAF;      
 TR0 = 1;
 while(time--)
 {
  while(TF0 == 0);
  TF0 = 0;
  TL0 = 0xEF;     
  TH0 = 0xAF;      
 }
 TR0 = 0;
}