#include <time.h>
void menuscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void menuscreen_entry(int* buffer);
void menuscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void menuscreen_exit (int* buffer);
void draw(void);
