// Convert numbers to thai words

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main() {
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

    // Input Variables
    char input[100];
    char integer[50], decimal[50];

    // Other Variables
    int i, j, dot_position = -1, decimal_shift = 0;
    int integer_cache = 0, decimal_cache = 0;

    size_t integer_count = 0, decimal_count = 0;
    wchar_t suffixCache[10], numberCache[99];

    // Set the locale to support UTF-8
    setlocale(LC_ALL, "");

    // Accept the input
    printf("Enter number : ");
    scanf("%s", input);

    // Find decimal point position
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '.') {
            dot_position = i;
            break;
        }
    }

    // If decimal number exist, separate them
    if (dot_position != -1) {
        strncpy(integer, input, dot_position);
        integer[dot_position] = '\0';

        strncpy(decimal, input + dot_position + 1, 2);
        decimal[2] = '\0';
    } else {
        strncpy(integer, input, sizeof(integer));
        integer[strlen(input) + 1] = '\0';
    }

    // Get Integer and Decimal length
    integer_count = strlen(integer);
    decimal_count = strlen(decimal);

    // Print full integer number
    for (i = 0; i < integer_count; i++) {
        integer_cache = integer[i] - 48;

        if (integer_cache == 0 && i != 0) {
            continue;
        }

        if (integer_count - i - 1 > 7) {
            wcscpy(suffixCache, bahtSuffix[integer_count - 7 - i]);
        } else {
            wcscpy(suffixCache, bahtSuffix[integer_count - i - 1]);
        }

        if (integer_count - i - 1 == 1 && integer_cache == 2) {
            wcscpy(numberCache, uniqueWords[0]);
        } else if (integer_count - i - 1 == 1 && integer_cache == 1) {
            wcscpy(numberCache, L"");
        } else if (integer_count - i - 1 == 0 && integer_cache == 1) {
            wcscpy(numberCache, uniqueWords[1]);
        } else if (integer_count - i - 1 == 0 && integer_cache == 0) {
            wcscpy(numberCache, L"");
        } else {
            wcscpy(numberCache, thaiNumber[integer_cache]);
        }

        wprintf(L"%ls%ls", numberCache, suffixCache);
    }
    wprintf(L"บาท");

    // Print decimal number
    if (dot_position == -1) {
        wprintf(L"ถ้วน");
    } else {
        for (i = 0; i < decimal_count; i++) {
            decimal_cache = decimal[i] - 48;

            wcscpy(suffixCache, bahtSuffix[decimal_count - i - 1]);

            if (decimal_count - i - 1 == 1 && decimal_cache == 2) {
                wcscpy(numberCache, uniqueWords[0]);
            } else if (decimal_count - i - 1 == 0 && decimal_cache == 1) {
                wcscpy(numberCache, uniqueWords[1]);
            } else if (decimal_count - i - 1 == 0 && decimal_cache == 0) {
                wcscpy(numberCache, L"");
            } else {
                wcscpy(numberCache, thaiNumber[decimal_cache]);
            }

            wprintf(L"%ls%ls", numberCache, suffixCache);
        }
        wprintf(L"สตางค์");
    }

    return 0;
}