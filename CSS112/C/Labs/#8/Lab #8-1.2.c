#include <stdio.h>

int i, j, k, n;

void swap(int* matrix, int startPos, int pos1, int pos2) {
    pos1--;
    pos2--;

    int tmp = matrix[startPos + pos1];
    matrix[startPos + pos1] = matrix[startPos + pos2];
    matrix[startPos + pos2] = tmp;
}

int main() {
    int input, startPos;
    int size_x, size_y;
    int c1, c2;

    printf("Input order of matrix A m,n = ");
    scanf("%d,%d", &size_x, &size_y);

    size_x++;
    size_y++;

    int matrixA[size_x][size_y];

    printf("Input matrix A\n");
    for (i = 1; i < size_x; i++) {
        for (j = 1; j < size_y; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Matrix A before swapping : \n");
    for (i = 1; i < size_x; i++) {
        for (j = 1; j < size_y; j++) {
            printf("%4d", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("Input column number for swapping (c1, c2) : ");
    scanf("%d,%d", &c1, &c2);

    for (i = 1; i < size_x; i++) {
        startPos = i * size_y+1;
        swap(&matrixA[0][0], startPos, c1, c2);
    }

    printf("Output Matrix A : \n");
    for (i = 1; i < size_x; i++) {
        for (j = 1; j < size_y; j++) {
            printf("%4d", matrixA[i][j]);
        }
        printf("\n");
    }

    return 0;
}