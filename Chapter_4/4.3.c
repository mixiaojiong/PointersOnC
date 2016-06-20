#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a,b,c;
    printf("please input first line.\n");
    scanf("%d", &a);
    printf("please input second line.\n");
    scanf("%d", &b);
    printf("please input third line.\n");
    scanf("%d", &c);

    if (((a+b) > c) && ((a+c) > b) && ((b+c) > a)) {
        if (a == b && a == c && b ==c) {
            printf("等边三角形");
        } else if (a == b || a == c || b == c) {
            printf("等腰三角形");
        } else {
            printf("三角形");
        }

    } else {
        printf("input error");
    }
}
