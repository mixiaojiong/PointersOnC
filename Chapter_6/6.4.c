#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void Eratiosthenes(int arr[], int x);

int main (void) {
    int x, i;
    int arr[MAX];
    x = 2;
    //初始化
    for(i = 0; i < MAX; i++) {
        arr[i] = 1;
    }
    Eratiosthenes(arr, x);
}

void Eratiosthenes(int arr[], int x) {
    //剔除
    int i;
    for(i = 0; i < MAX; i++) {
        if ((i+1) == x) {
            arr[i] = 0;
        }
    }
    //实现算法
    for(i = 0; i < MAX;i++) {
        if (((i+1) % x) == 0) {
            arr[i] = 0;
        }
    }
    //输出
    for(i = 0; i < MAX;i++) {
        printf("第%d个数为%d\n", i+1, arr[i]);
    }
}
