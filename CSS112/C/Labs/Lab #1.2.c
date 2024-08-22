#include <stdio.h>

int main() {

    char operator;

    float number_1 = 0, number_2 = 0;
    float summary;

    printf("Enter Operator: ");
    scanf("%c", &operator);

    printf("Enter number 1: ");
    scanf("%f", &number_1);

    printf("Enter number 2: ");
    scanf("%f", &number_2);

    if (operator == '+') {
        summary = number_1 + number_2;
    } else if (operator == '-') {
        summary = number_1 - number_2;
    } else if (operator == '*') {
        summary = number_1 * number_2;
    } else if (operator == '/') {
        summary = number_1 / number_2;
    } else {
        summary = -1.00;
    }

    printf("********************************\n");
    printf("Result: %.2f %c %.2f = %.2f\n", number_1, operator, number_2, summary);
    printf("********************************\n");

    return 0;
}