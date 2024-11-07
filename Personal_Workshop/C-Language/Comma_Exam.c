#include <stdio.h>

int main() {
    char input_number[100];

    int i, j, k, n, count = -1, FLAG_DECIMAL = -1, len;

    printf("Input number : ");
    fgets(input_number, sizeof(input_number), stdin);

    for (len = 0; input_number[len] != '\n'; len++) {
        if (input_number[len] == '.') {
            FLAG_DECIMAL = len;
            count = FLAG_DECIMAL;
        }
    }

    if (FLAG_DECIMAL == -1) {
        count = len;
    }

    printf("--------------------------\n");
    printf("After Format : ");

    for (i = 0; i < count % 3; i++) {
        printf("%c", input_number[i]);
    }

    for (j = count % 3; j < count; j++) {
        //printf("     -%d %d %d-     ", i, j, (j - i) % 3);
        if ((j - i) % 3 == 0 && j != 0) {
            printf(",");
        }
        printf("%c", input_number[j]);
    }

    if (FLAG_DECIMAL != -1) {
        for (k = FLAG_DECIMAL; k < len; k++) {
            printf("%c", input_number[k]);
        }
    }

    printf("\n--------------------------\n");

    return 0;
}