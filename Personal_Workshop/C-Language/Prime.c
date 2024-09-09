#include <stdio.h>

int main() {
    int primeNum = 13;

    // printf("Enter prime number: ");
    // scanf("%d", &primeNum);

    long long int result[primeNum];

    // Initialize result array
    for (int i = 1; i < primeNum; i++) {
        result[i] = 0;
    }

    // Precompute powers mod primeNum
    for (int a = 1; a < primeNum; a++) {
        long long int value = 1;  // a^0 % primeNum is 1
        for (int b = 1; b < primeNum; b++) {
            value = (value * a) % primeNum;
            result[value]++;
        }
    }

    // Print result
    for (int i = 1; i < primeNum; i++) {
        printf("%lld ", result[i]);
    }

    return 0;
}
