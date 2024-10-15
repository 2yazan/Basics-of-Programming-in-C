// Find the longest common word between two given texts.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

void readWordsFromFile(FILE *file, char words[][MAX_WORD_LENGTH], int *wordCount) {
    char line[1000];
    
    *wordCount = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \n");
        
        while (token != NULL) {
            strcpy(words[*wordCount], token);
            (*wordCount)++;
            
            token = strtok(NULL, " \n");
        }
    }
}

void findLongestCommonWord(char words1[][MAX_WORD_LENGTH], int wordCount1, char words2[][MAX_WORD_LENGTH], int wordCount2, char longestCommonWord[]) {
    for (int i = 0; i < wordCount1; i++) {
        for (int j = 0; j < wordCount2; j++) {
            if (strcmp(words1[i], words2[j]) == 0 && strlen(words1[i]) > strlen(longestCommonWord)) {
                strcpy(longestCommonWord, words1[i]);
            }
        }
    }
}

int main() {
    FILE *file1, *file2;

    file1 = fopen("text1.txt", "r");
    if (file1 == NULL) {
        printf("Failed to open the first text file.\n");
        return 1;
    }

    file2 = fopen("text2.txt", "r");
    if (file2 == NULL) {
        printf("Failed to open the second text file.\n");
        return 1;
    }

    char words1[100][MAX_WORD_LENGTH];
    char words2[100][MAX_WORD_LENGTH];
    int wordCount1, wordCount2;
    char longestCommonWord[MAX_WORD_LENGTH] = "";
    readWordsFromFile(file1, words1, &wordCount1);
    readWordsFromFile(file2, words2, &wordCount2);
    findLongestCommonWord(words1, wordCount1, words2, wordCount2, longestCommonWord);
    printf("The longest common word: %s\n", longestCommonWord);

    fclose(file1);
    fclose(file2);
    return 0;
}