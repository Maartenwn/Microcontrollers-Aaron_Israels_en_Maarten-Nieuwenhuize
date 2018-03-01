#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "display.h"
#include "TimeCalculations.h"

struct _tm *old;
int backlightStatus = 0;

void turnOnBacklight(){
    LcdBackLight(LCD_BACKLIGHT_ON);
    changeStatusBacklight(1);
}

void changeStatusBacklight(int i){
    backlightStatus = i;
}

int getStatusBacklight(){
    return backlightStatus;
}

void resetTimerBacklight(struct _tm *gmt){
    old = malloc(sizeof(struct _tm));    
    memcpy(old,gmt,sizeof(struct _tm));
}

void turnOffBacklight(){
    LcdBackLight(LCD_BACKLIGHT_OFF);
    changeStatusBacklight(0);
}

void checkTimerBacklight(struct _tm *gmt, int timeBetween){
        if(getSecondsBetween(gmt,old)>timeBetween){
            turnOffBacklight();
            free(old);
        }
}
