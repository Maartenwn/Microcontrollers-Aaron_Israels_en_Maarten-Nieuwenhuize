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

#include <avr/io.h>

void ADC_init(){
	ADMUX =  0b01100000;
	ADCSRA = 0b11100110;
}

int main (void)
{
	DDRA = 0xFF;
	DDRB = 0xBB;


	ADC_init();
	while(1){
		PORTA = ADCL;
		PORTB = ADCH;
	}
		
		
}

