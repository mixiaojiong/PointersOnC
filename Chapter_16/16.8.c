#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buffer[512];
    while(fgets(buffer, 512, stdin)) {
        long sum = 0;
        int member = 0;
        long age = 0;
        char *bp = buffer;

        while((age = strtol(bp, &bp, 10)) > 0) {
            member++;
            sum += age;
        }
        if (member == 0) {
            continue;
        }
        printf("%5.2f: %s", (double)sum / member, buffer);
    }
}
