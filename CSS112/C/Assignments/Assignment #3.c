#include <stdio.h>

int main() {
    int score[11] = {0};
    int input, i, j, n = 0;
    float sum = 0, average = 0;

    printf("Input student's score: ");
    for (i = 0; ;i++) {

        scanf("%d", &input);

        if (input < 0 || input > 10) {
            break;
        }

        score[input]++;

        sum = sum + input;
        n++;
    }

    average = sum / n;
    printf("================\n");
    printf("Total Number  : %2d\n", n);
    printf("Mean:         : %3.2f\n", average);
    printf("================\n");

    for (i = 10; i >= 1; i--) {
        printf("\n%2d |", i);

        for (j = 1; j <= 10; j++) {
            if (score[j] != 0 && score[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
    }
    printf("\n   ");
    for (i = 1; i <= 10; i++) {
        printf("---");
    }
    printf("\n   ");
    for (i = 1; i <= 10; i++) {
        printf("%3d", i);
    }

    return 0;
}