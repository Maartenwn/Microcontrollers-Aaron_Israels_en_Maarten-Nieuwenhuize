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

#define BIT(x)	(1 << (x))


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
	for (int tms=0; tms<ms; tms++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}


void ADC_init(){
	ADMUX = 0b11100011;
	ADCSRA = 0b10000110;
}

int main (void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;

	ADC_init();
	while(1){
		ADCSRA |= BIT(6);
		while( (ADCSRA & BIT(6)));
		PORTA = ADCL;
		PORTB = ADCH;
		wait(500);
	}	
}

