// Given a text file, find the longest word among the words that start with the letter "a". 
// If no such words exist, report that. 
// Write the words that start with the letter "a" to another file.


#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

struct Word {
    char text[MAX_WORD_LENGTH];
    int length;
};

// Function to find the longest word starting with 'a' in a file
struct Word findLongestWordStartingWithA(FILE* file) {
    struct Word longestWord;
    struct Word currentWord;

    longestWord.length = 0;

    while (fscanf(file, "%s", currentWord.text) == 1) {
        currentWord.length = strlen(currentWord.text);

        // Check if the word starts with 'a' and if its length is greater than the current longest word.
        if (currentWord.text[0] == 'a' && currentWord.length > longestWord.length) {
            longestWord = currentWord;
        }
    }

    return longestWord;
}

// Function to write words starting with 'a' to a file
void writeWordsStartingWithAToFile(FILE* sourceFile, FILE* targetFile) {
    struct Word currentWord;

    while (fscanf(sourceFile, "%s", currentWord.text) == 1) {
        currentWord.length = strlen(currentWord.text);

        // Check if the word starts with 'a' and write it to the target file.
        if (currentWord.text[0] == 'a') {
            fprintf(targetFile, "%s\n", currentWord.text);
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    struct Word longestWord = findLongestWordStartingWithA(inputFile);

    if (longestWord.length == 0) {
        printf("No words starting with 'a' were found in the input file.\n");
    } else {
        printf("The longest word starting with 'a': %s\n", longestWord.text);
    }

    fclose(inputFile);

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        return 1;
    }

    FILE* inputFileForWriting = fopen("input.txt", "r");
    if (inputFileForWriting == NULL) {
        printf("Failed to reopen the input file.\n");
        return 1;
    }

    writeWordsStartingWithAToFile(inputFileForWriting, outputFile);

    fclose(inputFileForWriting);
    fclose(outputFile);

    return 0;
}
