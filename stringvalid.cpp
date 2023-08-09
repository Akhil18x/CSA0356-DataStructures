#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Include ctype.h for isalpha and isdigit functions

bool isValidString(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!(isalpha(str[i]) || isdigit(str[i]))) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%99s", input); // Limit the input size to prevent buffer overflow
    
    if (isValidString(input)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }
    
    return 0;
}