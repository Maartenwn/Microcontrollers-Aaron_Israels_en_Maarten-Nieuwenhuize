/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** ioisr.c
**
** Beschrijving:	7 segment display
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ioisr.c
**					avr-gcc -g -mmcu=atmega128 -o ioisr.elf ioisr.o
**					avr-objcopy -O ihex ioisr.elf ioisr.hex 
**					or type 'make'
** Author: 			dkroeske@gmail.com && maartenwn@gmail.com && aaron.israels@home.nl
** -------------------------------------------------------------------------*/
#define F_CPU 8000000																																	

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void display(int digit);

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

int count;

const unsigned char numbers[16] = {

	0b00111111,	//0
	0b00000110,	//1
	0b01011011,	//2
	0b01001111,	//3
	0b01100110,	//4
	0b01101101,	//5
	0b01111101,	//6
	0b00000111,	//7
	0b01111111,	//8
	0b01101111,	//9
	0b01110111,	//a
	0b01111100,	//b
	0b00111001, //c
	0b01011110, //d
	0b01111001, //e
	0b01110001 //f
};

/******************************************************************/
ISR( INT1_vect )
/* 
short:			ISR INT1
inputs:			
outputs:	
notes:			add 1 to count and displays in on the 7 seq display
Version :    	DMK, Initial code
*******************************************************************/
{
	count++;
	if(count > 15 || count < 0){
		display(14);
	}else display(count);
}

/******************************************************************/
ISR( INT2_vect )
/* 
short:			ISR INT2
inputs:			
outputs:	
notes:			removes 1 from count and displays in on the 7 seq display
Version :    	DMK, Initial code
*******************************************************************/
{	
    count--;
	if(count > 15 || count < 0){
		display(14);
	}else display(count);
}

/******************************************************************/
void display( int digit )
/* 
short:			shows digits on a 7 seq display form 0 to 15
inputs:			int digit (digit you want to display)
outputs:	
notes:			
Version :    	DMK, Initial code
*******************************************************************/
{
	PORTC = numbers[digit];
}

/******************************************************************/
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			https://youtu.be/PFpU6IJAsgA
Version :    	DMK, Initial code
*******************************************************************/
{
	// Init I/O
	DDRD = 0x00;			//set PORTD as input
	DDRC = 0xFF;			//set PORTC as output


	// Init Interrupt hardware
	EICRA |= 0x3C;			// INT1 rising edge, INT2 rising edge
	EIMSK |= 0x06;			// Enable INT1 & INT2
	
	// Enable global interrupt system
	//SREG = 0x80;			// Of direct via SREG of via wrapper
	sei();
	
	count = 0;
	display(count);				

	while (1)
	{							

	}

	return 1;
}