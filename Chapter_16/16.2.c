#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_OK_RAND ((((unsigned)RAND_MAX + 1) / 6) * 6 - 1)

int main(void) {
    srand(time(NULL));
    int value;
    do {
        value = rand();
    } while(value > MAX_OK_RAND);
    printf("%d\n", RAND_MAX);
    printf("%d\n", MAX_OK_RAND);
    printf("%d\n", value % 6 + 1);
}
