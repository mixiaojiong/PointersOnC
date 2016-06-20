#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 510

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("argument error");
        EXIT_FAILURE;
    }
    char buff[BUFF_SIZE];
    FILE *fp;
    for (int i = 2; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            perror(argv[i]);
            EXIT_FAILURE;
        }
        int line = 0;
        while (fgets(buff, sizeof(buff), fp) != NULL) {
            line++;
            if (strstr(buff, argv[1])) {
                printf("%s:%d:%s", argv[i], line, buff);
            }      
        }
    }
}
