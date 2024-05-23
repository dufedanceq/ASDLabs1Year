#include <math.h>
#include <stdio.h>

int main() {
    int n;
    double S = 0;
    int counter = 0;
    double cpi = 1;
    double power = 1;
    printf("input n:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        power *= 4;
        cpi *= i + cos(i);
        S += cpi / (power - i);
        counter += 10; // i <= n, i++, *=, *= , +, cos, +=, /, -, jmp
    }
    counter += 5; // =, =, =, i = 1, i <= n
    printf("S = %.7lf\n", S);
    printf("counter = %d\n", counter);
    return 0;
}
