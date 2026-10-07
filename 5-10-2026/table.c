#include <stdio.h>

int main() {
    int a, b, c, X;

    printf("a | b | c | X\n");
    printf("-----------\n");

    for (int i = 0; i < 8; i++) {
        // Extract individual bits using bitwise operations
        a = (i >> 2) & 1;
        b = (i >> 1) & 1;
        c = i & 1;

        // Bitwise logic: X = (a & b) | (b & c) | (c & a)
        X = (a & b) | (b & c) | (c & a);

        printf("%d | %d | %d | %d\n", a, b, c, X);
    }
set clipboard+=unnamedplus

    return 0;
}

