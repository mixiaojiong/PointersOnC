#include <stdio.h>
#include <string.h>

int count_chars(char const *str, char const *chars);

int main(void) {
    char string[] = "helloalb";
    char chars[] = "loab";
    int x = count_chars(string, chars);
    printf("%d", x);
}
int count_chars(char const *str, char const *chars) {
    int count = 0;
    while((str = strpbrk(str, chars)) != NULL) {
        str++;
        count++;
    }
    return count;
}
