#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isNotPrint(int c) {
    return !isprint(c);
}

int (*oper_func[]) (int) = {
        iscntrl,
        isspace,
        isdigit,
        islower,
        isupper,
        ispunct,
        isNotPrint
};
char *label[] = {
        "iscntrl",
        "isspace",
        "isdigit",
        "islower",
        "isupper",
        "ispunct",
        "isNotPrint"
};
#define N  (sizeof(oper_func))  / sizeof(oper_func[0])
int main (void) {
    int count[N];
    int ch;
    int total = 0;
    int i;
    for(i = 0; i < N; i++) {
        count[i] = 0;
    }
    while(( ch = getchar()) != EOF) {
        total++;
        for(i = 0; i < N; i++) {
            if (oper_func[i](ch)) {
                count[i]++;
            }
        }
    }
    for(i = 0; i < N; i++) {
        printf("%3.0f   %s\n", count[i] * 100.0 / total, label[i]);
    }
}


