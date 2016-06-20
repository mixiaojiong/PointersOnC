#include <stdio.h>
#include <stdlib.h>

int main (void) {
    char buff[80];
    while (fgets(buff, sizeof(buff), stdin) != NULL) {
        fputs(buff, stdout);
    }
}
