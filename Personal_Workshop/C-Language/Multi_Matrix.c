#include <stdio.h>

int main() {
    int m, n, p, i, j, k, sum;

    printf("Input matrix length A[m x n] B[n x p] (m,n,p) : ");
    scanf("%d,%d,%d", &m, &n, &p);

    int A[m][n], B[n][p], C[m][p];

    printf("-------------------------\n");
    printf("Input matrix A: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("-------------------------\n");
    printf("Input matrix B: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            sum = 0;

            for (k = 1; k <= n; k++) {
                sum = sum + A[i][k] * B[k][j];
            }

            C[i][j] = sum;
        }
    }

    printf("-------------------------\n");
    printf("Matrix C: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            printf("%5d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}