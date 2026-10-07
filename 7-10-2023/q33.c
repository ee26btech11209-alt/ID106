#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number following a Binomial Distribution B(n, p)
// Here, n = 100 (max value) and p = 0.5
int get_binomial_random(int n, double p) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double r = (double)rand() / RAND_MAX;
        if (r < p) {
            count++;
        }
    }
    return count;
}

// Function given in the image (Bubble Sort algorithm)
void fun(int A[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        for (int j = 0; j <= n - i - 2; j++) {
            if (A[j] > A[j + 1]) {
                // Swap A[j] and A[j+1]
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 10; // Size of the array
    int A[10];

    // Initialize random seed
    srand(time(NULL));

    // Fill the array using Binomial Distribution B(100, 0.5)
    printf("Original Array (Binomial Distributed, max 100):\n");
    for (int i = 0; i < n; i++) {
        A[i] = get_binomial_random(100, 0.5);
        printf("%d ", A[i]);
    }
    printf("\n\n");

    // Pass the array into the function
    fun(A, n);

    // Output the sorted array
    printf("Output Array (Sorted):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

