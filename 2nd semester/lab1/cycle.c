#include <stdio.h>

double x;

double expression(int n){
    return (2 * n - 1) * (2 * n - 1) * (x * x) / (4 * n * n + 2 * n);
}

double cpi(double arg, int totup){
    x = arg;
    double sum = arg;
    double elem = arg;
    for (int i = 2; i <= totup; i++) {
        elem *= expression(i - 1);
        sum += elem;
    }
    return sum;
}

int main(){
    double arg = -1;
    while (arg >= 1 || arg <= -1){
        printf("Input x:\n");
        scanf("%lf", &arg);
    }
    unsigned int totup;
    printf("Input n:\n");
    scanf("%d", &totup);
    double sum = cpi(arg, totup);
    printf("%.30lf", sum);
    return 0;
}