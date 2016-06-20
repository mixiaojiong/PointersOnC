#include <stdio.h>
#include <stdlib.h>

int test() {
    static int x = 111;
    return 1;
}

int main(void) {
    printf("%d\n", x);
}
