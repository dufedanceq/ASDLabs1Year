#include <math.h>
#include <stdio.h>
int main(){
    int n;
    double S = 0;
    int counter = 0;
    printf("input n:");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        double cpi = 1;
        double power = 1;
        for(int j = 1; j <= i; j++){
            cpi *= j+ cos(j);
            counter += 6;
        }
        counter += 2;
        for (int p = 0; p < i; p++) {
            power *= 4;
            counter += 4;
        }
        counter += 2;
        S += cpi / (power-i);
        counter += 8;
    }
    counter += 1;
    printf("S = %.7lf\n", S);
    printf("counter = %d\n", counter);
    return 0;
}