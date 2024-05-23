#include <stdio.h>

int main() {
    int n;
    int i, j;
    printf("matrix size:");
    scanf("%d", &n);
    int A[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] =", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    int firstPositive = -1;
    int lastNegative = -1;

    for (i = 0; i < n; i++) {
        if (A[n - 1 - i][i] > 0 && firstPositive == -1) {
            firstPositive = i;
        }
        if (A[n - 1 - i][i] < 0) {
            lastNegative = i;
        }
    }

    if (firstPositive != -1) {
        printf("pershiy dodatniy: A[%d][%d]\n", n - 1 - firstPositive, firstPositive);
    } else {
        printf("nema dodatnih\n");
    }

    if (lastNegative != -1) {
        printf("ostanniy vid'emniy -: A[%d][%d]\n", n - 1 - lastNegative, lastNegative);
    } else {
        printf("nema vid'emnih\n");
    }

    if (firstPositive != -1 && lastNegative != -1) {
        int temp = A[n - 1 - firstPositive][firstPositive];
        A[n - 1 - firstPositive][firstPositive] = A[n - 1 - lastNegative][lastNegative];
        A[n - 1 - lastNegative][lastNegative] = temp;

        printf("new matrix:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d\t", A[i][j]);
            }
            printf("\n");
        }
    }else{
            printf("nemae dodatnih ta/abo vid'emnih elementiv");
    }

    return 0;
}
