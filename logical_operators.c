#include "main.h"


/**
 * and_operator - handles the && logical operator
 *
 * @commands: commands
 *
 * Return: status
 */
int and_operator(char **commands)
{
	int status = 0;
	char **current_command = commands;

	while (*current_command != NULL && _strcmp(*current_command, "&&") == 0)
	{
		current_command++;
		if (*current_command == NULL)
			break;

		status = single_command(current_command);
		if (status != 0)
			break;
	}

	return (status);
}


/**
 * or_operator - handles the || operator
 *
 * @commands: commands
 *
 * Return: status
 */
int or_operator(char **commands)
{
	int status = 0;
	char **current_command = commands;

	while (*current_command != NULL && _strcmp(*current_command, "||") == 0)
	{
		current_command++;

		if (*current_command == NULL)
		{
			break;
		}

		status = single_command(current_command);

		if (status == 0)
		{
			break;
		}
	}

	return (status);
}


/**
 * single_command - executes a single command
 *
 * @commands: commands
 *
 * Return: status
 */
int single_command(char **commands)
{
	char *full_path = find_executable(commands[0]);

	if (full_path == NULL)
	{
		fprintf(stderr, "hsh: %s: not found\n", commands[0]);
		return (-1);
	}

	int status = 0;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(full_path, commands, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}

	free(full_path);

	return (WEXITSTATUS(status));
}
