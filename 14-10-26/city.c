#include <stdio.h>

// Define the City structure
struct City {
    char name[50];
    char country[50];
    long population;
    float latitude;
    float longitude;
};

int main() {
    struct City c;

    // Reading inputs from the user
    printf("Enter city name: ");
    scanf(" %[^\n]", c.name); // Reads string with spaces

    printf("Enter country name: ");
    scanf(" %[^\n]", c.country);

    printf("Enter population: ");
    scanf("%ld", &c.population);

    printf("Enter latitude: ");
    scanf("%f", &c.latitude);

    printf("Enter longitude: ");
    scanf("%f", &c.longitude);

    // Displaying the details
    printf("\n--- City Details ---\n");
    printf("City Name: %s\n", c.name);
    printf("Country: %s\n", c.country);
    printf("Population: %ld\n", c.population);
    printf("Latitude: %.4f\n", c.latitude);
    printf("Longitude: %.4f\n", c.longitude);

    return 0;
}

