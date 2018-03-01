#include <time.h>
void settingsscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void settingsscreen_entry(int* buffer);
void settingsscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void settingsscreen_exit (int* buffer);
