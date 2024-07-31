#include <stdio.h>

int main() {
    int requiredAge;
    int input;

    printf("What's your age?\n Answer : ");
    scanf("%i", &input);

    if (input < requiredAge) {
        printf("You're too young to enter this place :(");
    } else {
        printf("Have a nice day sir :)");
    }

    return 0;
}