#include <stdio.h>
char *my_strcpy_end(char *dst, char const *src);

int main(void) {
    char src[] = "hello";
    char dst[10];
    char *res;
    res = my_strcpy_end(dst, src);
    if (*res == '\0') {
        printf("right");
    }
}
char *my_strcpy_end(char *dst, char const *src) {
    while ((*dst++ = *src++) != '\0')
        ;
    return dst - 1;
}
