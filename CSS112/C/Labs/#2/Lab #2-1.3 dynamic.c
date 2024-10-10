#include <stdio.h>
#include <math.h>
#include "tinyexpr.h"

//////////////// FUNCTION f(x) ///////////////////
// We'll use a global expression string that the user can input
const char *expr_str;

// Function wrapper for tinyexpr
float f(float x) {
    te_variable vars[] = {{"x", &x}};
    te_expr *expr = te_compile(expr_str, vars, 1, 0);

    if (!expr) {
        printf("Error: Invalid expression\n");
        return 0;
    }

    float result = te_eval(expr);
    te_free(expr);
    return result;
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
    char expression[100];

    // Get the user-defined mathematical expression
    printf("Enter a mathematical expression in terms of x (e.g., x*x, sin(x), etc.): ");
    scanf("%s", expression);
    expr_str = expression;  // Store the expression string globally

    printf("Enter a,b : ");
    scanf("%f,%f", &a, &b);

    printf("Enter n : ");
    scanf("%d", &n);

    result1 = tri_integrate(a, b, n);
    result2 = simp_integrate(a, b, n);

    printf("======================\n");
    printf("Trapezoid : %.6f\n", result1);
    printf("Simpson   : %.6f\n", result2);
    printf("======================\n");

    return 0;
}