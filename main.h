#ifndef MAIN_H_
#define MAIN_H_

#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void read_command(char *command, int is_interactive, int *exit_flag);
void tokenize(char *command, char *tokens[], const char *delim);
void handle_cd(char *directory, char *prev_dir, char *curr_dir);
int handle_env(void);
void parse_command(char *args[]);
int _strcmp(const char *s1, const char *s2);
size_t _strcspn(const char *s, const char *reject);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);
char *find_executable(const char *cmd);
void print_cwd(void);
void redirect_output(char *filename, char *command);
void redirect_input(char *filename, char *command);
void handle_redirection(char *token, char *command);
char *get_custom_env(const char *var);
char *_strdup(const char *s);
char *_strchr(const char *s, int c);

#endif
