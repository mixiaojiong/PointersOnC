#include <stdio.h>
#include <string.h>

char const whitespace[] = " \n\r\f\t\v";

int main (void) {
    char buffer[101] = "the sdfdfsdf the fsdfdsfthe:";
    int count = 0;
    char *word;
    for(word = strtok(buffer, whitespace); word != NULL; word = strtok(NULL, whitespace)) {
        if (strcmp(word, "the") == 0) {
            count++;
        }
    }
    printf("%d", count);
}
