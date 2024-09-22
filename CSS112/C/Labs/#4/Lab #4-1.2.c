#include <stdio.h>
#include <string.h>

int main() {
    char input[999];
    int i, n, len, sum = 1;

    printf("Input sentence: ");
    fgets(input, sizeof(input), stdin);

    len = strlen(input);

    for (i = 0; i < len; i++) {
        // If input with the index of i-th is a lower character and not a spacebar (ASCII)
        if (input[i] > 90 && input[i] != 32) {
            input[i] = input[i] - 32;
        }

        if (input[i] == ' ') {
            printf("\n");
            sum++;
        } else {
            printf("%c", input[i]);
        }
    }

    printf("Total words: %d", sum);

    return 0;
}