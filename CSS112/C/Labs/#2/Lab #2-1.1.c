#include <stdio.h>

int main() {

    int startNum, endNum;

    printf("Input begin number: ");
    scanf("%i", &startNum);

    printf("Input end number: ");
    scanf("%i", &endNum);

    for (int i = 1; i < 13; i++) {
        for (int j = startNum; j < endNum + 1; j++) {
            printf("%2d * %2d = %3d   ", j, i, j * i);
        }
        printf("\n");
    }

    return 0;
}