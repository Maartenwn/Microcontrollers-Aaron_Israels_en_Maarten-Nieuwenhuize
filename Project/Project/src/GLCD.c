/*
 * Touchpanel.c
 *
 * Created: 15/03/2018 13:35:58
 *  Author: Maarten
 */ 
 #define F_CPU 8000000

 #include "Images.h"
 #include "GLCD.h"
 #include <avr/io.h>
 #include <util/delay.h>

 #define GETBITFROM(n,k) ( ((n >> k) & 1))
 #define BIT(x) ( 1<<x )

 void GLCD_init(){
	DDRA = 0xFF;
	DDRE = 0xFF;

	PORTE |= BIT(2);
	PORTE |= BIT(3);

	PORTE |= BIT(7);

	DisplayOn();
	GLCD_CLR();
 }

 void EnableCmd(void);

 void GLCD_DisplayImage(POSITION *image){
	int i =0;
	while(image[i].x != -1 && image[i].y != -1){
		Draw_Point(image[i].x,image[i].y,1);
		i++;
	}
 }


 void Draw_Point(unsigned short x,unsigned short y, unsigned short color)
 {
	 int Col_Data = 0;
	 GOTO_XY(x,(y/8));
	 switch (color)
	 {
		 case 0:         //Light spot
		 Col_Data = ~(1<<(y%8)) & GLCD_Read(x);
		 break;
		 case 1:         //Dark spot
		 Col_Data = (1<<(y%8)) | GLCD_Read(x);
		 break;
	 }
	 GOTO_XY(x,(y/8));
	 GLCD_Write(Col_Data);
 }

 unsigned short GLCD_Read(unsigned short column)
 {
	 unsigned short read_data = 0; //Read data here
	 DDRA = 0x00;     //PORTD as Input
	 PORTE |= BIT(4);             //Read
	 PORTE |= BIT(5);            //Data

	 if(column >63){
	  PORTE |= BIT(2);
	  PORTE &= ~BIT(3);
	 }else {
		PORTE &= ~BIT(2);
		PORTE |= BIT(3);
	 }

	 _delay_us(1);
	 PORTE |= BIT(6);
	 _delay_us(1);

	 //dummy reead
	 PORTE &= ~BIT(6);
	 _delay_us(5);

	 PORTE |= BIT(6);
	_delay_us(1);
	 
	 read_data = PINA;    //Input data
	 PORTB = read_data;

	 PORTE &= ~BIT(6);    //Low Enable to remove data from the bus
	 _delay_us(1);        //tdhr
	 DDRA = 0xFF;     //Output again
	 return read_data;
 }

 void EnableCmd(){
	PORTE |= BIT(6);

	_delay_us(5);

	PORTE &= ~BIT(6);
	
	_delay_us(5);

 }

 void GLCD_Write(unsigned short b)
 {
	 PORTE |= BIT(4);                  //RS low --> command
	 PORTE &= ~BIT(5);                 //RW low --> write
	 PORTA = b;            //put data on data port
	 _delay_us(1);
	 EnableCmd();
 }


 void DisplayOn(){
	PORTE &= ~BIT(2);                  //RS low --> command
	PORTE &= ~BIT(3);                 //RW low --> write
	 
	PORTE &= ~BIT(4);                  //RS low --> command
	PORTE &= ~BIT(5);                 //RW low --> write
	  
	PORTA = 0x3F;	
	EnableCmd();
 }

 void GLCD_CLR()
 {
	 int y;
	 int x;

	 for(y=0; y<64; y++){
		 for (x=0; x<128; x++){
			 GOTO_XY(x,y);
			 GLCD_Write(0x00);
		 }
	 }

	 Set_Start_Line(0);
 }

 void GOTO_XY(unsigned int x,unsigned int y)
 {
	 GOTO_COL(x);
	 GOTO_ROW(y);
 }

 void GOTO_COL(unsigned int x)
 {
	 unsigned short Col_Data;
	 PORTE &= ~BIT(4);                  //RS low --> command
	 PORTE &= ~BIT(5);                 //RW low --> write
	 if(x<64)             //left section
	 {
		 PORTE &= ~BIT(2);          //select chip 1
		 PORTE |= BIT(3);         //deselect chip 2
		 Col_Data = x;              //put column address on data port
	 }
	 else                 //right section
	 { 
		 PORTE |= BIT(2);          //select chip 1
		 PORTE &= ~BIT(3);
		 Col_Data = x-64;   //put column address on data port
	 }
	 Col_Data = (Col_Data | 0x40 ) & 0x7F;  //Command format
	 PORTA = Col_Data;
	 EnableCmd();
 }

 void GOTO_ROW(unsigned int y)
 {
	 unsigned short Col_Data;
	 PORTE &= ~BIT(4);                  //RS low --> command
	 PORTE &= ~BIT(5);                 //RW low --> write
	 Col_Data = (y | 0xB8 ) & 0xBF; //put row address on data port set command
	 PORTA = Col_Data;
	 EnableCmd();	
 }

 void GLCD_Clrln(unsigned short ln)
 {
	 int i;
	 GOTO_XY(0,ln);      //At start of line of left side
	 GOTO_XY(64,ln);     //At start of line of right side (Problem)
	 PORTE &= ~BIT(2);
	 for(i=0;i<65;i++)
	 GLCD_Write(0);
 }

 void Set_Start_Line(unsigned short line)
 {
	 PORTE &= ~BIT(4);                  //RS low --> command
	 PORTE &= ~BIT(5);                 //RW low --> write
	 //Activate both chips
	 PORTE &= ~BIT(2);                  //RS low --> command
	 PORTE &= ~BIT(3);                 //RW low --> write
	 PORTA = 0xC0 | line;     //Set Start Line command
	 EnableCmd();
 }

