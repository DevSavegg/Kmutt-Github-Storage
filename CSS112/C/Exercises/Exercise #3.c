#include <stdio.h>

int main() {

    int count = 0;

    for (int i = 1; i < 1001; i++) {
        if (i % 2 == 1 && i % 7 == 0) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}