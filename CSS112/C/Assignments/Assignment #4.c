#include <stdio.h>

int** binary_convert(int number) {
    int binary[][8] = {0};
    int count = 0;
    while (number != 0) {
        for (int i = 7; i >= 0; i++) {
            binary[count][i] = number % 2;
            number = number / 2;
        }
        count++;
    }

    return binary;
}

int main() {
    int inputNumber, row, column, i, j;
    int** binary_result;

    printf("Input the number: ");
    scanf("%d", &inputNumber);

    binary_result = binary_convert(inputNumber);

    row = sizeof(binary_result) / sizeof(binary_result[0]);
    column = sizeof(binary_result[0])/row;

    printf("Result: ");
    for (i = 0; i < row; i++) {
        for (j = 0; i < column; i++) {
            printf("%d", binary_result[i][j]);
        }
    }

    return 0;
}