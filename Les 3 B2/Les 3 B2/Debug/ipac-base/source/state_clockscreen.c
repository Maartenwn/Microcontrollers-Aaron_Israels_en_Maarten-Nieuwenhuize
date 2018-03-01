#include "state_clockscreen.h"
#include <stdio.h>
#include "keyboard.h"
#include "display.h"
#include "log.h"
#include <time.h>

#define LOG_MODULE LOG_MAIN_MODULE

int amountOf10ms;

void clockscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer)){
    if(KEY_ESC == keycode){
        sm_setState(4,NULL,NULL); //menu screen
    }
}

void clockscreen_entry(int* buffer){
    LogMsg_P(LOG_INFO,PSTR("state_clockscreen entry"));
    amountOf10ms = 0;
    LcdClear();
    
}
void clockscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) , struct _tm *tine){
    amountOf10ms++;
    
    if(amountOf10ms >= 10){
        LogMsg_P(LOG_INFO,PSTR("state_clockscreen clock refresh"));
        amountOf10ms = 0;
        LcdClear();
        manageDisplay(tine);
    }
    
}

void clockscreen_exit (int* buffer){
    amountOf10ms = 0;
    LcdClear();
}


void manageDisplay(struct _tm *tm){
        char currentTime[8];
        currentTime[0] = tm->tm_hour/10;
        currentTime[1] = tm->tm_hour;
        currentTime[3] = tm->tm_min/10;
        currentTime[4] = tm->tm_min;
        currentTime[6] = tm->tm_sec/10;
        currentTime[7] = tm->tm_sec;
        int i;
        for(i =0; i < 8; i++){
            if(i==2||i==5){
                LcdChar(0x3A);
            } else {
            char c = (currentTime[i]%10) +48;
            LcdChar(c);
            }
        }
}
