/*
 * UART1.c
 *
 * Created: 04-07-2022 21:09:43
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
int main(void)
{
	unsigned char data;
    USART_Init(25);
    while (1) 
    {
		data = USART_Receive();
		USART_Transmit(data);
		
	 }
}

