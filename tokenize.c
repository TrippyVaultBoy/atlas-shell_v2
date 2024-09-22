#include "main.h"

void tokenize(char *command, char *tokens[], const char *delim) {
    int i = 0;
    tokens[i] = strtok(command, delim);
    printf("%s \n", tokens[i]);

    while(tokens[i] != NULL) {
        tokens[++i] = strtok(NULL, delim);
        printf("%s \n", tokens[i]);
    }
}