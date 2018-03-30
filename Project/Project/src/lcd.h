/*
 * LCD.h
 *
 * Created: 22-2-2018 15:34:21
 *  Author: Aaron en Maarten
 */ 


#ifndef LCD_H_
#define LCD_H_

void init(void);
void clr_display(void);
void display_text(char *str);
void set_cursor(int pos);
void set_display(int pos);

void lcd_command ( unsigned char dat );

#endif /* LCD_H_ */