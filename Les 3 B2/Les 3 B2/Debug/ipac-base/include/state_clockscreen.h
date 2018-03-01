#include <time.h>
void manageDisplay(tm *tm);
void clockscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void clockscreen_entry(int* buffer);
void clockscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void clockscreen_exit (int* buffer);
