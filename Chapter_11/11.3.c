#include <stdio.h>
#include <stdlib.h>

char *copy_string();

int main(void) {
    char *res = copy_string();
    printf("%s", res);
    EXIT_SUCCESS;
}
char *copy_string() {
    int max = 100;
    int ch;
    int count = 0;
    char *tmp;
    char *buffer = malloc(max * sizeof(char));
    tmp = buffer;
    if (buffer == NULL) {
        printf("malloc error");
        EXIT_FAILURE;
    }
    while((ch = getchar()) != EOF) {
        if (count >= max) {
            max = max * 2;
            buffer = realloc(buffer, max * sizeof(char));
            if (buffer == NULL) {
                printf("realloc error");
                EXIT_FAILURE;
            }
        }
        *tmp++ = ch;
        count++;
    }
    if (count < max) {
        buffer = realloc(buffer, (count+1) * sizeof(char));
        if (buffer == NULL) {
            printf("realloc error");
            EXIT_FAILURE;
        }
    }
    return buffer;
}
