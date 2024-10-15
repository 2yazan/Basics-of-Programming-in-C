// Given a binary file of structures consisting of city names and their populations, 
// which is sorted in non-decreasing order of population, 
// transform the file so that the cities are sorted in non-increasing order of population.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char city[50];
    int population;
} City;

int compare(const void* a, const void* b) {
    City* cityA = (City*) a;
    City* cityB = (City*) b;
    
    return cityB->population - cityA->population;
}

int main() {
    City cities[] = {
        {"Phoenix", 1660272},
        {"Philadelphia", 1580863},
        {"San Antonio", 1532233},
        {"San Diego", 1425976},
        {"Dallas", 1345047},
        {"San Jose", 1030119},
        {"New York", 8537673},
        {"Los Angeles", 3971883},
        {"Chicago", 2695598},
        {"Houston", 2325502}
    };
    int numCities = sizeof(cities) / sizeof(cities[0]);

    // Write the city data to cities.bin
    FILE *file = fopen("cities.bin", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fwrite(cities, sizeof(City), numCities, file);

    fclose(file);

    // Read the city data from cities.bin, sort, and write to output.bin
    file = fopen("cities.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    City readCities[1000];
    int readNumCities = fread(readCities, sizeof(City), 1000, file);

    fclose(file);

    qsort(readCities, readNumCities, sizeof(City), compare);

    file = fopen("output.bin", "wb");
    if (file == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    fwrite(readCities, sizeof(City), readNumCities, file);

    fclose(file);

    printf("File successfully converted.\n");

    return 0;
}
