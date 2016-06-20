#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int max_list(int first, ...);
int main(void) {
    int res;
    res = max_list(1, 11, 23, 9, 88, 34, 10, -10);
    printf("%d\n", res);
}
int max_list(int first, ...) {
    va_list var_arg;
    int max, this;
    max = 0;
    if (first >= 0) {
        va_start(var_arg, first);
        max = first;
        while((this = va_arg(var_arg, int)) >= 0) {
            if (this > max) {
                max = this;
            }
        }
    }
    return max;
}
