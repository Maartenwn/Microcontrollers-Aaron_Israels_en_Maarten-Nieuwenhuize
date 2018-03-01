#include <time.h>
void syncingscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void syncingscreen_entry(int* buffer);
void syncingscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void syncingscreen_exit (int* buffer);
