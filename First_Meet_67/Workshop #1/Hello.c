#include <stdio.h>

int main() {
    char* name;

    printf("What's your name?\n");
    scanf("%s", name);

    printf("Hello, %s :)", name);

    return 0;
}