#include <time.h>
void timezoneStartscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void timezoneStartscreen_entry(int* buffer);
void timezoneStartscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void timezoneStartscreen_exit (int* buffer);
