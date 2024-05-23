#include <stdio.h>

double x;
int n;

double expression(int n){
    return (2 * n - 1) * (2 * n - 1) * (x * x) / (4 * n * n + 2 * n);
}
double rec(double prev, int curr, double sum){
    double elem = (curr != 1) ? prev * expression( curr- 1) : x;
    sum += elem;
    if (curr == n){
        return sum;
    }
    else{
        return rec(elem, curr + 1, sum);
    }
}
double cpi(double arg, int totup){
    x = arg;
    n = totup;
    return rec(0, 1, 0);
}
int main(){
    double x = -1;
    while (x >= 1 || x <= -1){
        printf("Input x:\n");
        scanf("%lf", &x);
    }
    printf("Input n:\n");
    scanf("%d", &n);
    double sum = cpi(x, n);
    printf("%.30lf", sum);
    return 0;
}
