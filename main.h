#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

void read_command(char *command, int is_interactive, int *exit_flag);
void tokenize(char *command, char *tokens[], const char *delim);
void handle_cd(char *directory, char *prev_dir, char *curr_dir);
int handle_env(void);
void parse_command(char *args[]);
int _strcmp(const char *s1, const char *s2);

#endif
