#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void insertion_sort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));
int cmp(const void *, const void *);
int main(int ac, char **av) {
    int arr[5] = {10, 3, 4, 9, 2};
    insertion_sort(arr, 5, sizeof(int), cmp);
    for (int i = 0; i < 5; i++ ){
        printf("%d\t", arr[i]);
    }
}
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;  //升序排序
}

void insertion_sort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *)) {
    char *array;
    char *temp;
    int i;
    int next_el;
    array = base;
    temp = malloc(width);
    assert(temp != NULL);
    for (next_el = 1; next_el < nel; next_el++) {
        char *i_ptr = array;
        char *next_ptr = array + next_el * width;
        for (i = 0; i < next_el; i++, i_ptr += width) {
            if (compar(next_ptr, i_ptr) < 0) {
                break;
            }
        }
        if (i == next_el)
            continue;

        memcpy(temp, next_ptr, width);
        memmove(i_ptr + width, i_ptr, (next_el - i) * width);
        memcpy(i_ptr, temp, width);
    }
    free(temp);
}

