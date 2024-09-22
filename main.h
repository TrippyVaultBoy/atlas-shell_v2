#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <string.h>

void read_command();
void tokenize(char *command, char *tokens[], const char *delim);

#endif