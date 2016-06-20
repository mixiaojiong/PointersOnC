#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    time_t now;
    struct tm *tm;
    int hour, minute;

    now = time(NULL);
    tm = localtime(&now);
    hour = tm->tm_hour;
    minute = tm->tm_min;

    if (minute >= 30) {
        hour++;
    }
    hour %= 12;
    if (hour == 0) {
        hour = 12;
    }
    minute++;
    minute /= 5;
    if (minute == 0) {
        minute = 12;
    }
    printf("hour is : %d\t minute is : %d\n", hour, minute);

}
