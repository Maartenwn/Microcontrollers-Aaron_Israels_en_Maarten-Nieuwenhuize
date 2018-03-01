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
#define F_CPU 8 * 10^6

#include <avr/io.h>
#include "lcd.h"

static char str[] = "Hi guys";

int main (void)
{
	

	/* Insert application code here, after the board has been initialized. */

	DDRC = 0xFF;
	PORTC = 0x00;
	DDRD = 0xFF;
	

	init();
	clr_display();
	display_text("Hello world EHlldkjdflkjfdljkfdslkjfds");

	while(1){
	}
}
