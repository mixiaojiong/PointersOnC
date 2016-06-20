#include <stdio.h>

size_t my_strnlen(char const *string, int size);

int main (void) {
    char test[4] = "hell";
    size_t x = my_strnlen(test, 4);
    printf("%lu\n", x);
}

size_t my_strnlen(char const *string, int size) {
    register size_t length;
    for (length = 0; length < size; length++) {
        if (*string++ == '\0') {
            break;
        }
    }
    return length;
}

