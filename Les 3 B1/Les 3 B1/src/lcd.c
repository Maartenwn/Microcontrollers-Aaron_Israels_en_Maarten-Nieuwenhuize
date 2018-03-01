/*
 * LCD.c
 *
 * Created: 22-2-2018 15:34:08
 *  Author: Aaron en Maarten
 */
#define F_CPU 8000000

#include <avr/io.h>
#include <avr/delay.h>
#include <string.h>
#include "LCD.h"

void lcd_writeChar( unsigned char dat )
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x0C; // data (RS=1),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}

void lcd_command ( unsigned char dat )
{
	PORTC = dat & 0xF0; // hoge nibble
	PORTC = PORTC | 0x08; // data (RS=0),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x04; // stop (EN = 0)
	PORTC = (dat & 0x0F) << 4; // lage nibble
	PORTC = PORTC | 0x08; // data (RS=0),
	// start (EN=1)
	_delay_ms(1); // wait 1 ms
	PORTC = 0x00; // stop
	// (EN=0 RS=0)
}

void init() {
	// return home
	lcd_command( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	lcd_command( 0x28 );
	// display: on, cursor off, blinking off
	lcd_command( 0x0C );
	// entry mode: cursor to right, no shift
	lcd_command( 0x06 ); //was 0x06

}

void display_text(char *str) {
	_delay_ms(1);
	int length = strlen(str);
	for(int x = 0; x < length; x++) {
		lcd_writeChar(str[x]);
		if(x == 16){
			lcd_command(0xC0);
		}
	}
}

void set_display(int pos) {
	_delay_ms(1);
	for(int x = 0; x < pos; x++) {
		lcd_command(0b0000011000);
	}
}

void set_cursor(int pos){
	_delay_ms(1);
	clr_display();
	for(int x = 0; x < pos; x++) {
		lcd_command(0b0000010100);
	}
}

void clr_display() {
	_delay_ms(1);
	lcd_command(0x01);
}

