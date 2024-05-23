#include <stdio.h>

double x;
int n;

double expression(int n){
    return (2 * n - 1) * (2 * n - 1) * (x * x) / (4 * n * n + 2 * n);
}
double rec(double prev, int curr){
    double elem = (curr != 1) ? prev * expression(curr - 1) : x;
    if (curr == n){
        return elem;
    }
    else{
        double sum = elem + rec(elem, curr + 1);
        return sum;
    }
}
double cpi(double arg, int count){
    x = arg;
    n = count;
    return rec(0, 1);
}

int main(){
    double arg = -1;
    while (arg >= 1 || arg <= -1){
        printf("Input x:\n");
        scanf("%lf", &arg);
    }
    unsigned int count;
    printf("Input n:\n");
    scanf("%d", &count);
    double sum = cpi(arg, count);
    printf("%.30lf", sum);
    return 0;
}