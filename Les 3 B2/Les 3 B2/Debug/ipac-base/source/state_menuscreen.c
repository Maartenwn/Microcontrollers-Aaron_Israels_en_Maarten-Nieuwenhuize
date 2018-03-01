#include "state_menuscreen.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "keyboard.h"
#include "display.h"

#define menusize 3

char menu[menusize][14] = {
    "Alarms","Radio","Settings"
};

int currentNumber;

void menuscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer)){
    switch(keycode){
        case KEY_UP:
            currentNumber--;
            if(currentNumber < 0){
                currentNumber = 0;
            }
            draw();
        break;
        
        case KEY_DOWN:
            currentNumber++;
            if(currentNumber >= menusize){
                currentNumber = menusize - 1;
            }
            draw();
        break;
        
        case KEY_ESC:
            sm_setState(3,NULL,NULL); //clockscreen 
        break;

        case KEY_OK:
            switch(currentNumber){
                case 0:
                    sm_setState(5,NULL,NULL); //alarmscreen
                break;

                case 1:
                    sm_setState(10,NULL,NULL); //radioscreen
                break;

                case 2:
                    sm_setState(12,NULL,NULL); //setttingsscreen
                break;
            }
        break;
    }
}

void menuscreen_entry(int* buffer){
    currentNumber = 0;
    draw();
}

void menuscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) , struct _tm *time){

}
void menuscreen_exit (int* buffer){
    LcdClear();
}

void draw(){
    LcdClear();
    char string[14];
    char c = 126;

    sprintf(string,"%c%c%s",c,' ',menu[currentNumber]);
    LcdDisplayStrUpperRow(string);

    if(currentNumber < menusize - 1){
        char string[14];
        
        sprintf(string,"%s%s","  ",menu[currentNumber + 1]);
        LcdDisplayStrLowerRow(string);
    }
}
