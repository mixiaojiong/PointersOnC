#include <stdio.h>
#include <stdlib.h>

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);
int main(void) {
    int m1[3][2] = {
        {2, -6},
        {3, 5},
        {1, -1}
    };
    int m2[2][4] = {
        {4, -2, -4, -5},
        {-7, -3, 6, 7}
    };
    int r[3][4];
    matrix_multiply(&m1[0][0], &m2[0][0], &r[0][0], 3, 2, 4);
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j =0; j < 4; j++) {
            printf("%d ", r[i][j]);
        }
        putchar('\n');
    }
}

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {
    int *p1, *p2;
    int row, col, k;
    for(row = 0; row < x; row++) {
        for(col = 0; col < z; col++) {
            p1 = m1 + row * y;
            p2 = m2 + col;
            *r = 0;
            for(k = 0; k < y; k++) {
                *r += *p1 * *p2;
                p1 += 1;
                p2 += z;
            }
            r++;
        }
    }
}
