#include <time.h>
void welcomescreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void welcomescreen_entry(int* buffer);
void welcomescreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void welcomescreen_exit (int* buffer);
