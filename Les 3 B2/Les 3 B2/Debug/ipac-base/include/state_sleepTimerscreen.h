#include <time.h>
void sleepTimerscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void sleepTimerscreen_entry(int* buffer);
void sleepTimerscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void sleepTimerscreen_exit (int* buffer);
