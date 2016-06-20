#include <stdio.h>
#include <stdlib.h>

int arr[8][8];
void print();
int conflicts(int row, int col);
void place_queen(int row);

int main(void) {
    place_queen(0);
    return EXIT_SUCCESS;
}

void place_queen(int row) {
    int col;
    for (col = 0; col < 8; col++) {
        arr[row][col] = 1;
        if (row == 0 || !conflicts(row, col)) {
            if (row < 7) {
                place_queen(row + 1);
            } else {
                print();
            }
        }
        arr[row][col] = 0;
    }
}

int conflicts(int row, int col) {
    int i;

    for(i = 1; i < 8; i++) {
        if (row - i >= 0 && arr[row-i][col]) {
            return 1;
        }
        if (col - i >= 0 && arr[row][col-i]) {
            return 1;
        }
        if (col + i < 8 && arr[row][col+i]) {
            return 1;
        }

        if (row - i >= 0 && col - i >= 0 && arr[row-i][col-i]) {
            return 1;
        }
        if (row - i >= 0 && col + i < 8 && arr[row-i][col+i]) {
            return 1;
        }
    }
    return 0;
}
void print() {
    int row, col;
    static int num;
    num++;
    printf("solution#%d:\n", num);
    for(row = 0; row < 8; row++) {
        for(col = 0; col < 8; col++) {
            if (arr[row][col]) {
                printf("Q");
            } else {
                printf("+");
            }
        }
        putchar('\n');
    }
    putchar('\n');
}
