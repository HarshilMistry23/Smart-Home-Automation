/*
 * GccApplication1.c
 *
 * Created: 28-06-2022 15:27:01
 * Author : harsh
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL


int main(void)
{
    /* Replace with your application code */
	DDRB=0b00000010;
	
	while(1){
		if (PINB == 00000001)
		{
			
		PORTB=0b00000010;
		//_delay_ms(1000);
	}
	if (PINB == 0b00000000)
	{
		PORTB=0b00000000;
		//_delay_ms(1000);
		
	}
	}
	

}

