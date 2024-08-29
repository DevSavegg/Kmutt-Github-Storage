#include <stdio.h>

float f(float x) {
    return (x * x) + 2;
}

float integrate(float a, float b, float n) {
    float h = (b - a) / n;
    
    float start = ((f(a) + f(b)) / 2);
    float sum = 0;

    sum = sum + start;

    for (int i = 1; i < n; i++) {
        sum = sum + f(a + (i * h));
    }

    sum = sum * h;

    return sum;
}

int main() {
    float a, b, n;
    float result;
    printf("Enter a,b : ");
    scanf("%f,%f", &a, &b);

    printf("Enter n : ");
    scanf("%f", &n);

    result = integrate(a, b, n);

    printf("======================\n");
    printf("%.6f", result);
}