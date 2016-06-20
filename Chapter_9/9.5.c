#include <stdio.h>
#include <string.h>
void my_strncat(char *dst, char const *src, int dst_len);

int main(void) {
    char test[] = "hello";
    char dst[10] = "aa";
    my_strncat(dst, test, 10);
    printf("%s\n", dst);
}

void my_strncat(char *dst, char const *src, int dst_len) {
    int len;
    len = strlen(dst);
    dst_len -= len + 1;
    if (dst_len > 0) {
        strncat(dst + len, src, dst_len);
    }
}
