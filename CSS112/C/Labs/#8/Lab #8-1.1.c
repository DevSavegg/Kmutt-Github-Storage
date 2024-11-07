#include <stdio.h>

int i, j, k;

int gcd(int* numList, int size, int maxNum) {
    int gcd = 1;
    int FLAG;

    for (i = 1; i <= maxNum; i++) {
        FLAG = 0;

        for (j = 1; j <= size; j++) {
            if (numList[j] % i != 0) {
                FLAG = 1;
                break;
            }
        }

        if (FLAG == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int main() {
    int count = 1, input, res, max = -1;
    int numList[100];

    printf("Input number : \n");
    printf("------------------------\n");

    for (count = 1;; count++) {
        printf("x[%2d] = ", count);
        scanf("%d", &input);

        if (input < 0) {
            count--;
            break;
        }

        if (input > max) {
            max = input;
        }

        numList[count] = input;
    }

    res = gcd(numList, count, max);

    printf("=======================\n");
    printf("The GCD : %d\n", res);
    printf("=======================\n");

    return 0;
}