#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

void read_command(char *command);
void tokenize(char *command, char *tokens[], const char *delim);
void handle_cd(char *directory, char *prev_dir, char *curr_dir);
int handle_env(void);

#endif
