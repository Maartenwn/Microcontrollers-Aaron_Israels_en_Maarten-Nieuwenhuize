/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** main.c
**
** Target:			AVR mcu
** Author: 			maartenwn@gmail.com en aaron.israëls@home.nl
** -------------------------------------------------------------------------*/
#define F_CPU 8000000

typedef struct {
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT;

PATTERN_STRUCT pattern[] = {
	{0x07, 100}, {0x0E, 100}, {0x1C, 100}, {0x38, 100}, {0x70, 100}, {0xE0, 100}, {0xC1, 100}, {0x83, 100}, {0x00, 0}
};	


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


/*		https://youtu.be/2xQ5p_-oRwI
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Looping forever, showing a preprogrammed pattern
Version :    	DMK, Initial code
*******************************************************************/
{
	DDRD = 0b11111111;			// All pins PORTD are set to output 
		
	while (1)
	{
		int index =0;
		while(pattern[index].delay != 0){
			PORTD = pattern[index].data;
			wait(pattern[index].delay);
			index++;
		}	
		
	}

	return 1;
}