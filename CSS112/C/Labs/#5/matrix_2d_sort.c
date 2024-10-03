#include <stdio.h>

int main() {
    int row, column, i, j, k, tmp, count = 0;
    int matrix_size_X = 1, matrix_size_Y = 1;
    
    printf("Input order of matrix A m,n: ");
    scanf("%d,%d", &matrix_size_X, &matrix_size_Y);

    int flat_matrix[matrix_size_X * matrix_size_Y];
    int matrix_before_sort[matrix_size_X + 1][matrix_size_Y + 1];
    int matrix_after_sort[matrix_size_X + 1][matrix_size_Y + 1];

    for (row = 1; row <= matrix_size_X; row++) {
        for (column = 1; column <= matrix_size_Y; column++) {
            printf("a[%d][%d] = ", row, column);
            scanf("%d", &flat_matrix[count++]);
            matrix_before_sort[row][column] = flat_matrix[count - 1];
        }
    }

    for (i = 0; i < count; i++) {
        for (j = i; j < count; j++) {
            if (flat_matrix[i] && flat_matrix[j] && flat_matrix[i] > flat_matrix[j]) {
                tmp = flat_matrix[i];
                flat_matrix[i] = flat_matrix[j];
                flat_matrix[j] = tmp;
            }
        }
    }

    count = 0;
    for (row = 1; row <= matrix_size_X; row++) {
        for (column = 1; column <= matrix_size_Y; column++) {
            matrix_after_sort[row][column] = flat_matrix[count++];
        }
    }
    
    printf("\n--------------------\n");
    printf("Matrix before sort :\n");
    for (row = 1; row <= matrix_size_X; row++) {
        for (column = 1; column <= matrix_size_Y; column++) {
            printf("%5d", matrix_before_sort[row][column]);
        }
        printf("\n");
    }
    printf("--------------------\n");

    printf("\n--------------------\n");
    printf("Matrix after sort :\n");
    for (row = 1; row <= matrix_size_X; row++) {
        for (column = 1; column <= matrix_size_Y; column++) {
            printf("%5d", matrix_after_sort[row][column]);
        }
        printf("\n");
    }
    printf("--------------------\n");

    return 0;
}