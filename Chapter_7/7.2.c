#include <stdio.h>
#include <stdlib.h>

int gcd (int M, int N);

int main(void) {
    int M, N, res;
    scanf("%d,%d", &M, &N);
    res = gcd(M, N);
    printf("%d\n", res);
}

int gcd(int M, int N) {
    if (M <= 0 || N <= 0) {
        return 0;
    }
    if ( (M % N) == 0) {
        return N;
    }
    return gcd(N, (M%N));
}
