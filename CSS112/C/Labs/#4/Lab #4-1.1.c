#include <stdio.h>

int main() {
    char name[100], surname[100];
    int i, strLen;

    printf("Input name-surname: ");
    scanf("%s %s", &name, &surname);

    printf("Output name-surname: %s %s", surname, name);

    return 0;
}