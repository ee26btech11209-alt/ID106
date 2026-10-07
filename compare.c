#include <stdio.h>

int main() {
    int x = 12; // Binary: 1100
    int y = 10; // Binary: 1010

    // 1. Bitwise AND (&)
    // Compares each bit position individually:
    //   1100 (12)
    // & 1010 (10)
    // ----------
    //   1000 (8 in decimal)
    int bitwise_result = x & y;

    // 2. Logical AND (&&)
    // Checks if both variables are non-zero (true):
    // x (12) is true, y (10) is true -> True (1)
    int logical_result = x && y;

    printf("x = %d (binary 1100), y = %d (binary 1010)\n\n", x, y);
    printf("Bitwise AND (x & y)  = %d  [Bit comparison -> 1000]\n", bitwise_result);
    printf("Logical AND (x && y) = %d  [Boolean check  -> True]\n", logical_result);

    return 0;
}

