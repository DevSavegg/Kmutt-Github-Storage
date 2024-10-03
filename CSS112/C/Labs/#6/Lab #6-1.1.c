#include <stdio.h>

int main() {
    int arrA[99], arrB[99], diff[99];
    int i, j, k;
    int end_index_A, end_index_B, diff_index_count = 1;

    int FLAG_IS_DUPLICATE = 0, FLAG_IS_FOUND = 0;

    int *arrA_pointer, *arrB_pointer, *diff_pointer;

    printf("Input set A : \n");
    printf("------------------\n");

    for(i = 1; i <= 99; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arrA[i]);

        if (arrA[i] < 0) {
            end_index_A = i;
            break;
        }
    }

    printf("====================\n");
    printf("Input set B : \n");
    printf("------------------\n");

    for(i = 1; i <= 99; i++) {
        printf("b[%d] = ", i);
        scanf("%d", &arrB[i]);

        if (arrB[i] < 0) {
            end_index_B = i;
            break;
        }
    }

    printf("------------------\n");
    printf("A - B = { ");

    for (arrA_pointer = &arrA[1]; arrA_pointer < &arrA[end_index_A]; arrA_pointer++) {
        FLAG_IS_FOUND = 0;

        for (arrB_pointer = &arrB[1]; arrB_pointer < &arrB[end_index_B]; arrB_pointer++) {
            if (*arrA_pointer == *arrB_pointer) {
                FLAG_IS_FOUND = 1;
                break;
            }
        }

        if (FLAG_IS_FOUND == 1) {
            continue;
        }

        FLAG_IS_DUPLICATE = 0;
        for (diff_pointer = &diff[1]; diff_pointer < &diff[diff_index_count]; diff_pointer++) {
            if (*arrA_pointer == *diff_pointer) {
                FLAG_IS_DUPLICATE = 1;
                break;
            }
        }

        if (FLAG_IS_DUPLICATE == 0) {
            *diff_pointer = *arrA_pointer;
            diff_index_count++;

            if (arrA_pointer < &arrA[end_index_A - 1]) {
                printf("%d, ", *arrA_pointer);
            } else {
                printf("%d ", *arrA_pointer);
            }
        }
    }
    printf("}");

    return 0;
}