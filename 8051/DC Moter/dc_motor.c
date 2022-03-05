#include<reg51.h>

sbit switch1 = P1^0;//clockwise rotation for both motor
sbit switch2 = P1^1;//clockwise rotation for right motor only
sbit switch3 = P1^2;//clockwise rotation for left motor only
sbit switch4 = P1^3;//anticlockwise rotation for both motor
sbit switch5 = P1^4;//stop rotation (made it always one so that if all switch is off then motor will be in off condition else in on condition)

void delay(void)
{
	unsigned int i;
	for(i=0;i<0xFF;i++);
}
void main()
{
	P1 = 0x00;
	P2 = 0x00;
	
	while(1)
	{
		if(switch1 == 1)
		{
			P2 = 0x09;
		}
		
		if(switch2 == 1)
		{
			P2 = 0x04;
		}
		
		if(switch3 == 1)
		{
			P2 = 0x01;
		}
		
		if(switch4 == 1)
		{
			P2 = 0x06;
		}
		
		if(switch5 == 1)
		{
			P2 = 0x00;
		}
	}
}