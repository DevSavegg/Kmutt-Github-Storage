#include <stdio.h>
#include <math.h>

//////////////// FUNCTION f(x) ///////////////////
float f(float x) {
    return expf(powf(x, 2));
}
//////////////////////////////////////////////////

float tri_integrate(float a, float b, int n) {
    float h = (b - a) / n;
    float sum = (f(a) + f(b)) / 2;

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);  // Directly add to sum without extra assignments
    }

    return sum * h;
}

float simp_integrate(float a, float b, int n) {
    // Ensure n is even
    if (n % 2 != 0) {
        printf("\n!!! n must be an even number in Simpson's rule. !!!\n\n");
        return 0;
    }

    float h = (b - a) / n;  // Step size
    float result = f(a) + f(b);
    
    // Combine even and odd sums in a single loop for fewer iterations
    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        result += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);  // Avoid if-else branching
    }

    return result * (h / 3.0);
}

int main() {
    float a, b;
    int n;
    float result1, result2;

    printf("Enter a,b : ");
    scanf("%f,%f", &a, &b);

    printf("Enter n : ");
    scanf("%d", &n);

    result1 = tri_integrate(a, b, n);
    result2 = simp_integrate(a, b, n);

    printf("======================\n");
    printf("Trapezoid : %.8f\n", result1);
    printf("Simpson   : %.8f\n", result2);
    printf("======================\n");

    return 0;
}