// Integer numbers are read from the keyboard. The input ends when zero is entered. 
// Store these numbers as floating-point values in normalized form, 
// separating them with spaces.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void normalize(int* numbers, int count, char* result) {
    for (int i = 0; i < count; i++) {
        float normalizedNum = (float)numbers[i] / 100.0;
        sprintf(result + strlen(result), "%.2f    ", normalizedNum);
    }
}

int* readNumbers(int* count) {
    int* numbers = NULL;
    int capacity = 0;
    int num;
    do {
        printf("Enter an integer (0 - exit): ");
        scanf("%d", &num);

        if (num != 0) {
            if (*count >= capacity) {
                capacity += 5;
                numbers = realloc(numbers, capacity * sizeof(int));
            }
            numbers[*count] = num;
            (*count)++;
        }
    } while (num != 0);
    
    return numbers;
}

int main() {
    int count = 0;
    int* numbers = readNumbers(&count);
    char output[1000] = "";
    normalize(numbers, count, output);
    printf("Normalized numbers: %s\n", output);
    free(numbers);
    return 0;
}