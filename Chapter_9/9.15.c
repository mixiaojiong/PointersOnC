#include <stdio.h>
#include <string.h>

void dollars(char *dst, char const *src);

int main(void) {
    char src[100];
    char dst[100];
    while(gets(src)) {
        dollars(dst, src);
        printf("src is :%s\t%s\n", src, dst);
    }
}

void dollars(char *dst, char const *src) {
    int len;
    if (dst == NULL || src == NULL)
        return;
    *dst++ = '$';
    len = strlen(src);
    if (len >= 3) {
        int i;
        for (i = len - 2; i > 0;) {
            *dst++ = *src++;
            if (--i > 0 && i % 3 == 0) {
                *dst++ = ',';
            }
        }
    } else {
        *dst++ = '0';
    }
    *dst++ = '.';
    *dst++ = len < 2 ? '0' : *src++;
    *dst++ = len < 1 ? '0' : *src;
    *dst = '\0';
}

