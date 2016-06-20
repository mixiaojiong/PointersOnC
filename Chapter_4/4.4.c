#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void copy_n(char dst[], char src[], int n) {
    int src_index, dst_index;
    src_index = 0;
    for(dst_index = 0;dst_index < n; dst_index++) {
        dst[dst_index] = src[src_index];
        if (src[src_index] != '\0') {
            src_index++;
        }
    }
    printf("%s\n", dst);
}
int main(void) {
    int n = 5;
    char src[MAX] = "he";
    char dst[MAX];
    copy_n(dst, src, n);
}

