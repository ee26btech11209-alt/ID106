#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number following a Binomial Distribution B(n, p)
// Here, n = 100 (so the max value is 100) and p = 0.5
int generate_binomial(int n, double p) {
    int successes = 0;
    for (int i = 0; i < n; i++) {
        // Generate a random float between 0.0 and 1.0
        double r = (double)rand() / RAND_MAX;
        if (r < p) {
            successes++;
        }
    }
    return successes;
}

// Function to sort the array using the algorithm provided in the image (Bubble Sort)
void fun(int A[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        for (int j = 0; j <= n - i - 2; j++) {
            if (A[j] > A[j + 1]) {
                // Swap A[j] and A[j + 1]
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    int n = 30;
    int A[30];

    // Populate array A with random numbers (Max value 100) using Binomial Distribution
    for (int i = 0; i < n; i++) {
        A[i] = generate_binomial(100, 0.5);
    }

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");

    // Sort the array using the provided algorithm
    fun(A, n);

    printf("Output Array (Sorted Matrix/Vector):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

