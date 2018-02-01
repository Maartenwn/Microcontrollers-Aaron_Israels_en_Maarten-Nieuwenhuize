/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** main.c
**
** Beschrijving:	Toggle even PORTD.7 en PORTD.6
** Target:			AVR mcu
** Author: 			maartenwn@gmail.com en aaron.israëls@home.nl
** -------------------------------------------------------------------------*/
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>



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
int main( void )

/* Video = https://www.youtube.com/watch?v=UEXmCrNFxI0 */

/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Looping forever, flipping bits on PORTD.6 and PORTE.7
Version :    	DMK, Initial code
*******************************************************************/
{
	
	DDRD = 0b11111111;			// All pins PORTD are set to output 
	DDRE = 0b11111111;			// All pins PORTE are set to output

	PORTE = 0xFF;	
	
	while (1)
	{
		PORTD = 0x80;
		wait( 500 );				
		PORTD = 0x40;
		wait( 500 );				
	}

	return 1;
}