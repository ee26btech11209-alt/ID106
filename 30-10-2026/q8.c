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

void processVector(int n)
{
    double x;

    // 1. Generate n random numbers
    uniform("vector.dat", n);

    // 2. Read file contents into an array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    FILE *fp = fopen("vector.dat", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%lf", &x);
        int val = 1 + (int)(x * 100);
        if (val > 100)
            val = 100;
        arr[i] = val;
    }
    fclose(fp);

    // 3. Print the original random vector
    printf("Original random vector:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // 4. Use a pointer to find the minimum value
    int *min_ptr = &arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < *min_ptr)
        {
            min_ptr = &arr[i]; // Point to the new minimum element
        }
    }

    printf("Minimum value found: %d\n\n", *min_ptr);

    // 5. Set the minimum value to 0 using the pointer
    *min_ptr = 0;

    // 6. Print the updated vector
    printf("Updated vector (minimum value set to 0):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main()
{
    srand(time(NULL));

    int n;
    printf("Enter length of vector (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    processVector(n);

    return 0;
}

