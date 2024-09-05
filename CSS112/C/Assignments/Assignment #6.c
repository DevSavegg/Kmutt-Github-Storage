#include <stdio.h>

int main() {
    char words[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char numbers[11];

    printf("Input: ");
    for (int i = 0; i < 10; i++) {
        scanf("%c", &numbers[i]);
        if (numbers[i] == '\n' || i == 9) {
            break;
        }
    }

    printf("Output: \n");
    for (int i = 0; i < 10; i++) {
        printf("%s ", words[numbers[i] - 48]);
    }

    return 0;
}