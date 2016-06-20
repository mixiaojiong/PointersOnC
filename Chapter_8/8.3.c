#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int arr[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    int i,j;
    int flag = 0;
    for (i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if (i == j) {
                if (arr[i][j] != 1) {
                    printf("error");
                    flag = 1;
                    break;
                }
            } else {
                if (arr[i][j] != 0) {
                    printf("error");
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (!flag) {
        printf("right");
    }
}
