#include <stdio.h>
#include <math.h>

int main() {
    for (int i = 100; i < 1000; i++) {
        int num1, num2, num3;
        num1 = i/100;
        num2 = i/10;
        num3 = i - (num1 * 100) - (num2 * 10);

        printf("%d %d %d\n", num1, num2, num3);

        if (pow(num1, 3) + pow(num2, 3) + pow(num3, 3) == i) {
            printf("N = %d\n", i);
        }
    }

    return 0;
}