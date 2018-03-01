
#include <time.h>
void alarmcreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void alarmscreen_entry(int* buffer);
void alarmscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void alarmscreen_exit (int* buffer);
