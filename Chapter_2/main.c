#include <stdio.h>
#include <stdlib.h>
int increment(int arg);
int negate(int arg);

int main (void) {
    int res;
    res = increment(10);
    printf("%d\n", res);
    res = increment(0);
    printf("%d\n", res);
    res = negate(-10);
    printf("%d\n", res);
}
