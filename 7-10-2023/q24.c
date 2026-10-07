#include <stdio.h>

// Boolean function X(p, q, r): returns 1 if at least two inputs are 1
int X(int p, int q, int r) {
    return (p & q) | (q & r) | (r & p);
}

int main() {
    int check_A = 1, check_B = 1, check_C = 1, check_D = 1;

    // Loop through all 32 combinations of a, b, c, d, e (5-bit integer)
    for (int i = 0; i < 32; i++) {
        int a = (i >> 4) & 1;
        int b = (i >> 3) & 1;
        int c = (i >> 2) & 1;
        int d = (i >> 1) & 1;
        int e = i & 1;

        // Statement A: X(a, b, X(c, d, e)) == X(X(a, b, c), d, e)
        if (X(a, b, X(c, d, e)) != X(X(a, b, c), d, e)) {
            check_A = 0;
        }

        // Statement B: X(a, b, X(a, b, c)) == X(a, b, c)
        if (X(a, b, X(a, b, c)) != X(a, b, c)) {
            check_B = 0;
        }

        // Statement C: X(a, b, X(a, c, d)) == (X(a, b, a) & X(c, d, c))
        if (X(a, b, X(a, c, d)) != (X(a, b, a) & X(c, d, c))) {
            check_C = 0;
        }

        // Statement D: X(a, b, c) == X(a, X(a, b, c), X(a, c, c))
        if (X(a, b, c) != X(a, X(a, b, c), X(a, c, c))) {
            check_D = 0;
        }
    }

    // Results
    printf("Option (A) is %s\n", check_A ? "CORRECT" : "INCORRECT");
    printf("Option (B) is %s\n", check_B ? "CORRECT" : "INCORRECT");
    printf("Option (C) is %s\n", check_C ? "CORRECT" : "INCORRECT");
    printf("Option (D) is %s\n", check_D ? "CORRECT" : "INCORRECT");

    return 0;
}

