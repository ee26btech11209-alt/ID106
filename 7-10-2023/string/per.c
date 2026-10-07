#include <stdio.h>

int main() {
    char alphabet[] = {'a', 'b', 'c'};
    int total_strings = 0;
    int matching_strings = 0;

    // Loop through all possible 5-character combinations using 5 nested loops
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    for (int m = 0; m < 3; m++) {
                        
                        total_strings++;

                        // Check if at least one pair of adjacent characters is equal
                        if (i == j || j == k || k == l || l == m) {
                            matching_strings++;
                        }
                    }
                }
            }
        }
    }

    printf("Total strings of length 5: %d\n", total_strings);
    printf("Strings with at least one consecutive pair: %d\n", matching_strings);

    return 0;
}

