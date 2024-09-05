#include <stdio.h>

int main() {
    int oddArr[999] = {};
    int evenArr[999] = {};

    int oddCount = 0, evenCount = 0, i, input;

    printf("Input Array : a\n");
    printf("-----------------\n");

    for (i = 0; ;i++) {
        printf("Input a[%2d]: ", i + 1);
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        if (input % 2 == 0) {
            evenArr[evenCount] = input;
            evenCount++;
        } else {
            oddArr[oddCount] = input;
            oddCount++;
        }
    }

    printf("-----------------\n");
    
    printf("Odd Number: ");
    for (i = 0; i < oddCount; i++) {
        printf("%3d", oddArr[i]);
    }
    printf("\nTotal: %d numbers\n", oddCount);

    printf("Even Number : ");
    for (i = 0; i < evenCount; i++) {
        printf("%3d", evenArr[i]);
    }
    printf("\nTotal : %d numbers", evenCount);

    return 0;
}