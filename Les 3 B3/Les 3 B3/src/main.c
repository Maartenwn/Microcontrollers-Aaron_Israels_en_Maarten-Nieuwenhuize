/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#define F_CPU 8 * 10 ^6
#include <avr/io.h>
#include <stdio.h>
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

int msCount = 0;
int shouldHigh = 1;

ISR( TIMER2_COMP_vect )
{
	msCount++;
	// Increment ms counter
	if(shouldHigh && 15 == msCount){
		PORTD = 0x00;
		msCount = 0;
		shouldHigh = 0;
		}else if(25 == msCount){
		PORTD = 0xFF;
		shouldHigh = 1;
		msCount = 0;
	}
}

int main (void)
{

	/* Insert application code here, after the board has been initialized. */

	DDRD = 0xFF;

	OCR2 = 519;
	TCCR2 = 1<<WGM21;           /* CTC mode */
	/* Enable interrupts */
	TIMSK = TIMSK | 1<<TOIE1 | 1<<OCIE2;
	TCCR2 |= 1<<CS22 | 0<<CS21 | 1<<CS20;
	TCNT2 = 0;
	sei();

	while(1){
		
		wait(100);
	}
}
