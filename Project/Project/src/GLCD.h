/*
 * GLCD.h
 *
 * Created: 15/03/2018 13:36:18
 *  Author: Maarten
 */ 
 #include "Images.h"

#ifndef GLCD_H_
#define GLCD_H_

void GLCD_DisplayImage(POSITION * image);
void GLCD_Write(unsigned short b);
unsigned short GLCD_Read(unsigned short column);
void Set_Start_Line(unsigned short line);
void Draw_Point(unsigned short x,unsigned short y, unsigned short color);
void GOTO_COL(unsigned int x);
void GOTO_ROW(unsigned int y);
void GOTO_XY(unsigned int x,unsigned int y);
void GLCD_Clrln(unsigned short ln);
void GLCD_CLR(void);
void GLCD_init(void);
void SendCmd(int command);
void DisplayOn(void);


#endif /* GLCD_H_ */