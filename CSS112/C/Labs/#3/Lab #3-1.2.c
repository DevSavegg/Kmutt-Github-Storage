#include <stdio.h>

int main() {
    int aArr[999] = {};
    int bArr[999] = {};
    int intersectArr[999] = {};

    int input, i, j, k, size_a = 0, size_b = 0, size_intersect = 0, is_duplicate = 0;

    printf("Input Set A : \n");
    printf("-----------------\n");

    for (i = 0; ; i++) {
        printf("a[%d]: ", i + 1);
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        aArr[i] = input;
        size_a++;
    }

    printf("\nInput Set B : \n");
    printf("-----------------\n");

    for (i = 0; ; i++) {
        printf("b[%d]: ", i + 1);
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        bArr[i] = input;
        size_b++;
    }

    printf("\n-----------------\n");

    for (i = 0; i < size_a; i++) {
        for (j = 0; j < size_b; j++) {

            if (bArr[j] == aArr[i]) {
                is_duplicate = 0;

                for (k = 0; k < size_intersect; k++) {
                    if (bArr[j] == intersectArr[k]) {
                        is_duplicate = 1;
                        break;
                    }
                }

                if (is_duplicate == 0) {
                    intersectArr[size_intersect] = bArr[j];
                    size_intersect++;
                }
            }
        }
    }

    printf("The intersect of set a and b is : ");
    if (size_intersect == 0) {
        printf("Empty Set\n");
    } else {
        printf("{");
        for (i = 0; i < size_intersect; i++) {
            if (i == size_intersect - 1) {
                printf("%d", intersectArr[i]);
            } else {
                printf("%d, ", intersectArr[i]);
            }
        }

    printf("}\n");
    }

    return 0;
}