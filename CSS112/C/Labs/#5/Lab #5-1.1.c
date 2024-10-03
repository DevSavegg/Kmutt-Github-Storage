#include <stdio.h>

int main() {
    int matrix_size_x = 1, matrix_size_y = 1;
    int row, column, i, j, tmp;

    printf("input order of matrix A; m,n = ");
    scanf("%d,%d", &matrix_size_x, &matrix_size_y);

    int matrix[matrix_size_x + 1][matrix_size_y + 1];

    for (row = 1; row <= matrix_size_x; row++) {
        for (column = 1; column <= matrix_size_y; column++) {
            printf("a[%d][%d] = ", row, column);
            scanf("%d", &matrix[row][column]);
        }
    }

    printf("\n--------------------\n");
    printf("Matrix before sort : \n");
    for (row = 1; row <= matrix_size_x; row++) {
        for (column = 1; column <= matrix_size_y; column++) {
            printf("%5d", matrix[row][column]);
        }
        printf("\n");
    }
    printf("--------------------\n");

    for (row = 1; row <= matrix_size_x; row++) {
        for (column = 1; column <= matrix_size_y; column++) {
            for (j = column + 1; j <= matrix_size_y; j++) {
                if (matrix[row][column] > matrix[row][j]) {
                    tmp = matrix[row][column];
                    matrix[row][column] = matrix[row][j];
                    matrix[row][j] = tmp;
                }
            }
        }
    }

    printf("\n--------------------\n");
    printf("Matrix after sort : \n");
    for (row = 1; row <= matrix_size_x; row++) {
        for (column = 1; column <= matrix_size_y; column++) {
            printf("%5d", matrix[row][column]);
        }
        printf("\n");
    }
    printf("--------------------\n");
}