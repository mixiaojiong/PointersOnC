#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128

int main(void) {
    char input[MAX];
    char tmp[MAX];
    int flag = 0;
    while (gets(input) != NULL) {
        if (strcmp(tmp, input) == 0) {
            flag = 1;
        } else {
            if (flag) {
                printf("%s\n", tmp);
            }
            flag = 0;
            strcpy(tmp, input);
        }
    }
}
