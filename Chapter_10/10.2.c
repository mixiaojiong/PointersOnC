#include <stdio.h>

int main(void) {
    struct all{
        float msrp;
        float asp;
    };
    struct loan{
        float msrp;
        float asp;
    };
    struct hire{
        float msrp;
        float asp;
    };
    struct sale {
        char custName[20];
        char custAddr[20];
        char model[20];
        enum {all, loan, hire} type;
        union {
            struct all all;
            struct loan loan;
        }info;
    };
}
