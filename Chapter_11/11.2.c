#include <stdio.h>
#include <stdlib.h>

int *my_array();

int main(void) {
    int *x = my_array();
    for(int i = 0;i <= x[0]; i++) {
        printf("%d\n", x[i]);
    }
    EXIT_SUCCESS;
}
int *my_array() {
    int *array;
    int max = 100;
    int val;
    array = malloc(max * sizeof(int));
    if (array == NULL) {
        printf("malloc error");
        EXIT_FAILURE;
    }
    int count = 0;
    while(scanf("%d", &val) == 1) {
        count++;
        if (count > max) {
            max = max * 2;
            array = realloc(array, max * sizeof(int));
            if (array == NULL) {
                printf("realloc error");
                EXIT_FAILURE;
            }
        }
        array[count] = val;
    }
    if (count < max) {
        array = realloc(array, (count + 1) * sizeof(int));
        if (array == NULL) {
            printf("realloc error");
            EXIT_FAILURE;
        }
    }
    array[0] = count;
    return array;
}
