#include <stdio.h>
#include <stdlib.h>

int del_substr(char *str, char const *substr);
char *match(char *str, char *want);

int main(void) {
    char *str = "ABCDEFG";
    char *substr = "CDE";

    int res;
    res = del_substr(str, substr);
    printf("%d\n",  res);
}

int del_substr(char *str, char const *substr) {
    char *next;
    while(*str != '\0') {
        next = match(str, substr);
        if (next != NULL) {
            break;
        }
        str++;
    }
    if (*str == '\0') {
        return 0;
    }
    while (str = next) {
        if (*next == '\0') {
            break;
        }
        str++;
        next++;
    }
    return 1;
}
char *match(char *str, char *want) {
    while (*want != '\0') {
        if (*str++ != *want++) {
            return NULL;
        }
    }
    return str;
}
