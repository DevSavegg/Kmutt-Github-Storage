#include <stdio.h>

int main() {
    int i,j,k,m,n,sum= 0;
    int matrix_size_X = 1, matrix_size_Y = 1;

    printf("Input order of matrix A m,n = ");
    scanf("%d,%d", &matrix_size_X, &matrix_size_Y);

    int matrix[matrix_size_X + 1][matrix_size_Y + 1];
    int *matrix_pointer;

    for (i = 1; i <= matrix_size_X; i++) {
        for (j = 1; j <= matrix_size_Y; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 1; i <= matrix_size_X; i++) {
        sum = 0;
        for (matrix_pointer = &matrix[i][1]; matrix_pointer < &matrix[i][matrix_size_Y + 1]; matrix_pointer++) {
            sum = sum + *matrix_pointer;
            printf("%4d", *matrix_pointer);
        }
        printf("    sum of row %d = %3d\n", i, sum);
    }

    return 0;
}