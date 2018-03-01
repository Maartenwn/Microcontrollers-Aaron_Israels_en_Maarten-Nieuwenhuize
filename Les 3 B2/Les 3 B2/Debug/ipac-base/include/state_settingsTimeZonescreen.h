#include <time.h>
void settingsTimeZonescreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void settingsTimeZonescreen_entry(int* buffer);
void settingsTimeZonescreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void settingsTimeZonescreen_exit (int* buffer);
