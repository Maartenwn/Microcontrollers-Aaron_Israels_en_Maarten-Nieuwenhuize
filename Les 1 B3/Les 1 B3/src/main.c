/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** main.c
**
** Beschrijving:	Flash PORTD.7 when PORTC.0 is pressed
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
notes:			Looping forever, flipping bits on PORTD.7 when portc.0 is pressed
Version :    	DMK, Initial code
*******************************************************************/
{
	DDRD = 0b11111111;			// All pins PORTD are set to output 
	DDRC = 0b11111111;
		
	while (1)
	{
		if(PINC % 2){
			PORTD = 0x80;
			wait(50);
			PORTD = 0x00;
			wait(50);
		}			
	}

	return 1;
}