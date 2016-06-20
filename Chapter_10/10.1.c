#include <stdio.h>

int main(void) {
    struct phone{
        unsigned int areaCode;
        unsigned int exchange;
        unsigned int stationCode;
    };
    struct call {
        int date;
        int time;
        struct phone putPhone;
        struct phone callPhone;
        struct phone payPhone;
    };
}
