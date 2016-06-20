#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1000

int main(void) {
    int max = 0;
    int num = 0;
    int ch;
    char output[MAX_LINE];

    while ((ch = getchar()) != EOF) {
        if (num >= MAX_LINE) {
            printf("overflow!\n");
            break;
        }
        output[num] = ch;
        if (ch == '\n') {
            if (num > max) {
                max = num;
            }
            num = 0;
        } else {
            num++;
        }
    }
    printf("%s", output);
    printf("%d", max - 1);
    return EXIT_SUCCESS;
}
