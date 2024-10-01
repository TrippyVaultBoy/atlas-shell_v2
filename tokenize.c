#include "main.h"

/**
 * tokenize - func to convert commands into tokens
 *
 * @command: command thats being input
 * @tokens: array of tokens
 * @delim: deliminator
 *
 */
void tokenize(char *command, char *tokens[], const char *delim)
{
	int i = 0;

	tokens[i] = strtok(command, delim);

	while (tokens[i] != NULL)
	{   
		tokens[++i] = strtok(NULL, delim);
	}

	tokens[i] = NULL;

	// for (int j = 0; tokens[j] != NULL; j++) {
    //     printf("Token[%d]: '%s'\n", j, tokens[j]);
    // }
}
