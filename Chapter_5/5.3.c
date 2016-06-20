#include <stdio.h>
#include <stdlib.h>

int main (void) {
    unsigned int answer;
    unsigned int i;
    answer = 0;
    unsigned int value = 25;
    for(i = 1; i != 0; i <<= 1) {
        answer <<= 1;
        if (value & 1) {
            answer |= 1;
        }
        value >>= 1;
    }
    printf("%u\n", answer);
    return answer;
}
