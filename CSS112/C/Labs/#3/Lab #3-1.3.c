#include <stdio.h>

int main() {
    // Variables
    int startDigits[3] = {};
    int guessedDigits[3] = {};

    int correctPositionCount = 0, correctDigitCount = 0, i, j, k, round, is_duplicate = 0;

    // Input for a start numbers
    printf("Input 3 digits a[1],a[2],a[3] : ");
    scanf("%d,%d,%d", &startDigits[0], &startDigits[1], &startDigits[2]);

    // Check if the start input is correct and in range between (1 - 9)
    for (i = 0; i < 3; i++) {
        if (startDigits[i] < 1 || startDigits[i] > 9) {
            printf("Expected startDigit[%d]'s digit to be in range (1 - 9), got %d. Will set to 9 instead\n", i, startDigits[i]);
            startDigits[i] = 9;
        }
    }

    // For-loop text header
    printf("--------------------\n");
    printf("Start Guess 3 Digits\n");
    printf("--------------------\n");

    // For-loop
    for (round = 1; round <= 10; round++) { // As the problem's requirement said, loop 10 times
        // Display round
        printf("Round %d; b[1],b[2],b[3] : ", round);

        // Accept inputs
        scanf("%d,%d,%d", &guessedDigits[0], &guessedDigits[1], &guessedDigits[2]);

        // Check if the guessed input is correct and in range between (1 - 9)
        for (i = 0; i < 3; i++) {
            if (guessedDigits[i] < 1 || guessedDigits[i] > 9) {
                printf("Expected guessedDigit[%d]'s digit to be in range (1 - 9), got %d. Will set to 9 instead\n", i, guessedDigits[i]);
                guessedDigits[i] = 9;
            }
        }

        // Reset both digits and positions correct count
        correctDigitCount = 0;
        correctPositionCount = 0;

        // Setup intersect array
        int guessedIntersectArr[3] = {};
        int intersectCount = 0;

        // Start Loop check the numbers

        // We can set the constant loop round to 3
        // Because we know that the input can't exceed 3 digits.
        for (i = 0; i < 3; i++) { // Start Loop
            for (j = 0; j < 3; j++) { // Guess Loop
                if (guessedDigits[j] == startDigits[i]) {
                    // If the number from guessed array is matching the start numbers

                    // Loop check if number is duplicate
                    is_duplicate = 0;
                    for (k = 0; k < intersectCount; k++) {
                        if(guessedDigits[j] == guessedIntersectArr[k]) {
                            is_duplicate = 1;
                            break;
                        }
                    }

                    if (is_duplicate == 0) {
                        // Insert number to intersect table
                        guessedIntersectArr[intersectCount] = guessedDigits[j];
                        intersectCount++;

                        // Increase correct digit count
                        correctDigitCount++;
                    }

                    if (i == j) {
                            // Increate correct position count
                            correctPositionCount++;
                    }
                }
            }
        }

        // Display result
        printf("Correct %d digit(s) and %d position(s)\n", correctDigitCount, correctPositionCount);

        // Check if the guesser is winning or not
        if (correctPositionCount == 3) {
            // If the guesser is correct in all conditions, display win text and leave the loop

            printf("\n\nYOU WIN!!!");
            break;
        } else if (round == 10) {
            // If this is the last round and guesser cannot guess it right, display lose text

            printf("\n\nYOU LOST :(");
        }
    }

    // End program
    return 0;
}