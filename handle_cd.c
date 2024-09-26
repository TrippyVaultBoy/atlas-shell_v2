#include "main.h"

void handle_cd(char *directory, char *prev_dir, char *curr_dir) {
    char *home_dir;
    
    if (directory == NULL) {
        home_dir = getenv("HOME");
        if (chdir(home_dir) != 0) {
            printf("chdir home error\n");
        }
        setenv("PWD", home_dir, 1);
    } else if (strcmp(directory, "-") == 0) {
        if (chdir(prev_dir) != 0) {
            printf("chdir - error\n");
        }
        setenv("PWD", prev_dir, 1);
    } else {
        if (chdir(directory) != 0) {
            printf("chdir error\n");
        }
        setenv("PWD", directory, 1);
    }

    prev_dir = curr_dir;
    getcwd(curr_dir, sizeof(curr_dir));
}