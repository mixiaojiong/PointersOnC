#include <stdio.h>
#include <stdlib.h>

#define MAX 10

char *find_char(char const *source, char const *chars);

int main(void) {
    char *source = "ABCDEF";
    char *chars = "XRCEF";
    char *res = find_char(source, chars);
    if (res == NULL) {
        printf("res is null\n");
    } else {
        printf("%c\n", *res);
    }
}
char *find_char(char const *source, char const *chars) {
    char *p;
    if (source != NULL && chars != NULL) {
        while(*source != '\0') {
            p = chars;
            while (*p != '\0') {
                if (*source == *p) {
                    return source;
                }
                p++;
            }
            source++;
        }
    }
    return NULL;
}
