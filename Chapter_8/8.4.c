#include <stdio.h>
#include <stdlib.h>

void iddentity_matrix(int *cnt, int size);
int main(void) {
    int arr[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    iddentity_matrix(arr[0][0], 3);
}
void iddentity_matrix(int *cnt, int size) {
    int i,j;
    int flag = 0;
    for (i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if (*cnt++ != (i == j)) {
                printf("error");
                break;
            }
        }
    }
    if (!flag) {
        printf("right");
    }
}
