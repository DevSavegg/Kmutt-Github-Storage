#include <stdio.h>

int f(int n) {
    if (n == 0) {
        return 1;
    } else if (n >= 1 && n <= 2) {
        return 2;
    } else {
        return f(n-1) + f(n-2);
    }
}

int main() {
    int n, res;

    printf("Input n : ");
    scanf("%d", &n);

    res = f(n);

    printf("Output f(%d) : %d", n, res);
}