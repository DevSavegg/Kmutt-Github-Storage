////////   Libraries   ////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

////////   Declare Functions   ////////

char getch();
int detect_arrow_key();
void clearScreen();
void printTitle();
void printCard(int numberAmount, int* number, char* face);
void solveCardFace(wchar_t *cardFaceVariable, char face);
void solveCardNumber(char *dest, int num);

////////   Constant Variables   ////////

const char *menuOptions[] = {
    "Start Game",
    "Settings",
    "Exit"
};
const int menuSize = sizeof(menuOptions) / sizeof(menuOptions[0]);

////////   Global Variables   ////////

// Counting Variables
int i, j, k, n;

////////   Main Function   ////////

int main() {
    int currentSelection = 0;
    bool isSelected = false;

    setlocale(LC_ALL, "");

    while (!isSelected) {
        clearScreen();
        printTitle();
        
        printf("\n\n\n");

        printf("                               -----------------\n");
        for (i = 0; i < menuSize; i++) {
            printf("                           ");
            if (i == currentSelection) {
                printf("-> | %-15s |\n", menuOptions[i]);
            } else {
                printf("   | %-15s |\n", menuOptions[i]);
            }
        }
        printf("                               -----------------\n");

        switch (detect_arrow_key())
        {
        case 0:
            currentSelection--;
            if (currentSelection < 0) {
                currentSelection = menuSize - 1;
            }
            break;
        case 1:
            currentSelection++;
            if (currentSelection > menuSize - 1) {
                currentSelection = 0;
            }
            break;
        case 2:
            printf("Fuck you\n");
            isSelected = true;
            break ; 
        default:
            break;
        }
    }

    switch (currentSelection)
    {
    case 2:
        clearScreen();
        return 0;
    
    default:
        break;
    }

    printCard(5, (int[]){2, 3, 4, 5, 6}, (char[]){'S', 'H', 'D', 'C', 'S'});
    printCard(4, (int[]){7, 8, 9, 10}, (char[]){'H', 'D', 'C', 'S'});
    printCard(3, (int[]){1, 11, 12}, (char[]){'D', 'C', 'S'});
    printCard(2, (int[]){13, 1}, (char[]){'C', 'S'});
    printCard(1, (int[]){2}, (char[]){'X'});

    return 0;
}









////////   Functions   ////////









char getch() {
    char ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int detect_arrow_key() {
    char ch = getch();

    if (ch == '\n' || ch == '\r') {
        return 2;
    } else if (ch == '\x1b') {
        ch = getch();
        if (ch == '[') {
            ch = getch();
            switch (ch)
            {
            case 'A':
                return 0;
            case 'B':
                return 1;
            default:
                return -1;
            }
        }
    }

    return -1;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows command
    #else
        system("clear");  // Unix-based systems command
    #endif
}

void printTitle() {

printf(
"          __| |____________________________________________________| |__\n"
"          __   ____________________________________________________   __\n"
"            | |                                                    | |  \n"
"            | | ____       _               _   _ _       _     _   | |  \n"
"            | ||  _ \\ ___ | | _____ _ __  | \\ | (_) __ _| |__ | |_ | |  \n"
"            | || |_) / _ \\| |/ / _ \\ '__| |  \\| | |/ _` | '_ \\| __|| |  \n"
"            | ||  __/ (_) |   <  __/ |    | |\\  | | (_| | | | | |_ | |  \n"
"            | ||_|   \\___/|_|\\_\\___|_|    |_| \\_|_|\\__, |_| |_|\\__|| |  \n"
"            | |                                    |___/           | |  \n"
"          __| |____________________________________________________| |__\n"
"          __   ____________________________________________________   __\n"
"            | |                                                    | |  \n"
  );

}

void printCard(int numberAmount, int* number, char* face) {
    if (numberAmount < 0 || numberAmount > 5) {
        printf("Amount of card(s) exceed limit, only up to 5 were allowed.");
        return;
    }

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