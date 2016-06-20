#include <stdio.h>
#include <stdlib.h>

int numeric_palindrome(int value);

int main (void) {
    int value ;
    scanf("%d", &value);
    printf("%d", numeric_palindrome(value));
}
int numeric_palindrome(int value) {
    if (!value) {
        return value;
    }
    int tmp = value;
    int res = 0;
    do {
       res = res * 10 + tmp % 10;
       tmp /= 10;
    } while (tmp);

    return value == res;
}
