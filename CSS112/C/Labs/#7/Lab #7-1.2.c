#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char input[100], alp;
    int base, len, i, j, k, a, n, res, dot_position = -1, space_count = 0;
    float sum = 0;
    int tmp;

    printf("Input Number: ");
    fgets(input, sizeof(input), stdin);

    printf("Input Base: ");
    scanf("%d", &base);

    len = strlen(input) - 1;

    for (n = 0; n < len; n++) {
        if (input[n] == '.') {
            dot_position = n;
            n--;
            break;
        } else if (input[n] == ' ') {
            space_count++;
        }
    }

    if (dot_position == -1) {
        n--;
    }

    n = n - space_count;

    for (i = 0; i < len; i++) {
        if (input[i] == '.' || input[i] == ' ') {
            continue;
        }

        if (isalpha(input[i])) {
            alp = toupper(input[i]);

            if ((base == 16) && (alp < 65 || alp > 70)) {
                printf("\n!!! Digit alphabet out of bound on base 16 (A - F expected); got: %c (index: %d) !!!\n", alp, i);
                return 1;
            }

            a = alp - 55;
        } else {
            alp = input[i];
            a = atoi(&alp);

            if (base == 8 && a > 7) {
                printf("\n!!! Digit out of bound on base 8 (0 - 7 expected); got: %d (index: %d) !!!\n", a, i);
                return 1;
            } else if (base == 2 && a > 1) {
                printf("\n!!! Digit out of bound on base 2 (0 - 1) expected; got: %d (index: %d) !!!\n", a, i);
                return 1;
            }
        }

        //printf("%c, %d, %d\n", input[i], isalpha(input[i]), a);

        sum = sum + (a * pow(base, n--));
    }

    printf("\n=======================\n");
    if (dot_position == -1) {
        printf("Output decimal: %.0f", sum);
    } else {
        printf("Output decimal: %.4f", sum);
    }
    printf("\n=======================\n");

    return 0;
}