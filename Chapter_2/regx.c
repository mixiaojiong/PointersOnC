#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int flag = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '{') {
            flag++;
        }

        if (ch == '}') {
            flag--;
            if (flag < 0) {
                printf("regx error\n");
            }
        }
    }
    return EXIT_SUCCESS;
}
