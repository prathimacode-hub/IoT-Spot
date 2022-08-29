#define F_CPU 16000000L
#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#define enable            5
#define registerselection 6

static unsigned int pulse = 0;
static unsigned int i = 0;

void send_a_command(unsigned char command) {
    PORTA = command;
    PORTD &= ~ (1<<registerselection);
    PORTD |= 1<<enable;
    _delay_ms(5);
    PORTD &= ~1<<enable;
    PORTA = 0;
}

void send_a_character(unsigned char character) {
    PORTA = character;
    PORTD |= 1<<registerselection;
    PORTD |= 1<<enable;
    _delay_ms(5);
    PORTD &= ~1<<enable;
    PORTA = 0;
}

void send_a_string(char *string_of_characters) {
    while(*string_of_characters > 0)
    {
        send_a_character(*string_of_characters++);
    }
}

 ISR(INT0_vect) {
    if (i==1)
    {
        pulse=TCNT1;
        TCNT1=0;
        i=0;
        TCCR1B = 0;
    }
    if (i==0)
    {
        TCCR1B|=5;
        i=1;
    }
}

int main(void) {   
    DDRA = 0xff;
    DDRD = 0b11111011;
    _delay_ms(50);
    GICR|=(1<<INT0); //enabling interrupt0
    MCUCR|= 1 ;  //setting interrupt triggering logic change
    TCCR1A = 0;
    int16_t COUNTA = 0;
    char SHOWA [16];
    send_a_command(0x01); //Clear Screen 0x01 = 00000001
    _delay_ms(8);
    send_a_command(0x38); 
    _delay_ms(8);
    send_a_command(0x0C); // display on, cursor blinking
    _delay_ms(8);
    sei(); // enables global interrupts

    while(1) {
        PORTD &=~(1<<PIND0);
        _delay_us(2);
        PORTD|=(1<<PIND0);
        _delay_us(15);
        PORTD &=~(1<<PIND0);
        _delay_us(10);
        COUNTA = pulse*1.094;
        send_a_command(0x80);
        send_a_string ("DISTANCE=");
        itoa(COUNTA,SHOWA,10);
        send_a_string(SHOWA);
        send_a_string ("cm    ");
        send_a_command(0x80 + 0);
    }
}
