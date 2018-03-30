/*
 * Touch.c
 *
 * Created: 22/03/2018 12:43:33
 *  Author: Maarten
 */ 

 #define F_CPU 8000000

#include "Touch.h"
#include <util/delay.h>
#include <avr/io.h>

 #define GETBITFROM(n,k) ( ((n >> k) & 1))



void touch_init(){
	DDRB = 0x00;
}

int prevFeedPressed = 0;
int isFeedPressed(){
	int isPressed = 0;
	if(GETBITFROM(PINB,3) > 0){
		isPressed = 1;
	}
	if(isPressed == 1 && isPressed != prevFeedPressed){
		prevFeedPressed = 1;
		return 1;
	}else if(isPressed == 0){
		prevFeedPressed = 0;
	}
	return 0;
}

int prevPlayPressed = 0;
int isPlayPressed(){
	int isPressed = 0;
	if(GETBITFROM(PINB,2) > 0){
		isPressed = 1;
	}
	if(isPressed == 1 && isPressed != prevPlayPressed){
		prevPlayPressed = 1;
		return 1;
		}else if(isPressed == 0){
		prevPlayPressed = 0;
	}
	return 0;
}

int prevMedicinPressed = 0;
int isMedicinPressed(){
	int isPressed = 0;
	if(GETBITFROM(PINB,1) > 0){
		isPressed = 1;
	}
	if(isPressed == 1 && isPressed != prevMedicinPressed){
		prevMedicinPressed = 1;
		return 1;
	}else if(isPressed == 0){
		prevMedicinPressed = 0;
	}
	return 0;
}

int prevCleanPressed = 0;
int isCleanPressed(){
	int isPressed = 0;
	if(GETBITFROM(PINB,4) > 0){
		isPressed = 1;
	}if(isPressed == 1 && isPressed != prevCleanPressed){
		prevCleanPressed = 1;
		return 1;
	}else if(isPressed == 0){
		prevCleanPressed = 0;
	}
	return 0;
}
