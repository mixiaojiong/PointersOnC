#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j, flag;
    for(i = 1; i <= 100; i++) {
        flag = 0;
        for(j = i; j > 0; j--) {
            if ((i % j) == 0) {
                flag++;
            }
        }
        if (flag == 2) {
            printf("%d\n", i);
        }
    }
}
