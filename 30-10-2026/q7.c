#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void uniform(char *str, int len)
{
    int i;
    FILE *fp;

    fp = fopen(str, "w");
    // Generate len random double values in [0, 1)
    for (i = 0; i < len; i++)
    {
        fprintf(fp, "%lf\n", (double)rand() / RAND_MAX);
    }
    fclose(fp);
}

void uniformVector1To100(int n)
{
    double x;

    // Generate n random numbers using uniform() function
    uniform("vector.dat", n);

    FILE *fp = fopen("vector.dat", "r");

    printf("Vector elements (from 1 to 100):\n");
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%lf", &x);

        // Scale x to an integer from 1 to 100 inclusive
        int val = 1 + (int)(x * 100);

        // Guard against the rare edge case where x == 1.0 (rand() == RAND_MAX)
        if (val > 100)
            val = 100;

        printf("%d ", val);
    }
    printf("\n");

    fclose(fp);
}

int main()
{
    srand(time(NULL));

    int n;
    printf("Enter length of vector (n): ");
    scanf("%d", &n);

    uniformVector1To100(n);

    return 0;
}

