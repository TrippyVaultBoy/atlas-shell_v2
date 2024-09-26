#include "main.h"

/**
 * main - main shell function
 *
 * Return: Success
 */
int main(void)
{
	int exit_flag = 0;

	char command[100];

	char *tokens[100];

	const char *delim = " ";

	char prev_dir[100] = "";

	char curr_dir[100];

	getcwd(curr_dir, sizeof(curr_dir));

	while (!exit_flag)
	{
		read_command(command);
		tokenize(command, tokens, delim);

		if (strcmp(tokens[0], "exit") == 0)
		{
			exit_flag = 1;
		}
		else if (strcmp(tokens[0], "cd") == 0)
		{
			handle_cd(tokens[1], prev_dir, curr_dir);
		}
		else if (strcmp(tokens[0], "env") == 0)
		{
			handle_env();
		}

	}

	return (0);
}
