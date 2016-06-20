#include <stdio.h>
#include <stdlib.h>

float single_tax(float income);

int main(void) {
    float res;
    res = single_tax(1000);
    printf("%f", res);
}

float single_tax(float income) {
    float limit[] = {0, 23350, 56550, 117950, 256600, -1};
    float base[] = {0, 3502.5, 12798.5, 31832.5, 81710.5};
    float percentage[] = {0.15, 0.28, 0.31, 0.36, 0.396};
    int category;
    for(category = 1; income >= limit[category]; category++)
        ;
    category--;
    return base[category] + percentage[category] * (income - limit[category]);
}
