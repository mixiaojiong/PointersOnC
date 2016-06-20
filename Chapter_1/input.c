#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int line_num = 0;
    int ch;
    int begin = 1;
    while ((ch = getchar()) != EOF) {
        if (begin) {
            begin = 0;
            line_num++;
            printf("%d: ", line_num);
        }
        putchar(ch);
        if (ch == '\n')
            begin = 1;
    }
    return EXIT_SUCCESS;
}
