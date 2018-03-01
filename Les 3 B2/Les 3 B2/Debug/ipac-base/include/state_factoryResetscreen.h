#include <time.h>
void factoryResetscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void factoryResetscreen_entry(int* buffer);
void factoryResetscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void factoryResetscreen_exit (int* buffer);
