/*
 * PWMwaveform.c
 *
 * Created: 11-07-2022 18:42:33
 * Author : harsh
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

void PWM_init(){
	TCCR0 = (1<<WGM00) | (1<<WGM01) |  (1<<COM01) | (1<<CS00);
	DDRB|= (1<<PB3);
}

int main(void)
{
    PWM_init();
	unsigned char duty = 100;
    while (1) 
    {
		OCR0 = duty;
    }
}

