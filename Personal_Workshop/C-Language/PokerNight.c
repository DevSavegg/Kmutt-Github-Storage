////////   Libraries   ////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

////////   Declare Functions   ////////

// Input Related
char getch();
int detect_pressed_key(char target);
int detect_arrow_key();

// Graphic Related
void clearScreen();

void printTitle();
void printSettings();

void printCard(int numberAmount, int* number, char* face);

// Logical Related
void solveCardFace(wchar_t *cardFaceVariable, char face);
void solveCardNumber(char *dest, int num);

////////   Constant Variables   ////////

const char *currency = "$";

const char *maxPlayerText = "8 Players";
const char *maxInitialMoneyText = "1M";

const char *cardRanks[] = {
    "High Card",
    "One Pair",
    "Two Pair",
    "Three of A Kind",
    "Straight",
    "Flush",
    "Full House",
    "Four of A Kind",
    "Straight Flush",
    "Royal Flush"
};

const char *menuOptions[] = {
    "Start Game",
    "Settings",
    "Exit"
};
const int menuSize = sizeof(menuOptions) / sizeof(menuOptions[0]);

const char *settingOptions[] = {
    "Maximum Player",
    "Inital Money",
    "Timeout Interval",
    "< Back >"
};
const int settingSize = sizeof(settingOptions) / sizeof(settingOptions[0]);

////////   Struct Variables   ////////

typedef struct 
{
    int StartingMoney;
    int MaxPlayer;
    int TimeoutInterval;
} Settings;
typedef struct
{
    int Number;
    char Face;
} Card;
typedef struct
{
    int CurrentMoney;
    int PlayerPosition;
    int SpecialRole;
    Card currentCard[];
} Person;

typedef struct
{
    int PoolMoney;
    int currentPlayerIndex;
    Card centralCard[];
} System;

////////   Global Variables   ////////

// Counting Variables
int i, j, k, n;
int previousDealer;

////////   Main Function   ////////

int main() {
    int TITLE_currentSelection, SETTING_currentSelection;
    bool TITLE_isSelected, SETTING_isSelected;

    setlocale(LC_ALL, "");

title:
    TITLE_isSelected = false;
    TITLE_currentSelection = 0;

    while (!TITLE_isSelected) {
        clearScreen();
        printTitle();
        
        printf("\n\n\n");

        printf("                                   -----------------\n");
        for (i = 0; i < menuSize; i++) {
            printf("                               ");
            if (i == TITLE_currentSelection) {
                printf("-> | %-15s |\n", menuOptions[i]);
            } else {
                printf("   | %-15s |\n", menuOptions[i]);
            }
        }
        printf("                                   -----------------\n");

        switch (detect_arrow_key())
        {
        case 0:
            TITLE_currentSelection--;
            if (TITLE_currentSelection < 0) {
                TITLE_currentSelection = menuSize - 1;
            }
            break;
        case 1:
            TITLE_currentSelection++;
            if (TITLE_currentSelection > menuSize - 1) {
                TITLE_currentSelection = 0;
            }
            break;
        case 2:
            TITLE_isSelected = true;
            break ; 
        default:
            break;
        }
    }

    switch (TITLE_currentSelection)
    {
    case 0:
        goto startGame;
        break;
    case 1:
        goto settings;
        break;
    case 2:
        goto exit;
        break;
    default:
        goto error;
        break;
    }

error:
    clearScreen();
    printf("Unexpected error occured while in Runtime state, aborting...");
    return 1;

exit:
    clearScreen();
    return 0;

settings:
    SETTING_isSelected = false;
    SETTING_currentSelection = 0;

    while (!SETTING_isSelected) {
        clearScreen();
        printSettings();

        printf("\n\n\n");

        printf("                           -------------------\n");
        for (i = 0; i < settingSize; i++) {
            printf("                       ");
            if (i == SETTING_currentSelection) {
                printf("-> | %-17s |\n", settingOptions[i]);
            } else {
                printf("   | %-17s |\n", settingOptions[i]);
            }
        }
        printf("                           -------------------\n");

        switch (detect_arrow_key())
        {
        case 0:
            SETTING_currentSelection--;
            if (SETTING_currentSelection < 0) {
                SETTING_currentSelection = settingSize - 1;
            }
            break;
        case 1:
            SETTING_currentSelection++;
            if (SETTING_currentSelection > settingSize - 1) {
                SETTING_currentSelection = 0;
            }
            break;
        case 2:
            SETTING_isSelected = true;
            break ; 
        default:
            goto error;
            break;
        }
    }

    switch (SETTING_currentSelection)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        goto title;
        break;
    default:
        break;
    }

startGame:
    clearScreen();
    printTitle();

    printCard(5, (int[]){2, 3, 4, 5, 6}, (char[]){'S', 'H', 'D', 'C', 'S'});
    printCard(4, (int[]){7, 8, 9, 10}, (char[]){'H', 'D', 'C', 'S'});
    printCard(3, (int[]){1, 11, 12}, (char[]){'D', 'C', 'S'});
    printCard(2, (int[]){13, 1}, (char[]){'C', 'S'});
    printCard(1, (int[]){2}, (char[]){'X'});

    getch();
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

int is_key_pressed(char target) {
    char ch = getch();

    return toupper(ch) == toupper(target);
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
        "              __| |____________________________________________________| |__\n"
        "              __   ____________________________________________________   __\n"
        "                | |                                                    | |  \n"
        "                | | ____       _               _   _ _       _     _   | |  \n"
        "                | ||  _ \\ ___ | | _____ _ __  | \\ | (_) __ _| |__ | |_ | |  \n"
        "                | || |_) / _ \\| |/ / _ \\ '__| |  \\| | |/ _` | '_ \\| __|| |  \n"
        "                | ||  __/ (_) |   <  __/ |    | |\\  | | (_| | | | | |_ | |  \n"
        "                | ||_|   \\___/|_|\\_\\___|_|    |_| \\_|_|\\__, |_| |_|\\__|| |  \n"
        "                | |                                    |___/           | |  \n"
        "              __| |____________________________________________________| |__\n"
        "              __   ____________________________________________________   __\n"
        "                | |                                                    | |  \n"
    );
}

void printSettings() {
    printf(
        "              __| |______________________________________| |__\n"
        "              __   ______________________________________   __\n"
        "                | |                                      | |  \n"
        "                | | ____       _   _   _                 | |  \n"
        "                | |/ ___|  ___| |_| |_(_)_ __   __ _ ___ | |  \n"
        "                | |\\___ \\ / _ \\ __| __| | '_ \\ / _` / __|| |  \n"
        "                | | ___) |  __/ |_| |_| | | | | (_| \\__ \\| |  \n"
        "                | ||____/ \\___|\\__|\\__|_|_| |_|\\__, |___/| |  \n"
        "                | |                            |___/     | |  \n"
        "              __| |______________________________________| |__\n"
        "              __   ______________________________________   __\n"
        "                | |                                      | |  \n"
    );
}

/*

┌─────────────┐    
│X            │    
│             │    
│             │    
│             │    
│      X      │    
│             │    
│             │    
│             │    
│            X│    
└─────────────┘

*/

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
        printf("Card character not found, (S [Spades], H [Hearts], D [Diamonds], C [Clover], X [Conceal]) expected.");
        return;
    }
}