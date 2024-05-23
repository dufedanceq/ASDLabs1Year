#include <stdio.h>

int main() {
    float x, y = 0;

    printf("input x:");
    scanf("%f", &x);

    if ((x >= 0 && x <= 8) || (x >= 16)) {
        y = -3 * x * x / 5 + 9;
        printf("y = %f", y);
    } else{
        if(x < -1) {
            y = 15 * x - 2;
            printf("y = %f", y);
        } else {
            printf("no value for x");
        }
    }
    return 0;
}