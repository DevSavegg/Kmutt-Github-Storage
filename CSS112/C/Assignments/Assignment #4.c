#include <stdio.h>

void binary_convert(int binaryArray[][8], int number, int rows) {
    for (int count = rows - 1; count >= 0; count--) {
        for (int i = 7; i >= 0; i--) {
            binaryArray[count][i] = number % 2;
            number = number / 2;
        }
    }
}

int main() {
    int inputNumber, i, j;
    int row, column = 8;

    printf("Input the number: ");
    scanf("%d", &inputNumber);

    row = (inputNumber == 0) ? 1 : (sizeof(int) * 8 - __builtin_clz(inputNumber) + 7) / 8;

    int binary_result[row][column];

    binary_convert(binary_result, inputNumber, row);

    printf("Result:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%d", binary_result[i][j]);
        }
        printf("\n");
    }

    return 0;
}