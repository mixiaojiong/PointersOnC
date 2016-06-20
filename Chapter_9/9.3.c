#include <stdio.h>
#include <string.h>
char *my_strcpy(char *des, char const *src, int size);

int main(void) {
    char test[] = "hello";
    char des[3];
    char *res = my_strcpy(des, test, 3);
    while(*res != '\0') {
        putchar(*res);
        res++;
    }
}
char *my_strcpy(char *des, char const *src, int size) {
    strncpy(des, src, size);
    des[size - 1] = '\0';
    return des;
}
