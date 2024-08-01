#include <stdio.h>

//TODO: Not Finished Yet

int main() {
    int binary_list[] = {128, 64, 32, 16, 8, 4, 2, 1};

    int input[8];
    int size = sizeof(input)/sizeof(input[0]);

    int sum = 0;

    for (int i = 0; i < size; i++) {
        scanf("%i", &input[i]);

        switch (input[i])
        {
        case 1:
            sum += binary_list[i];
            break;

        case 0:
            break;
        
        default:
            printf("Invalid Input");
            break;
        }
    }

    printf("Input Binaries : ");
    for (int i = 0; i < size; i++) {
        printf("%i ", input[i]);
    }

    printf("\nTotal Summary : %i", sum);

    return 0;
}