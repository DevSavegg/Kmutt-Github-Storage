#include <stdio.h>

int main() {
    int N5 = 0, N4 = 0, N3 = 0, N2 = 0, N1 = 0;

    printf(">> ");

    while (1) {
        int input;
        scanf("%i", &input);

        if (input <= 0) {
            break;
        } else if (input < 10) {
            N1++;
        } else if (input < 100) {
            N2++;
        } else if (input < 1000) {
            N3++;
        } else if (input < 10000) {
            N4++;
        } else if (input < 100000) {
            N5++;
        }
    }

    printf("**********************\n");
    printf("N1: %d\nN2: %d\nN3: %d\nN4: %d\nN5: %d\n", N1, N2, N3, N4, N5);
    printf("**********************\n");

    return 0;
}