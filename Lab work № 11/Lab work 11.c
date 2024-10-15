//    There is information about students in a group: 
//    full name, results of the last exam session. 
//    It is required to obtain a list of students with their average score from the session, 
//    sorted either lexicographically or by non-increasing average score, as specified by the user.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
typedef struct {
    char name[100];      // Full name of the student
    float averageScore;  // Average score
} Student;

// Universal sorting function
void universalSort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
    // Implementation of a simple bubble sort for demonstration
    for (size_t i = 0; i < nitems - 1; i++) {
        for (size_t j = 0; j < nitems - i - 1; j++) {
            void* a = (char*)base + j * size;
            void* b = (char*)base + (j + 1) * size;

            if (compar(a, b) > 0) {
                // Swap
                char temp[size];
                memcpy(temp, a, size);
                memcpy(a, b, size);
                memcpy(b, temp, size);
            }
        }
    }
}

// Comparison function for sorting by name
int compareByName(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;
    return strcmp(studentA->name, studentB->name);
}

// Comparison function for sorting by average score
int compareByAverageScore(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;
    if (studentA->averageScore < studentB->averageScore) return 1; // Sort in descending order
    if (studentA->averageScore > studentB->averageScore) return -1;
    return 0;
}

// Main function
int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    Student* students = malloc(n * sizeof(Student));

    // Input student data
    for (int i = 0; i < n; i++) {
        printf("Enter the full name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name); // Read string with spaces
        printf("Enter the average score of student %d: ", i + 1);
        scanf("%f", &students[i].averageScore);
    }

    int choice;
    printf("Sort by:\n1. Name\n2. Average score\n");
    scanf("%d", &choice);
    
    // Sort based on user choice
    if (choice == 1) {
        universalSort(students, n, sizeof(Student), compareByName);
    } else if (choice == 2) {
        universalSort(students, n, sizeof(Student), compareByAverageScore);
    } else {
        printf("Invalid choice!\n");
        free(students);
        return 1;
    }

    // Output sorted students
    printf("\nSorted students:\n");
    for (int i = 0; i < n; i++) {
        printf("Full name: %s, Average score: %.2f\n", students[i].name, students[i].averageScore);
    }

    free(students);
    return 0;
}
