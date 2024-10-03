#include <stdio.h>

int str_len(char input[]) {
    int n = 0;
    char *inp_pt = &input[0];
    for (;*inp_pt != '\n'; inp_pt++) {n++;}
    return n;
}

int main() {
    char input[1000], sub_string[1000];
    char *input_pt, *sub_string_pt;

    int input_len, sub_string_len;
    int i,j,k,m,n,count;
    int FLAG_IS_FOUND = 0;

    printf("*** Input DATA ***\n");
    printf("Sentence : ");
    fgets(input, sizeof(input), stdin);

    printf("=====================\n");
    printf("Search word : ");
    fgets(sub_string, sizeof(sub_string), stdin);
    printf("=====================\n");

    input_len = str_len(input);
    sub_string_len = str_len(sub_string);

    input[input_len] = '\0';
    sub_string[sub_string_len] = '\0';

    for (i = 0; i < input_len; i++) {
        input_pt = &input[i];
        sub_string_pt = &sub_string[0];

        if (*input_pt != *sub_string_pt) {
            continue;
        }

        //printf("\n- %c, %c, %d -\n", *input_pt, *sub_string_pt, sub_string_len);

        count = 1;

        for (;;) {
            if (count == sub_string_len) {
                FLAG_IS_FOUND = 1;
                break;
            }

            input_pt++;
            sub_string_pt++;

            if (*input_pt == *sub_string_pt) {
                count++;
                continue;
            } else {
                break;
            }
        }

        if (FLAG_IS_FOUND == 1) {
            break;
        }
    }

    if (FLAG_IS_FOUND == 1) {
        printf("The word %s is in sentence.", sub_string);
    } else {
        printf("This word not found.");
    }

    return 0;
}