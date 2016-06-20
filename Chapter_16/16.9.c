#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av) {
    int i;
    int j;
    int k;
    int match;
    int total = 0;
    int num = 30;
    if (ac > 1)
        num = atoi(av[1]);
    int arr[num];
    srand(time(NULL));
    for (i = 0; i < 10000; i++) {
        int match = 0;
        for (j = 0; j < num; j++) {
            arr[j] = rand() % 365;
            for (k = 0; k < j; k++) {
                if (arr[k] == arr[j]) {
                    match = 1;
                }
            }
        }
        if (match) {
            total++;
        }
    }
    printf("%d\t%g", num, (double)total / 10000);
}

