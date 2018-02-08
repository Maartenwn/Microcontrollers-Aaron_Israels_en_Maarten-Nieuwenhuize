/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** ioisr.c
**
** Beschrijving:	Light on PORTC walks when pressing PORTD1 and PORTD2 
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ioisr.c
**					avr-gcc -g -mmcu=atmega128 -o ioisr.elf ioisr.o
**					avr-objcopy -O ihex ioisr.elf ioisr.hex 
**					or type 'make'
** Author: 			dkroeske@gmail.com && maartenwn@gmail.com && aaron.israels@home.nl
** -------------------------------------------------------------------------*/
#define F_CPU 8000000																																	

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/******************************************************************/
ISR( INT1_vect )
/* 
short:			ISR INT1
inputs:			
outputs:	
notes:			Set PORTC one futher
Version :    	DMK, Initial code
*******************************************************************/
{
    
	PORTC = PORTC << 1;
	if(PORTC == 0x00){
		PORTC = 0x01;
	}
}

/******************************************************************/
ISR( INT2_vect )
/* 
short:			ISR INT2
inputs:			
outputs:	
notes:			Set PORTC one back
Version :    	DMK, Initial code
*******************************************************************/
{	
    PORTC = PORTC >> 1;
	if(PORTC == 0x00){
		PORTC = 0x80;
	}
	
}

/******************************************************************/
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			https://youtu.be/MbOt8OOggTo
Version :    	DMK, Initial code
*******************************************************************/
{
	// Init I/O
	DDRD = 0x00;			//set PORTD as input
	DDRC = 0xFF;			//set PORTC as output


	// Init Interrupt hardware
	EICRA |= 0x3C;			// INT1 rising edge, INT2 rising edge
	EIMSK |= 0x06;			// Enable INT1 & INT2
	
	// Enable global interrupt system
	//SREG = 0x80;			// Of direct via SREG of via wrapper
	sei();				

	PORTC = 0x01;

	while (1)
	{							

	}

	return 1;
}