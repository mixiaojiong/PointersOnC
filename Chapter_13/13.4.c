#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define array_size 6
int comp_int(int* a, int *b){
    return *a - *b;
}
//返回0失败,1成功
int swap(void *a, void *b, unsigned int elem_size){
    char *temp = (char *)malloc(elem_size);
    if(temp == NULL)
        return 0;
    memcpy(temp, a, elem_size);
    memmove(a, b, elem_size);
    memmove(b, temp, elem_size);
    free(temp);
    return 1;
}
//打印数组
void print_array(char *array, unsigned int elem_size){
    for(int i=0; i < array_size; i++)
        printf( "%d\t", *(int *)(array + i * elem_size));
    printf( "\n");
}
//子函数，返回分割点
char* partition(char *array,
        char *first,
        char *last,
        unsigned int elem_size,
        int (*comp)(void *a, void *b)){
    char *temp = last;
    char *slow = first - elem_size;
    char *fast = first;
    for(;fast <last; fast += elem_size){
        if((*comp)(fast, temp) <= 0){
            slow += elem_size;
            if(slow != fast)
                swap(slow, fast, elem_size);
        }
    }
    char *pivot = slow + elem_size;
    swap(pivot, temp, elem_size);
    print_array(array, elem_size);
    printf("pivot is %d. \n" ,*pivot);
    return pivot;
}
void quick_sort(void *array, char *first, char *last, unsigned int elem_size, int (*comp)(void *a, void *b)){
    if(first < last){
        char *pivot = partition(array , first, last, elem_size, comp);
        quick_sort( array, first, pivot-elem_size, elem_size, comp);
        quick_sort( array, pivot+elem_size, last, elem_size, comp);
    }
}
int main(int argc, char **argv){
    int array [array_size] = {3,25,18,2,40,1};
    unsigned elem_size = sizeof (int);
    char *first = (char *)array;
    char *last = first + (array_size - 1) * elem_size;
    printf( "original array is: \n");
    print_array( array, elem_size);
    printf( "\n");
    quick_sort( array, first, last, elem_size, comp_int);
    return 0;
}
