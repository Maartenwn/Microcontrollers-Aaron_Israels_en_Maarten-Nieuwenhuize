#include <time.h>

int getSecondsBetween(tm *newTime, tm *old);

int getMinutesBetween(tm *newTime, tm *old);

int getHoursBetween(tm *newTime, tm *old);

void deepCpyTime(struct _tm *dest, struct _tm *old);
