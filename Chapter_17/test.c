#include <stdio.h>

void aaa(int *y) {
    *y = 6;
}

int main(void) {
    int x = 5;
    aaa(&x);
    printf("%d", x);
}
