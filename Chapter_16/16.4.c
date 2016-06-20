#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int arc, char *argv[]) {
    int month = atoi(argv[1]);
    int day = atoi(argv[2]);
    int year = atoi(argv[3]);

    struct tm info;
    info.tm_year = year - 1900;
    info.tm_mon = month - 1;
    info.tm_mday = day;
    info.tm_hour = 12;
    info.tm_min = 0;
    info.tm_sec = 0;
    info.tm_isdst = 0;
    int ret = mktime(&info);
    char buffer[80];
    if( ret == -1 )
    {
        printf("Error: unable to make time using mktime\n");
    }
    else
    {
        strftime(buffer, sizeof(buffer), "%c", &info );
        printf("%s", buffer);
    }

    return EXIT_SUCCESS;
}
