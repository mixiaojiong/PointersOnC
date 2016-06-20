#include <stdio.h>
#include <ctype.h>

int palindrome(char *string);

int main(void) {
    char string[] = "Madam, I'm Adam";
    printf("%d", palindrome(string));
}

int palindrome(char *string) {
    char *begin = string;
    while(*string != '\0')
        string++;

    while (begin <= string) {
        while(!isalpha(*begin)) {
            begin++;
        }
        while(!isalpha(*string)) {
            string--;
        }
        if (begin >= string) {
            return 1;
        }
        if (toupper(*begin) != toupper(*string)) {
            return 0;
        }
        begin++;
        string--;
    }
    return 0;
}
