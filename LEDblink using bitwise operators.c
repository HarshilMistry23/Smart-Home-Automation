/*
 * OprblinkLED.c
 *
 * Created: 30-06-2022 18:32:15
 * Author : harsh
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

int main(void)
{
	DDRB |= 1 << 3;
    while (1) 
    {
		PORTB |= 1<<PB3;  //1<<3 can also be written
		_delay_ms(1000);
		
		PORTB &= ~(1<<PB3);
		_delay_ms(1000);
    }
}

