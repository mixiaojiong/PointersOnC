#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int my_printf(char *format, ...);

int main(void) {
    char test[10] = "hello";
    char ch = 'x';
    my_printf("%d,%f,%s,%c", 8, 1.1, test, ch);
}
int my_printf(char *format, ...) {
    va_list arg;
    char ch;
    char *str;
    va_start(arg, format);
    while((ch = *format++) != '\0') {
        if (ch != '%') {
            putchar(ch);
            continue;
        }
        switch(*format != '\0' ? *format++ : '\0' ) {
            case 'd':
                printf("%d", va_arg(arg, int));
                break;
            case 'f':
                printf("%f", va_arg(arg, double));
                break;
            case 'c':
                putchar(va_arg(arg, int));
                break;
            case 's':
                str = va_arg(arg, char *);
                while(*str != '\0') {
                    putchar(*str++);
                }
                break;
        }
    }
    return 0;
}
