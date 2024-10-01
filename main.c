#include "main.h"

int main() {
    int exit_flag = 0;
    char *command = NULL;
    char *tokens[100];
    const char *delim = " ";
    char prev_dir[100] = "";
    char curr_dir[100];
    size_t len = 100;

    getcwd(curr_dir, sizeof(curr_dir));
    int is_interactive = isatty(STDIN_FILENO);

    while (!exit_flag) {
        if (is_interactive) {
            printf("shellv2: ");
            fflush(stdout);
        }

        if (getline(&command, &len, stdin) == -1) {
            if (!is_interactive) {
                break;
            }
            continue;
        }

	    command[_strcspn(command, "\n")] = 0;
        tokenize(command, tokens, delim);

        if (_strcmp(tokens[0], "exit") == 0) {
            exit_flag = 1;
        } else if (_strcmp(tokens[0], "cd") == 0) {
            handle_cd(tokens[1], prev_dir, curr_dir);
        } else if (_strcmp(tokens[0], "env") == 0) {
            handle_env();
        } else {
            parse_command(tokens);
        }

    }

    return 0;
}