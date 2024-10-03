#include <stdio.h>

int main() {
    int matrix_size = 1;
    int row, column, sum;
    int count_y;

    printf("Input order of matrix A; n = ");
    scanf("%d", &matrix_size);

    int matrix[matrix_size + 1][matrix_size + 1];
    count_y = matrix_size;

    for (row = 1; row <= matrix_size; row++) {
        for (column = 1; column <= matrix_size; column++) {
            printf("A[%d][%d] = ", row, column);
            scanf("%d", &matrix[row][column]);
        }
    }

    printf("\n------------------------\n");
    sum = 0;
    for (row = 1; row <= matrix_size; row++) {
        for (column = 1; column <= matrix_size; column++) {
            if (row == column) {
                printf("%4d", matrix[row][column]);
                sum = sum + matrix[row][column];
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
    printf("Diagonal 1: %d", sum);
    printf("\n------------------------\n");

    printf("\n------------------------\n");
    sum = 0;
    for (row = 1; row <= matrix_size; row++) {
        for (column = 1; column <= matrix_size; column++) {
            if (column < count_y || column > count_y) {
                printf("    ");
            } else {
                printf("%4d", matrix[row][count_y]);
                sum = sum + matrix[row][count_y];
            }
        }
        count_y--;
        printf("\n");
    }
    printf("Diagonal 2: %d", sum);
    printf("\n------------------------\n");

    return 0;
}