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

#define F_CPU 8000000

#include <avr/io.h>
#include "GLCD.h"
#include "Touch.h"
#include "lcd.h"
#include "tamagotchi.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
	DDRC = 0xFF;
	DDRD = 0xFF;
	init();
	GLCD_init();
	touch_init();
	tamagotchi_init();
	int looptimes = 0;
	while (1)
	{
		_delay_ms(30);
		looptimes++;
		if(looptimes >= 500){
			tamagotchi_update();
			looptimes = 0;
		}

		if(isFeedPressed()){
			tamagotchi_feed();
		}
		if(isCleanPressed()){
			tamagotchi_clean();
		}
		if(isMedicinPressed()){
			tamagotchi_medicin();
		}
		if(isPlayPressed()){
			tamagotchi_play();
		}

		if(looptimes % 20 == 0){
			char str[17] ="";
			clr_display();
			sprintf(str,"He %d Hu %d Ha%d",tamagotchi_getHealth(),tamagotchi_getHunger(),tamagotchi_getHappynes());
			display_text(str);
		}
	}
}
