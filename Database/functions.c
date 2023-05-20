#include "functions.h"

char *input_string(char *string) {
    char input;
    for (int i = 0; (input = getchar()) != '\n'; ++i) {
        string = (char *) realloc(string, sizeof(char) * (i + 2));
        string[i] = input;
        string[i + 1] = '\0';
    }
    return string;
}
