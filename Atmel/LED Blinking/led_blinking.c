#include <avr/io.h>
#define F_CPU 16000000L
#include <util/delay.h>

int main(void)
{
	DDRB = 0xff;
	while (1)
	{
		PORTB = 0xff;
		_delay_ms(1000);
		PORTB = 0x00;
		_delay_ms(1000);
	}
}
