#include <time.h>
void alarmSoundChooserscreen_keypressed(int keycode, void(*sm_setState)(int i,int* exitBuffer, int* entryBuffer));
void alarmSoundChooserscreen_entry(int* buffer);
void alarmSoundChooserscreen_loop (int* buffer, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer) ,tm *gmt);
void alarmSoundChooserscreen_exit (int* buffer);
