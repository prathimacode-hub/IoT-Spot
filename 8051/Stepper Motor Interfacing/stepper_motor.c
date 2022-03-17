#include<reg51.h>


sbit sw = P1^1;//input turn on/off the stepper motor
sbit sws = P1^0;//input for changing the direction of the stepper motor
void delay(int ms)//delay function
{
	unsigned int i, j;
	for(i = 0; i<ms; i++)
	{ 
		// Outer for loop for given milliseconds value
		for(j = 0; j< 1275; j++)
		{
			//execute in each milliseconds;
		}
	}
}

void main()
{
	
	int rot_angle[] = {0x0C,0x06,0x03,0x09};
	int i;
	//initialize
	sw=0;
	sws=0;
	P2 = 0x00;
	
	while(1)
	{
		if(sws==1)//turn on
	{
		if(sw == 1)//clockwise
		{
			for(i=3;i>=0;i--)
			{
				P2 = rot_angle[i];
				delay(100);
			}
		}
			
		else if(sw == 0)//anti clockwise
		{
			for(i = 0; i<4; i++)
		{
			P2 = rot_angle[i];
			delay(100);
		}
		}
	}
	else //turn off
		P2=0x00;
	
	}
	
}