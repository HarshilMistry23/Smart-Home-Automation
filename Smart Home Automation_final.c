/*
 * BTFan.c
 *
 * Created: 11-07-2022 19:35:16
 * Author : harsh
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
void USART_Init( unsigned int baud )
{
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}
void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}
int main(void)
{
	unsigned char duty = 64, rec;
    DDRB |= (1<<PB0) | (1<<PB2);
	DDRD |= (1<<PD2);
	PWM_init();
	USART_Init(25);
	
    while (1) 
    {
		rec = USART_Receive();
		if(rec == 'L'){
			PORTD |= (1<<PD2);
		}
		if(rec == 'B'){
			PORTD &= ~(1<<PD2);
		}
		if(rec == 'O'){
			PORTB |= (1<<PB2);
			PORTB &= ~(1<<PB0);
			OCR0 = duty ;
	    }
		if (rec == 'I'){
			duty = duty + 10;
			OCR0 = duty;
		}
		if (rec == 'D'){
			duty = duty - 10;
			OCR0 = duty;
		}
		if (rec == 'F'){
            PORTB &= ~(1<<PB2);
			PORTB &= ~(1<<PB0);
			OCR0 = 0;
		}
		
}
}

