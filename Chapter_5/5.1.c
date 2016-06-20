#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= 65 && ch <= 90) {
            ch = ch + 32;
        }
        putchar(ch);
    }
    EXIT_SUCCESS;
}
