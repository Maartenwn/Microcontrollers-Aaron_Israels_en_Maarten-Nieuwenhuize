#include "state_syncingscreen.h"
#include <time.h>
#include "display.h"

void syncingscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer)){

}

void syncingscreen_entry(int* buffer){
    LcdDisplayStr(" Synching NTP.. ");
}


void syncingscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) , struct _tm *time){
    //if(NTP has sinked || device has no internet || timout of sync has expired){
        sm_setState(3,NULL,NULL); // clockscreen
    //}
}

void syncingscreen_exit (int* buffer){
    LcdClear();
}
