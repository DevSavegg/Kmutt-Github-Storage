#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

void clearScreen();
void printTitle();
void printCard(int numberAmount, int* number, char* face);
void solveCardFace(wchar_t *cardFaceVariable, char face);
void solveCardNumber(char *dest, int num);

int main() {
    setlocale(LC_ALL, "");

    clearScreen();
    printTitle();

    printCard(5, (int[]){2, 3, 4, 5, 6}, (char[]){'S', 'H', 'D', 'C', 'S'});
    printCard(4, (int[]){7, 8, 9, 10}, (char[]){'H', 'D', 'C', 'S'});
    printCard(3, (int[]){1, 11, 12}, (char[]){'D', 'C', 'S'});
    printCard(2, (int[]){13, 1}, (char[]){'C', 'S'});
    printCard(1, (int[]){2}, (char[]){'X'});
}







//          Functions           //







void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows command
    #else
        system("clear");  // Unix-based systems command
    #endif
}

void printTitle() {

printf(
"__| |____________________________________________________| |__\n"
"__   ____________________________________________________   __\n"
"  | |                                                    | |  \n"
"  | | ____       _               _   _ _       _     _   | |  \n"
"  | ||  _ \\ ___ | | _____ _ __  | \\ | (_) __ _| |__ | |_ | |  \n"
"  | || |_) / _ \\| |/ / _ \\ '__| |  \\| | |/ _` | '_ \\| __|| |  \n"
"  | ||  __/ (_) |   <  __/ |    | |\\  | | (_| | | | | |_ | |  \n"
"  | ||_|   \\___/|_|\\_\\___|_|    |_| \\_|_|\\__, |_| |_|\\__|| |  \n"
"  | |                                    |___/           | |  \n"
"__| |____________________________________________________| |__\n"
"__   ____________________________________________________   __\n"
"  | |                                                    | |  \n"
  );

}

void printCard(int numberAmount, int* number, char* face) {
    if (numberAmount < 0 || numberAmount > 5) {
        printf("Amount of card(s) exceed limit, only up to 5 were allowed.");
        return;
    }
    int i;
    wchar_t card[3];
    
    for (i = 0; i < numberAmount; i++) {
        printf("┌─────────────┐    ");
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        if (face[i] == 'X') {
            printf("│X            │    ");
        } else if (number[i] > 1 && number[i] < 11) {
            printf("│%-2d           │    ", number[i]);
        } else {
            char num[2];
            solveCardNumber(num, number[i]);
            printf("│%s            │    ", num);
        }
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        printf("│             │    ");
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        printf("│             │    ");
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        printf("│             │    ");
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        wchar_t card;
        solveCardFace(&card, face[i]);
        wprintf(L"│      %lc      │    ", card);
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        printf("│             │    ");
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        printf("│             │    ");
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        printf("│             │    ");
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        if (face[i] == 'X') {
            printf("│            X│    ");
        } else if (number[i] > 1 && number[i] < 11) {
            printf("│           %2d│    ", number[i]);
        } else {
            char num[2];
            solveCardNumber(num, number[i]);
            printf("│            %s│    ", num);
        }
    }
    printf("\n");
    for (i = 0; i < numberAmount; i++) {
        printf("└─────────────┘    ");
    }
    printf("\n");
}

void solveCardNumber(char *dest, int num) {
    char cardNum[4];
     if (num == 11) {
        cardNum[0] = 'J';
    } else if (num == 12) {
        cardNum[0] = 'Q';
    } else if (num == 13) {
        cardNum[0] = 'K';
    } else if (num == 1) {
        cardNum[0] = 'A';
    } else {
        printf("Number of card exceed limit, 1 | 11 | 12 | 13 expected.");
        return;
    }
    cardNum[1] = '\0';

    memcpy(dest, cardNum, 2);
}

void solveCardFace(wchar_t *cardFaceVariable, char face) {
    switch (face)
    {
    case 'S':
        *cardFaceVariable = L'♠';
        break;
    case 'H':
        *cardFaceVariable = L'♥';
        break;
    case 'D':
        *cardFaceVariable = L'♦';
        break;
    case 'C':
        *cardFaceVariable = L'♣';
        break;
    case 'X':
        *cardFaceVariable = L'X';
        break;
    default:
        printf("Card character not found, (S [Spades], H [Hearts], D [Diamonds], C) expected.");
        return;
    }
}