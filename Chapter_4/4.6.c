#include <stdio.h>
#include <stdlib.h>
#define MAX 128

int substr(char dst[], char src[], int start, int len);
int main(void) {
    char src[MAX] = "hello";
    char dst[MAX];
    int res = substr(dst, src, 3, 5);
    printf("%d\n", res);
}

int substr(char dst[], char src[], int start, int len) {
    int src_index;
    int dst_index;
    if (start < 0 || len < 0) {
        return 0;
    }
    for(src_index = 0; src_index < start; src_index++) {
        if (src[src_index] == '\0') {
            return -1;
        }
    }
    for(dst_index = 0; dst_index < len; dst_index++) {
        if (src[src_index] == '\0') {
            break;
        }
        dst[dst_index] = src[src_index];
        src_index++;
    }
    printf("%s\n", dst);
    return 1;
}
