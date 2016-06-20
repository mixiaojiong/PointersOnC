#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 80

int main (void) {
    char buff[BUFSIZE];
    FILE *file;
    if ((file = fopen("family.txt", "r")) == NULL) {
        perror(buff);
        exit(EXIT_FAILURE);
    }
    int age[10];
    int num;
    while (fgets(buff, sizeof(buff), file) != NULL) {
        int sum = 0;
        num = sscanf(buff, "%d %d %d %d %d %d %d %d %d %d", age, age + 1, age + 2, age + 3, age + 4, age + 5, age + 6, age + 7, age + 8, age + 9);
        if (num == 0) {
            continue;
        }
        for (int i = 0; i < num; i++) {
            sum += age[i];
        }
        double res = sum / num;
        printf("%5.2f: %s", res, buff);
    }
}
