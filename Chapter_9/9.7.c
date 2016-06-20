#include <stdio.h>
#include <string.h>

char *my_strrchr(char *string, char ch);

int main(void) {
    char string[] = "helloalb";
    char *res;
    res = my_strrchr(string, 'l');
    res++;
    if (*res == 'b') {
        printf("right");
    }
}
char *my_strrchr(char *string, char ch) {
    char *res;
    while(*string != '\0') {
        if (*string == ch) {
            res = string;
        }
        string++;
    }
    return res;
}
