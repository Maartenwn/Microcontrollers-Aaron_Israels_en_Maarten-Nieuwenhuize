#include <time.h>
void radioscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void radioscreen_entry(int* buffer);
void radioscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void radioscreen_exit (int* buffer);
