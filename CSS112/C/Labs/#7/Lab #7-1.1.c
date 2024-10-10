#include <stdio.h>
#include <math.h>

int main() {
    int i, j, k, n = 0, input;
    int score[100];
    float sd, average, sum = 0;

    for (i = 1;; i++) {
        printf("score[%d] : ", i);
        scanf("%d", &input);

        if (input < 0) {
            break;
        }

        score[i] = input;
        n++;
    }

    for (int i = 1; i <= n; i++) {
        sum = sum + score[i];
    }

    average = sum / n;

    sum = 0;

    for (i = 1; i <= n; i++) {
        sum = sum + powf(score[i] - average, 2);
    }

    sd = sum / n;
    sd = sqrtf(sd);

    printf("\n=======================\n");
    printf("Value of sd: %f", sd);
    printf("\n=======================\n");

    return 0;
}