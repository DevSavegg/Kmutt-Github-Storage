#include <stdio.h>

char months[13][3] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void addPasswd(char* passArr, char* phone, char* birth) {
    // Number Section
    int slash_count = 0;
    int n = 0;

    for (int i = 0; birth[i] != '\n'; i++) {
        if ((char)(birth[i]) == '/') {
            slash_count++;
            if (slash_count == 1) {
                int month = (int)(((float)(birth[i + 1]) - 48) * 10 + ((float)(birth[i + 2]) - 48));

                for (int j = 0; j < 3; j++) {
                    passArr[n] = months[month][j];
                    n++;
                }
                
                i += 2;
            } else {
                continue;
            }
        } else {
            passArr[n] = (char)(birth[i]);
            n++;
            //printf("pass: %c, n : %d, input : %c, convert : %c\n", passArr[n - 1], n, birth[i], (int)(birth[i]));
        }
    }

    // Phone Section
    int PHONE_LEN;
    for (PHONE_LEN = 0; phone[PHONE_LEN] != '\n'; PHONE_LEN++) {}

    for (int i = PHONE_LEN - 4; i < PHONE_LEN; i++) {
        passArr[n] = (char)(phone[i]);
        n++;
    }
}

int main() {
    char phone_number[100], password[100], birth[100];

    printf("Input DD/MM/YYYY : ");
    fgets(birth, sizeof(birth), stdin);

    printf("Input Tel. no. : ");
    fgets(phone_number, sizeof(phone_number), stdin);

    addPasswd(password, phone_number, birth);

    printf("%s", password);

    return 0;
}