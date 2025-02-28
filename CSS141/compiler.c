#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    
    return 0;
}

int x = 0;
int f() { return x; }
int g() { int x = 1; return f(); }

/**
 * x in the code is a static scoping because the binding of a variable is done at compile time, not when the function is called (runtime).
 * function f() is already bound to x = 0 at the first place it is defined.
 * No matter where the function is called, if the returned value is a static value that didn't change, it will always reference 
 * the value of x that was defined at the first place it was defined.
 */