// Transform the string by replacing each digit with the corresponding 
// number of spaces (e.g., '0' with 0 spaces, '1' with 1 space, 
// '2' with 2 spaces, and so on).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Replaces each digit in the string with the corresponding number of spaces
char* replace(const char* str) {
    int size = strlen(str) * 9 + 1; // max possible size of the resulting string
    char* res = (char*)malloc(size); // resulting string
    memset(res, 0, size); // reset to zero
    char empty[11] = "         \0"; // string of spaces
    for (int i = 0, j = 0; i < strlen(str); i++)
        if (isdigit(str[i])) {
            strncat(res, empty, str[i] - '0'); // append the corresponding number of spaces to the end of the result string
            j += str[i] - '0';
        }
        else
            res[j++] = str[i]; // copy the character to the result string. If not a digit.
    return res;
}

// Reads, transforms, and outputs the string, replacing each digit with the corresponding number of spaces
void input() {
    printf("Enter a string (digits instead of spaces):\n");
    char buf[256];
    scanf("%s", buf);
    char* res = replace(buf);
    printf("%s", res);
    free(res);
}

int main() {
    input();
    return 0;
}
