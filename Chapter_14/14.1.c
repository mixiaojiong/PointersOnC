#include <stdio.h>

void print_ledger(int x);
int main(void) {
    print_ledger(10);
}

void print_ledger(int x) {
#ifdef OPTION_LONG
#define OK 1
    print_ledger_long(x);
#endif

#ifdef OPTION_DETAILED
#define OK 1
    print_ledger_detailed(x);
#endif

#ifdef OK
    print_ledger_default(x);
#endif
}
