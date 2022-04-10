#include<reg51.h>
#include<string.h>
#define lcdport P2
sbit rs=P3^4;
sbit rw=P3^5;
sbit en=P3^6;
sbit m1=P3^0;
sbit m2=P3^1;
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
char uid[]="12345";
char id[5];

void lcdint();
void user_id(char);
void lcdstring(char *);
void delay(int);
void lcdcmd(char);
void lcddata(char);
void check_id();
char scankey();
char check();
void door_open();
void door_close();

void main()
{
int n;
char key;
P2=0x00;
P1=0xff;
lcdint();
lcdstring("Door Locked");  //display on lcd
lcdcmd(0xc0);
lcdstring("enter Password");//display on lcd
delay(100);
lcdcmd(0x01);
lcdcmd(0x02);
lcdstring("Password");
lcdcmd(0xc0);
n=0;
while(n<5)     //Take input from the user
{
key=check();
id[n]=key;
lcddata(key);
delay(100);
n++;
}
lcdcmd(0x01);
lcdcmd(0x02);
if(strcmp(uid,id)==0) //check if the entered password is same as that of password
{
lcdstring("pwd matched");
delay(200);
door_open();
delay(600);
door_close();
lcdcmd(0x01);
lcdcmd(0x02);
}
else
{
lcdstring("Try Again");
delay(200);
lcdcmd(0x01);
lcdcmd(0x02);
}
}
void door_open() //door opening
{
lcdcmd(0x01);
lcdcmd(0x02);
lcdstring("opening door...");
m1=1;
m2=0;
}
void door_close()      //door closing
{
lcdcmd(0x01);
lcdcmd(0x02);
lcdstring("closing door..."); 
m1=1;
m2=0;
m1=0;
m2=1;
delay(400);
m1=0;
m2=0;
}
char check()
{
char b='a';
while(b=='a')
{
b=scankey();
}
return b;

}
char scankey() //read and store the key pressed by user
{
c1=c2=c3=1;
r1=r2=r3=r4=0;
r1=0;r2=r3=r4=1;
if(c1==0) //key 1 pressed
{
delay(2);
return '1';
}
if(c2==0)    //key 2 pressed
{
delay(2);
return '2';
}
if(c3==0)     //key 3 pressed
{
delay(2);
return '3';
}
r2=0;r1=r3=r4=1;
if(c1==0) //key 4 pressed
{
delay(2);
return '4';
}
if(c2==0)//key 5 pressed
{
delay(2);
return '5';
}
if(c3==0)//key 6 pressed
{
delay(2);
return '6';
}
r3=0;r1=r2=r4=1;
if(c1==0)//key 7 pressed
{
delay(2);
return '7';
}
if(c2==0)//key 8 pressed
{
delay(2);
return '8';
}
if(c3==0)//key 9 pressed
{
delay(2);
return '9';
}
r4=0;r1=r2=r3=1;
if(c1==0)//key * pressed
{
delay(2);
return '*';
}
if(c2==0)//key 0 pressed
{
delay(2);
return '0';
}
if(c3==0)//key # pressed the value is taken as a
{
delay(2);
return '#';
}
return 'a';
}
void lcdstring(char *p)
{
while(*p!='\0')
{
lcddata(*p);
delay(10);
p++;
}
}
void lcdint()
{
lcdcmd(0x38);
delay(2);
lcdcmd(0x01);
delay(2);
lcdcmd(0x80);
delay(2);
lcdcmd(0x0e);
delay(2);
}
void delay(int x)
{
int i,j;
for(i=0;i<x;i++)
for(j=0;j<1275;j++);
}
void lcdcmd(char a)
{
lcdport=a;
rs=0;
rw=0;
en=1;
delay(1);
en=0;
}
void lcddata(char value)
{
lcdport=value;
rs=1;
rw=0;
en=1;
delay(1);
en=0;
}
