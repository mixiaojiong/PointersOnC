#include <stdio.h>
#include <string.h>
char *my_strcat(char *des, char const *src, int size);
size_t my_strnlen(char const *string, int size);

int main(void) {
    char test[] = "hello";
    char des[10] = "aa";
    char *res = my_strcat(des, test, 7);
    while(*res != '\0') {
        putchar(*res);
        res++;
    }
}
char *my_strcat(char *des, char const *src, int size) {
    int length;
    size--;
    length = size - my_strnlen(des, size);
    if (length > 0) {
        strncat(des, src, length);
        des[size]  = '\0';
    }
    return des;
}
size_t my_strnlen(char const *string, int size) {
    register size_t length;
    for (length = 0; length < size; length++) {
        if (*string++ == '\0') {
            break;
        }
    }
    return length;
}

