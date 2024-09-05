#include <stdio.h>

void binary_convert(long long int binaryArray[][8], long long int number, long long int rows) {
    for (long long int count = rows - 1; count >= 0; count--) {
        for (long long int i = 7; i >= 0; i--) {
            binaryArray[count][i] = number % 2;
            number = number / 2;
        }
    }
}

int main() {
    long long int inputNumber, i, j;
    long long int row, column = 8;

    printf("Input the number: ");
    scanf("%lld", &inputNumber);

    row = (inputNumber == 0) ? 1 : (sizeof(long long int) * 8 - __builtin_clz(inputNumber) + 7) / 8;

    long long int binary_result[row][column];

    binary_convert(binary_result, inputNumber, row);

    printf("Result:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("%lld", binary_result[i][j]);
        }
        printf("\n");
    }

    return 0;
}