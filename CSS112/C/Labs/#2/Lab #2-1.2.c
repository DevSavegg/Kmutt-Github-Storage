#include <stdio.h>

int main() {
    int inputNum, i, j, numberToStart;
    int sum = 0;
    printf("Enter end number: ");
    scanf("%i", &inputNum);

    for (i = 0; i < inputNum + 1; i++) {
        if (i == 0) {
            printf("  ");
        } else {
            printf("%4d", i);
        }
    }
    printf("\n");

    for (i = 1; i < inputNum + 1; i++) {
        printf("%2d", i);

        // for (j = 1; j < inputNum + 1; j++) {
        //     // numberToStart = inputNum - (i - 1);

        //     // if (j >= numberToStart) {
        //     //     printf("%4d", j * i);

        //     //     sum = sum + (j * i);
        //     // } else {
        //     //     printf("    ");
        //     // }
        // }

        for (j = 1; j <= inputNum-i; j++) {
            printf("    ");
        }

        for (j = inputNum - i; j < inputNum; j++) {
            printf("%4d", i * (j + 1));
            sum = sum + (i * (j + 1));
        }

        printf("\n");
    }

    printf("==========================\n");
    printf("Sum : %d\n", sum);

    return 0;
}