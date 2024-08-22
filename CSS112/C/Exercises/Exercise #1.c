#include <stdio.h>

int main() {
    float sum = 0;

    float count = 0;

    while (count < 99) {
        count++;
        sum = sum + (count / (count + 1));
    }

    printf("%f", sum);

    return 0;
}