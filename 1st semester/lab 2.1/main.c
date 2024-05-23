#include <stdio.h>
int n;
void algoritm1(int A[][n], int m, int x, int j) {
    int L = 0, R = m - 1;

    while (L <= R) {
        int i = (R + L) / 2;

        if (A[i][j] == x) {
            printf("element %d found at position (%d, %d).\n", x, i, j);
            return;
        }
        if (x < A[i][j]) {
            R = i - 1;
        } else {
            L = i + 1;
        }
    }
    printf("element %d not found in column %d.\n", x, j);
}
int main() {
    int m;
    printf("rows (m): ");
    scanf("%d", &m);
    printf("columns (n): ");
    scanf("%d", &n);
    int A[m][n];
    printf("enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < n; j++) {
        for (int element = 0; element <= 5; element++) {
            algoritm1(A, m, element, j);
        }
    }
    return 0;
}
