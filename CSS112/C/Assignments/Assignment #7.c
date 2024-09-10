// Convert numbers to thai words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void removeLeadingZeros(char* str) {
    int i = 0, j = 0;

    // Find the first non-zero character
    while (str[i] == '0') {
        i++;
    }

    // Shift the remaining characters to the left
    while (str[i] != '\0') {
        str[j++] = str[i++];
    }
    
    // Null terminate the resulting string
    str[j] = '\0';

    // If the string was full of zeros (e.g., "0000"), we set it to "0"
    if (j == 0) {
        str[0] = '0';
        str[1] = '\0';
    }
}

int main() {
    // Set the locale to support UTF-8
    setlocale(LC_ALL, "");

    // Currency Constant
    const wchar_t bahtSuffix[7][10] = {
        L"",
        L"สิบ",
        L"ร้อย",
        L"พัน",
        L"หมื่น",
        L"แสน",
        L"ล้าน"
    };
    const wchar_t thaiNumber[10][10] = {
        L"ศูนย์",
        L"หนื่ง",
        L"สอง",
        L"สาม",
        L"สี่",
        L"ห้า",
        L"หก",
        L"เจ็ด",
        L"แปด",
        L"เก้า"
    };
    const wchar_t uniqueWords[2][10] = {
        L"ยี่",
        L"เอ็ด"
    };

    //----------------------------------------//
    
    // Input Variables
    char inputNumber[200];

    // Seperated Variables
    char *rawIntegerNumber, *rawFloatNumber;

    // Counting/Checking Variables
    int i, j, n;
    int aboveMillion, repeatMillion;

    // Cache Variables
    int tempInteger;
    float tempFloat;

    int integerRange, floatRange;
    int suffixPosition;

    wchar_t tempSuffix[10], tempNumber[10];

    //----------------------------------------//

    // Accept Input
    printf("Input the number (200 characters limit): ");
    scanf("%s", &inputNumber);

    //----------------------------------------//

    // If both integer and float exist
    if (strchr(inputNumber, '.') != NULL) {
        // Seperate integer from float
        rawIntegerNumber = strtok(inputNumber, ".");
        rawFloatNumber = strtok(NULL, ".");
    } else {
        // If not the manually set integer number
        rawIntegerNumber = inputNumber;
    }

    //----------------------------------------//

    // If interger exists
    if (rawIntegerNumber != NULL) {
        // Reset variable's value
        tempInteger = 0;
        aboveMillion = 0;
        n = 0;

        // Remove leading zeros from integer (If exist. E.g., 00412)
        //removeLeadingZeros(rawIntegerNumber);

        // Find range for integer
        integerRange = strlen(rawIntegerNumber);

        repeatMillion = integerRange / 7;

        // For-Loop print through every number and its suffix
        for (i = 0; i < integerRange; i++) {
            tempInteger = (int)rawIntegerNumber[i] - 48;

            if (tempInteger != 0) {
                // Check if the number is above million
                if (integerRange - i > 7) {
                    aboveMillion = 1;
                } else {
                    aboveMillion = 0;
                }

                // Debug
                //printf("\n\n--%c %d--\n\n", rawIntegerNumber[i], i);

                // Copy suffix
                if (aboveMillion == 1) {
                    suffixPosition = (integerRange - (i)) % 7;
                } else {
                    suffixPosition = (integerRange - (i + 1)) % 7;
                }
                wcscpy(tempSuffix, bahtSuffix[suffixPosition]);

                // Copy number
                if (suffixPosition == 0 && tempInteger == 1 && integerRange != 1 && aboveMillion != 1) { // E.g., 21, 111, 41021 (end with 1)
                    wcscpy(tempNumber, uniqueWords[1]);
                } else if (suffixPosition == 0 && tempInteger == 0) { // E.g., 50, 120, 5910 (end with 0)
                    wcscpy(tempNumber, L"");
                } else if ((suffixPosition) == 1 && tempInteger == 2) { // E.g., 20, 520, 10420 (2nd position is 2)
                    wcscpy(tempNumber, uniqueWords[0]);
                } else if ((suffixPosition == 1) && tempInteger == 1) {// E.g., 10, 210, 18310 (2nd position is 1)
                    wcscpy(tempNumber, L"");
                } else {
                    wcscpy(tempNumber, thaiNumber[tempInteger]);
                }

                wprintf(L"%ls%ls", tempNumber, tempSuffix);

                if (i % 7 == 0 && integerRange > 7 && (int)rawIntegerNumber[i + 1] - 48 == 0) {
                    //printf("-%d-", i);
                    wprintf(L"ล้าน");
                }
            }
        }
    }

    return 0;
}