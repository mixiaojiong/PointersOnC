#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A 10.45
#define B 10
#define C -1
#define X 1.78816

double wind_chill(double temp, double velocity);
int main (void) {
    double temp = -5;
    int velocity = 10;
    double ret;
    ret = wind_chill(temp, velocity);
    printf("%f\n", ret);
}
double wind_chill(double temp, double velocity) {
    return 33 - (A + B * sqrt(velocity) + C * velocity) * (33 - temp) / (A + B * sqrt(X) + C * X);
}
