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

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


typedef enum {UNKOWN,D5,D6,D7} EVENTS;
typedef enum {UNKOWNSTATE,Start,S1,S2,S3,End} STATES;

typedef struct {
	STATES next;
	EVENTS trigger;
} EVENT;

typedef struct {
	STATES state;
	EVENT events[3];
} STATE;

void handleD5(STATE *currentState);
void handleD6(STATE *currentState);
void handleD7(STATE *currentState);


STATE states[5] = {
	{
		Start , { {S1,D6} , {S2,D5} , {UNKOWN,UNKOWNSTATE} }
	},
	{
		S1 , { {S2,D5} , {Start,D7}, {UNKOWN,UNKOWNSTATE} }
	},
	{
		S2, { {Start ,D7} , {S3,D5} , {UNKOWN,UNKOWNSTATE} }
	},
	{
		S3 ,{ {Start , D7}, {End,D5} , {End , D6} }
	},
	{
		End , { {Start, D7} , {UNKOWN,UNKOWNSTATE}, {UNKOWN,UNKOWNSTATE} }
	}
};


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


void handleD5(STATE *currentState){
	int index; 
	for(index = 0; index < 3; index++){
		if(currentState->events[index].trigger == D5){
			int i = 0;
			EVENTS *next = &currentState->events[index].trigger;
			for(i = 0; i < 5; i++){
				if(currentState->events[index].next == states[i].state){
					*currentState = states[i];
					return;
				}
			}
		}
	}
}

void handleD6(STATE *currentState){
	int index;
	for(index = 0; index < 3; index++){
		if(currentState->events[index].trigger == D6){
			int i = 0;
			for(i = 0; i < 5; i++){
				if(currentState->events[index].next == states[i].state){
					*currentState = states[i];
					return;
				}
			}
		}
	}
}

void handleD7(STATE *currentState){
	int index;
	for(index = 0; index < 3; index++){
		if(currentState->events[index].trigger == D7){
			int i = 0;
			for(i = 0; i < 5; i++){
				if(currentState->events[index].next == states[i].state){
					*currentState = states[i];
					return;
				}
			}
		}
	}
}


/******************************************************************]
short:			main() loop, entry point of executable https://youtu.be/YS4TXIHeLDU
inputs:			
outputs:	
notes:			Looping forever
Version :    	DMK, Initial code
*******************************************************************/
int main( void )
{
	//DDRD = 0b11111111;			// All pins PORTD are set to output
	DDRE = 0b11111111;	

	STATE currentState = states[0];

	handleD5(&currentState);
	

	
	while (1)
	{
		if(PIND & 32){
			handleD5(&currentState);
		}else if(PIND & 64){
			handleD6(&currentState);
		}else if(PIND & 128){
			handleD7(&currentState);
		}

		


		if(currentState.state == states[4].state){
			PORTE = 0xFF;
		}else if(currentState.state == states[0].state){
			PORTE = 0x00;
		}else if(currentState.state == states[1].state){
			PORTE =0x01;
		}else if(currentState.state == states[2].state){
			PORTE = 0x02;
		}else if(currentState.state == states[3].state){
			PORTE = 0x04;
		}
		wait(100);		
	}

	return 1;
}




