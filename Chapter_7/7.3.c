#include <stdio.h>
#include <stdlib.h>

int ascii_to_integer(char *string);
int main(void) {
    char str[10] = "234";
    int res;
    res = ascii_to_integer(str);
    printf("%d\n", res);
}
int ascii_to_integer(char *string) {
    int res = 0;
    while(*string != '\0') {
        if (*string >= '0' && *string <= '9') {
            res *= 10;
            res += *string - '0';
        } else {
            return 0;
        }
        string++;
    }
    return res;
}
