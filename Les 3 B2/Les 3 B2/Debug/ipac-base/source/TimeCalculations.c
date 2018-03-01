#include <time.h>
#include <stdio.h>
#include "TimeCalculations.h"


int getSecondsBetween(struct _tm *newTime, struct _tm *old){
    int seconds = newTime -> tm_sec - old->tm_sec;
    int minutes = newTime->tm_min - old->tm_min;
    int hours = newTime -> tm_hour - old -> tm_hour;

    seconds += minutes * 60;
    seconds += hours * 60 * 60;
    return seconds;
}

int getMinutesBetween(struct _tm *newTime, struct _tm *old){
    int seconds = newTime -> tm_sec - old->tm_sec;
    int minutes = newTime->tm_min - old->tm_min;
    int hours = newTime -> tm_hour - old -> tm_hour;

    minutes += seconds / 60;
    minutes += hours * 60;
    return minutes;
}

int getHoursBetween(struct _tm *newTime, struct _tm *old){
    int seconds = newTime -> tm_sec - old->tm_sec;
    int minutes = newTime->tm_min - old->tm_min;
    int hours = newTime -> tm_hour - old -> tm_hour;

    hours += minutes / 60;
    hours += seconds / ( 60 * 60);
    return minutes;
}

void deepCpyTime(struct _tm *dest, struct _tm *old){
    dest -> tm_sec = old -> tm_sec;
    dest -> tm_min = old -> tm_min;
    dest-> tm_hour = old -> tm_hour;
    dest -> tm_isdst = old -> tm_isdst;
    dest -> tm_mon = old -> tm_mon;
    dest -> tm_wday = old -> tm_wday;
    dest -> tm_yday = old -> tm_yday;
    dest -> tm_year = old -> tm_year;
}
