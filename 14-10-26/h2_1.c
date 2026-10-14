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
    // Large enough arrays to hold user input
    char dest[100];
    char src[100];

    // Get destination string from user
    printf("Enter the destination string: ");
    if (fgets(dest, sizeof(dest), stdin) != NULL) {
        // Remove the trailing newline character added by fgets, if present
        int i = 0;
        while (dest[i] != '\0') {
            if (dest[i] == '\n') {
                dest[i] = '\0';
                break;
            }
            i++;
        }
    }

    // Get source string from user
    printf("Enter the source string to append: ");
    if (fgets(src, sizeof(src), stdin) != NULL) {
        // Remove the trailing newline character added by fgets, if present
        int i = 0;
        while (src[i] != '\0') {
            if (src[i] == '\n') {
                src[i] = '\0';
                break;
            }
            i++;
        }
    }

    // Perform concatenation
    my_strcat(dest, src);

    // Display the result
    printf("Concatenated string: %s\n", dest);

    return 0;
}

