//code by nikhil
// date 14-10-2026:
#include <stdio.h>

// Custom implementation of strcat
char *my_strcat(char *dest, const char *src) {
    char *ptr = dest;

    // Move ptr to the end of the destination string
    while (*ptr != '\0') {
        ptr++;
    }

    // Copy characters from src to dest
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }

    // Add null terminator at the end
    *ptr = '\0';

    return dest;
}

int main() {
    char dest[50] = "Hello ";
    char src[] = "World!";

    my_strcat(dest, src);

    printf("Concatenated string: %s\n", dest);

    return 0;
}

