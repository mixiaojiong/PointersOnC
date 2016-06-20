#include <stdio.h>
#include <stdlib.h>

int main (void) {
    char buff[256];
    while (fgets(buff, sizeof(buff), stdin) != NULL) {
        fputs(buff, stdout);
    }
}
