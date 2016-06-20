#include <stdio.h>
#include <stdlib.h>
#define MAX 128

void deblank(char string[]);
int main(void) {
    char string[MAX];
    gets(string);
    printf("%s\n", string);
    deblank(string);
}

void deblank(char string[]) {
    char res[MAX];
    int dst = 0;
    int src = 0;
    int isBlank = 0;
    while(string[src] != '\0') {
        if (string[src] == ' ') {
            isBlank = 1;
        } else {
            if (isBlank == 1) {
                res[dst] = ' ';
                dst++;
                isBlank = 0;
            }
            res[dst] = string[src];
            dst++;
        }
        src++;
    }
    printf("%s\n", res);
}
