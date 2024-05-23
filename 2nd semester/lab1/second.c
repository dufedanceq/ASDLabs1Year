#include <stdio.h>

double x;

double expression(int n){
    return (2 * n - 1) * (2 * n - 1) * (x * x) / (4 * n * n + 2 * n);
}
double rec(int n, double *sum){
    if (n == 1){
        *sum += x;
        return x;
    }
    double elem = rec(n - 1, sum) * expression(n - 1);
    *sum += elem;
    return elem;
}
void cpi(double arg, int totup, double *sum){
    *sum = 0;
    x = arg;
    rec(totup, sum);
}
int main(){
    double arg = -1;
    while (arg >= 1 || arg <= -1){
        printf("Input x:\n");
        scanf("%lf", &arg);
    }
    unsigned int totup;
    printf("Input n:\n");
    scanf("%u", &totup);
    double sum;
    cpi(arg, totup, &sum);
    printf("%.30lf", sum);
    return 0;
}