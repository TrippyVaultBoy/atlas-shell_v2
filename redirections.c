#include "main.h"


/**
 * handle_redirection - Handles redirection based on the token provided
 *
 * @token: token
 * @command: command
 */
void handle_redirection(char *token, char *command)
{
	if (_strcmp(token, ">") == 0 || _strcmp(token, ">>") == 0)
	{
		redirect_output(token, command);
	}
	else if (_strcmp(token, "<") == 0)
	{
		redirect_input(token, command);
	}
}


/**
 * redirect_output - Redirects standard output to a specified file
 *
 * @filename: specified file
 * @command: command
 */
void redirect_output(char *filename, char *command)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		perror("open");
		exit(1);
	}

	dup2(fd, STDOUT_FILENO);
	close(fd);

	parse_command((char **)command);
}


/**
 * redirect_input - Redirects standard input from a specified file
 *
 * @filename: specified file
 * @command: command
 */
void redirect_input(char *filename, char *command)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("open");
		exit(1);
	}

	dup2(fd, STDIN_FILENO);
	close(fd);

	parse_command((char **)command);
}


/**
 * heredoc - Reads input from stdin until it hits a specified delimiter
 *
 * @delimiter: specified delimiter
 *
 * Return: delimiter string
 */
char *heredoc(char *delimiter)
{
	char *buffer = NULL;
	size_t capacity = 0;
	ssize_t bytes_read;

	while ((bytes_read = getline(&buffer, &capacity, stdin)) != -1)
	{
		if (_strstr(buffer, delimiter) != NULL)
		{
			break;
		}
	}

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	buffer[_strcspn(buffer, "\n")] = 0;
	free(buffer);
	return (_strdup(delimiter));
}
