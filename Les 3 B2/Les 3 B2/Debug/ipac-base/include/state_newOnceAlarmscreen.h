#include <time.h>
void newOnceAlarmscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void newOnceAlarmscreen_entry(int* buffer);
void newOnceAlarmscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void newOnceAlarmscreen_exit (int* buffer);
