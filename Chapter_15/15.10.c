#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        perror("argument error");
        EXIT_FAILURE;
    }
    char *filename;
    filename = *++argv;
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        EXIT_FAILURE;
    }
    int c;
    int sum = 0;
    while(!feof(fp)) {
        c = fgetc(fp);
        sum += c;
    }
    printf("%d", sum);
}
