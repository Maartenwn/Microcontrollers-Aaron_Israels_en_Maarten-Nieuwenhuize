#include <time.h>
#include "state_welcomescreen.h"
#include "state_alarmscreen.h"
#include "state_alarmSoundChooserscreen.h"
#include "state_clockscreen.h"
#include "state_confirmationscreen.h"
#include "state_factoryResetscreen.h"
#include "state_menuscreen.h"
#include "state_newDailyAlarmscreen.h"
#include "state_newOnceAlarmscreen.h"
#include "state_Radioscreen.h"
#include "state_settingsscreen.h"
#include "state_settingsTimeZonescreen.h"
#include "state_sleepTimerscreen.h"
#include "state_syncingscreen.h"
#include "state_timezoneStarscreen.h"
#include "state_typeOfAlarmscreen.h"


void sm_setState(int i,int* exitBuffer, int* entryBuffer);
void sm_loop(tm *gmt);
void sm_init(void);
