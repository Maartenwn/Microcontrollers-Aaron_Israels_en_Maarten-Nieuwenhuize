#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/timer.h>
#include "backlight.h"
#include "statemachine.h"
#include "keyboard.h"
#include "display.h"
#include "log.h"

#define LOG_MODULE LOG_MAIN_MODULE


typedef struct {
	unsigned int id; //id of screen
	void(*keyPressed)(int keycode, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer));
	void(*entry)(int*);
	void(*loop)(int*, void(*sm_setState)(int,int* exitBuffer, int* entryBuffer),struct _tm *time);
	void(*exit)(int*);
}STATE;

enum screen_name{
	Welcomescreen, 				//0
	Syncingscreen, 				//1
	TimezoneStartscreen, 		//2
	Clockscreen,				//3
	Menuscreen, 				//4
	Alarmsscreen, 				//5
	TypeOfAlarmscreen,			//6
	NewDailyAlarmscreen , 		//7
	NewOnceAlarmscreen , 		//8
	AlarmSoundChooserscreen, 	//9
	Radioscreen,				//10
	Sleeptimerscreen, 			//11
	Settingsscreeen, 			//12
	SettingTimeZonescreen,		//13
	FactoryResetscreen , 		//14
	Confirmationscreen			//15
};

STATE states[16] = {
	{
		Welcomescreen,
		welcomescreen_keypressed,
		welcomescreen_entry,
		welcomescreen_loop,
		welcomescreen_exit
	},
	{
		Syncingscreen,
		syncingscreen_keypressed,
		syncingscreen_entry,
		syncingscreen_loop,
		syncingscreen_exit
	},
	{
		TimezoneStartscreen,
		timezoneStartscreen_keypressed,
		timezoneStartscreen_entry,
		timezoneStartscreen_loop,
		timezoneStartscreen_exit
	},
	{
		Clockscreen,
		clockscreen_keypressed,
		clockscreen_entry,
		clockscreen_loop,
		clockscreen_exit
	},
	{
		Menuscreen,
		menuscreen_keypressed,
		menuscreen_entry,
		menuscreen_loop,
		menuscreen_exit
	},
	{
		Alarmsscreen,
		alarmcreen_keypressed,
		alarmscreen_entry,
		alarmscreen_loop,
		alarmscreen_exit
	},
	{
		TypeOfAlarmscreen,
		typeOfAlarmscreen_keypressed,
		typeOfAlarmscreen_entry,
		typeOfAlarmscreen_loop,
		typeOfAlarmscreen_exit
	},
	{
		NewDailyAlarmscreen,
		newDailyAlarmscreen_keypressed,
		newDailyAlarmscreen_entry,
		newDailyAlarmscreen_loop,
		newDailyAlarmscreen_exit
	},
	{
		NewOnceAlarmscreen,
		newOnceAlarmscreen_keypressed,
		newOnceAlarmscreen_entry,
		newOnceAlarmscreen_loop,
		newOnceAlarmscreen_exit
	},
	{
		AlarmSoundChooserscreen,
		alarmSoundChooserscreen_keypressed,
		alarmSoundChooserscreen_entry,
		alarmSoundChooserscreen_loop,
		alarmSoundChooserscreen_exit
	},
	{
		Radioscreen,
		radioscreen_keypressed,
		radioscreen_entry,
		radioscreen_loop,
		radioscreen_exit
	},
	{
		Sleeptimerscreen,
		sleepTimerscreen_keypressed,
		sleepTimerscreen_entry,
		sleepTimerscreen_loop,
		sleepTimerscreen_exit
	},
	{
		Settingsscreeen,
		settingsscreen_keypressed,
		settingsscreen_entry,
		settingsscreen_loop,
		settingsscreen_exit
	},
	{
		SettingTimeZonescreen,
		settingsTimeZonescreen_keypressed,
		settingsTimeZonescreen_entry,
		settingsTimeZonescreen_loop,
		settingsTimeZonescreen_exit
	},
	{
		FactoryResetscreen,
		factoryResetscreen_keypressed,
		factoryResetscreen_entry,
		factoryResetscreen_loop,
		factoryResetscreen_exit
	},
	{
		Confirmationscreen,
		confirmationscreen_keypressed,
		confirmationscreen_entry,
		confirmationscreen_loop,
		confirmationscreen_exit
	}
};

int currentstate;
int prevKey; 


void sm_init(){
	currentstate = 0;
	prevKey = KEY_UNDEFINED;

	states[currentstate].entry(NULL);
}


//main loop called from main.c
//loops the currentstate then checks for buttonpresses and then checks for alarms.
void sm_loop(struct _tm *gmt){
	
	states[currentstate].loop(NULL,sm_setState,gmt);

	//check keypressed

	int k = KbGetKey();
	if(k != KEY_UNDEFINED && k != prevKey){
		if(getStatusBacklight() == 1){
			resetTimerBacklight();
			states[currentstate].keyPressed(k,sm_setState);
		} else {
			turnOnBacklight(gmt);
			resetTimerBacklight(gmt);
		}
	}
	prevKey = k;
	if(getStatusBacklight() == 1){
		checkTimerBacklight(gmt);
		LogMsg_P(LOG_INFO, PSTR("RTC time [%02d:%02d:%02d]"), gmt->tm_hour, gmt->tm_min, gmt->tm_sec );
	}


	//check alarms
	//todo add alarm check
}

//when changing between screen call this method to change screen,
// i = id of screen see enum screen_name
// exitBuffer is data that a screen need to close. if no data is needed, exitBuffer should be NULL from <stdlib>
// entryBuffer is data that a screen need to open. if no data is needed, entryBuffer should be NULL from <stdlib>
void sm_setState(int i,int* exitBuffer, int* entryBuffer){
	//exit function
	states[currentstate].exit(exitBuffer);
	//sets state
	currentstate = i;

	//entry funtion
	states[currentstate].entry(entryBuffer);
}
