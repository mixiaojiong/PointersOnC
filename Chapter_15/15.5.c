#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 80

FILE *openfile(char *prompt, char *mode);

int main (void) {
    FILE *read = openfile("input", "r");
    FILE *write = openfile("output", "w");
    char buff[BUFSIZE];
    int val;
    int total = 0;
    while (fgets(buff, sizeof(buff), read) != NULL) {
        if (sscanf(buff, "%d", &val) == 1) {
            total += val;
        }
        fputs(buff, write);
    }
    fprintf(write, "%d", total);
    fclose(read);
    fclose(write);
    return EXIT_SUCCESS;
}
FILE *openfile(char *prompt, char *mode) {
    char buff[BUFSIZE];
    FILE *file;
    printf("please input %s file: ", prompt);
    if (gets(buff) == NULL) {
         fprintf( stderr, "Missing %s file name.\n", prompt );
         exit( EXIT_FAILURE );
    }
    if ((file = fopen(buff, mode)) == NULL) {
        perror(buff);
        exit(EXIT_FAILURE);
    }
    return file;
}
