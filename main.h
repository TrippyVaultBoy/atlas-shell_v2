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
char *heredoc(char *delimiter);
char *get_custom_env(const char *var);
char *_strdup(const char *s);
char *_strchr(const char *s, int c);
char *_strstr(const char *haystack, const char *needle);
void setenv_builtin(char *var, char *value);
void unsetenv_builtin(char *var);
void execute_command(char **tokens);
int and_operator(char **commands);
int or_operator(char **commands);
int single_command(char **commands);
void execute_pipe(char **commands);
void next_command(char **commands);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, char *src);


#endif
