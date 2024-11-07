#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char input;

void clearScreen();

int main() {

    while (1) {
        clearScreen();

        printf("========== Product Manager ==========\n");
        
        puts("\n[[[[ Function Menu ]]]]\n");
        puts("[A] : Add Product");
        puts("[E] : Edit Product");
        puts("[R] : Remove Product");
        puts("[D] : Display All Products");
        puts("[X] : Exit Program\n");

        printf("=====================================\n");
        
        printf("Input : ");
        scanf("%c", &input);
        getchar();

        printf("=====================================\n");
        printf("%c", tolower(input));
        switch (tolower(input))
        {
        case 'a':
            /* code */
            printf("Hi");
            break;
        case 'e':
            /* code */
            break;
        case 'r':
            /* code */
            break;
        case 'd':
            /* code */
            break;
        case 'x':
            goto exit;
            break;
        default:
            goto error;
            break;
        }
    }

    return 0;

exit:
    clearScreen();

    printf("All Data Saved Successfully, Exit Program.");

    return 0;

error:
    clearScreen();

    printf("An error occured while on runtime state, exit.");

    return 1;
}

void clearScreen() {
    printf("\033[H\033[J");
}