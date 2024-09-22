#include <stdio.h>

int main() {
    char nameArr[100][999];
    char searchChar;
    
    int foundNameIndex[100];
    int i, j, count = 0, countIndex = 0;

    for (i = 0;;i++) {
        printf("Input name-surname %3d: ", count + 1);
        fgets(nameArr[i], sizeof(nameArr[i]), stdin);
        
        if (nameArr[i][0] == '*') {
            break;
        }

        count++;
    }
    printf("===========================\n");

    printf("Input search char: ");
    scanf("%c", &searchChar);

    if (searchChar > 90) {
        searchChar = searchChar - 32;
    }

    for (i = 0; i < count; i++) {
        if (searchChar == nameArr[i][0] || searchChar == (nameArr[i][0] - 32)) {
            printf("Name %2d: %s", countIndex + 1, nameArr[i]);
            countIndex++;
        }
    }

    return 0;
}