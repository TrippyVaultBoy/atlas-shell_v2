#include "main.h"

void parse_command(char *args[]) {
    if (args[0] == NULL) {
        return;
    }

    pid_t pid = fork();

    if (pid == 0) {
        char path[1024] = "/bin/";
        strcat(path, args[0]);

        char *newenvp[] = { NULL };
        char *newargv[] = { path, NULL };

        if ((execve(path, newargv, newenvp)) == -1) {
            perror("execve error");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}