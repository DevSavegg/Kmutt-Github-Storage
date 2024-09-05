#include <stdio.h>
#define LENGTH 50

int main() {
    char words[LENGTH] = {0};

    printf("Input: ");
    for (int i = 0; i < LENGTH; i++) {
        scanf("%c", &words[i]);
        if (words[i] == '\n') {
            break;
        }
    }

    printf("Output: ");
    for (int i = 0; i < LENGTH; i++) {
        printf("%c", words[i]);
    }

    return 0;
}