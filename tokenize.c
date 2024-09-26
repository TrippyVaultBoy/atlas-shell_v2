#include "main.h"

void tokenize(char *command, char *tokens[], const char *delim) {
    int i = 0;
    tokens[i] = strtok(command, delim);

    while(tokens[i] != NULL) {
        tokens[++i] = strtok(NULL, delim);
    }

    tokens[i] = NULL;

    // for (int i = 0; tokens[i] != NULL; i++) {
    //     printf("%s ", tokens[i]);
    // }
    // printf("\n");
}