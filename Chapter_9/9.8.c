#include <stdio.h>
#include <string.h>

char *my_strnchr(char *string, char ch, int which);

int main(void) {
    char string[] = "helloalb";
    char *res;
    res = my_strnchr(string, 'l', 2);
    res++;
    if (*res == 'o') {
        printf("right");
    }
}
char *my_strnchr(char *string, char ch, int which) {
    char *res;
    while(--which >= 0 && (res = strchr(string, ch)) != NULL) {
        string = res + 1;
    }
    return res;
}
