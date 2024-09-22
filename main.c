#include "main.h"

int main() {
    int exit_flag = 0;
    char command[1000];
    char *tokens[100];
    const char *delim = " ";

    while (!exit_flag) {
        read_command(command);

        if (strcmp(command, "exit") == 0) {
            exit_flag = 1;
        }

        tokenize(command, tokens, delim);
    }

    return 0;
}