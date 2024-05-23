#include <stdio.h>
int A[][100];
void shellsort(int mat[], int n) {
    int d, i, j, temp;
    for (d = n / 2; d > 0; d /= 2) {
        for (i = d; i < n; i++) {
            temp = mat[i];
            for (j = i; j >= d && mat[j - d] > temp; j -= d) {
                mat[j] = mat[j - d];
            }
            mat[j] = temp;
        }
    }
}
int main() {
    int m, n;
    printf("number of rows (m): ");
    scanf("%d", &m);
    printf("number of columns (n): ");
    scanf("%d", &n);
    printf("enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nmatrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++) {
        shellsort(A[i], n);
    }
    printf("\nnew martix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
