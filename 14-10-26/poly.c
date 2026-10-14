//code by nikhil
//date 14-10-2026#include <stdio.h>
#include <stdio.h>

#define MAX_DEGREE 20

// Define structure using typedef to store degree and coefficients[span_1](start_span)[span_1](end_span)
typedef struct {
    int n;                          // Degree of polynomial (n <= 20)[span_2](start_span)[span_2](end_span)
    double coeff[MAX_DEGREE + 1];   // Coefficients a0, a1, ..., an[span_3](start_span)[span_3](end_span)
} Polynomial;

// Function to evaluate polynomial P(x) using Horner's Method with a pointer
double evaluatePolynomial(const Polynomial *p, double x) {
    double result = p->coeff[p->n];
    for (int i = p->n - 1; i >= 0; i--) {
        result = result * x + p->coeff[i];
    }
    return result;
}

int main() {
    Polynomial p;
    Polynomial *ptr = &p; // Pointer to the polynomial structure

    // Get degree from user using pointer notation
    printf("Enter the degree of the polynomial (n <= 20): ");
    scanf("%d", &ptr->n);

    if (ptr->n < 0 || ptr->n > MAX_DEGREE) {
        printf("Error: Degree must be between 0 and %d.\n", MAX_DEGREE);
        return 1;
    }

    // Get coefficients from user using pointer notation
    printf("Enter the coefficients from a0 to an:\n");
    for (int i = 0; i <= ptr->n; i++) {
        printf("  a%d = ", i);
        scanf("%lf", &ptr->coeff[i]);
    }

    // Get value of x from user
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate and display the result by passing the pointer
    double value = evaluatePolynomial(ptr, x);
    printf("\nResult: P(%.2f) = %.2f\n", x, value);

    return 0;
}

