#include "state_welcomescreen.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "log.h"
#include "display.h"
#include "keyboard.h"
#include "TimeCalculations.h"

#define LOG_MODULE LOG_MAIN_MODULE


int hasChangedSinceLoop;
char text[32] = "   Welcome...";
struct _tm *previousTime;


void welcomescreen_keypressed(int keycode, void(*sm_setState)(int i ,int* exitBuffer, int* entryBuffer)){
    
}

void welcomescreen_entry(int* buffer){
    LcdDisplayStr(text);
    LcdBackLight(LCD_BACKLIGHT_ON);
}

void welcomescreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) , struct _tm *tine){
    if(NULL == previousTime){
        previousTime = malloc(sizeof(struct _tm));    
        memcpy(previousTime,tine,sizeof(struct _tm));
    }

    if(getSecondsBetween(tine, previousTime) > 5){
        //if( eeprom waarde is 0){
        //    
        //}else {
            sm_setState(1,NULL,NULL); //syncing screen
        //}
    }
}


void welcomescreen_exit (int* buffer){
    free(previousTime);
    LcdBackLight(LCD_BACKLIGHT_OFF);
}
