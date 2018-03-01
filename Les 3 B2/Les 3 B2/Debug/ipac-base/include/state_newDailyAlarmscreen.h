#include <time.h>
void newDailyAlarmscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void newDailyAlarmscreen_entry(int* buffer);
void newDailyAlarmscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void newDailyAlarmscreen_exit (int* buffer);
