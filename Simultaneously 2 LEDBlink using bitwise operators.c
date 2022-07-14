/*
 * 4LEDblink.c
 *
 * Created: 30-06-2022 22:14:19
 * Author : harsh
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL



int main(void){
	
DDRB |= (1<< PB4 | 1<< PB5 | 1<< PB6 | 1<< PB7);

  
    while (1) 
    {
		PORTB |= (1<< PB4| 1<< PB6); //0bx1x1xxxx
		PORTB &= ~(1<< PB5 | 1<< PB7);//0b0x0xxxxx
		_delay_ms(1000);
		PORTB &= ~(1<< PB4 | 1<< PB6);//0bx0x0xxxx
		PORTB |= (1<< PB5| 1<< PB7);//0b1x1xxxxx
		_delay_ms(1000);
    }
}

