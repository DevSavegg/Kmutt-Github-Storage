#include <stdio.h>

int expo(int base_x, int exp_n) {
    //printf("x: %d, n: %d\n", base_x, exp_n);
    if (exp_n == 0) {
        return 1;
    } else {
        return base_x * expo(base_x, exp_n - 1);
    }
}

int main() {
    int x, n, res;

    printf("Input x,n : ");
    scanf("%d,%d", &x, &n);

    res = expo(x, n);

    printf("The solution of %d power %d is : %d", x, n, res);

    return 0;
}