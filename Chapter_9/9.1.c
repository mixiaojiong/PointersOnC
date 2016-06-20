#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    float control, speace, digit, lower, upper, punct, notPrint, total;
    control = speace = digit = lower = upper = punct = notPrint = total = 0;
    while((ch = getchar()) != EOF) {
        if (iscntrl(ch)) {
            control++;
        }
        if (isspace(ch)) {
            speace++;
        }
        if (isdigit(ch)) {
            digit++;
        }
        if (islower(ch)) {
            lower++;
        }
        if (isupper(ch)) {
            upper++;
        }
        if (ispunct(ch)) {
            punct++;
        }
        if (!isprint(ch)) {
            notPrint++;
        }
        total++;
    }
    printf("control is %.2f\n", (control / total));
    printf("space is %.2f\n", (speace / total));
    printf("digit is %.2f\n", (digit / total));
    printf("lower is %.2f\n", (lower / total));
    printf("upper is %.2f\n", (upper / total));
    printf("punct is %.2f\n", (punct / total));
    printf("notPrint is %.2f\n", (notPrint / total));
}
