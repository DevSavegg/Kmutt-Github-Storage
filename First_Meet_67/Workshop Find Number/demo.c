#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1

void main() {
    int list[] = {50, 30, 80, 10, 40, 90, 20, 70, 60, 100};
    int length = sizeof(list)/sizeof(list[0]);

    int input;
    int isFound;

    scanf("%i", &input);

    for (int i = 0; i < length; i++) {
        if (list[i] == input) {
            printf("Value %d found at index %d\n", list[i], i);
            isFound = 1;
            break;
        }
    }

    if (isFound != 1) {
        printf("Value %d not found in the array\n", input);
    }

    return;
}