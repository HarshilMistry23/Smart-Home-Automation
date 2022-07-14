/*
 * BTLed.c
 *
 * Created: 07-07-2022 22:49:19
 * Author : harsh
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

void USART_Init( unsigned int baud )
    {
	    UBRRH = (unsigned char)(baud>>8);
	    UBRRL = (unsigned char)baud;
	    UCSRB = (1<<RXEN)|(1<<TXEN);
	    UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
    }
void USART_Transmit( unsigned char data )
    {
	    while ( !( UCSRA & (1<<UDRE)) )
	    ;
	    UDR = data;
    }
unsigned char USART_Receive( void )
    {
	    while ( !(UCSRA & (1<<RXC)) );
	    return UDR;
    }
int main(void){
	DDRD |= (1<<PD2);
	unsigned char data;
	USART_Init(25);
    while (1) 
    {
		data = USART_Receive();
		if(data == 'T'){
			PORTD |= (1<<PD2);
			}
		else if(data == 'F'){
			PORTD &= ~(1<<PD2);
		}
		
    }
}

