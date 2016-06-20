#include <stdio.h>
#include <stdlib.h>

void reverse_string(char *str);
int main (void) {
    char str[] = "hello";
    reverse_string(str);
}
void reverse_string(char *str) {
    char *last, *res;
    last = str;
    res = str;
    while (*last != '\0') {
        last++;
    }
    last--;
    while (str < last) {
        char temp;
        temp = *str;
        *str++ = *last;
        *last-- = temp;
    }
    printf("%s\n", res);
    printf("%s\n", str);
    printf("%s\n", last);
}

