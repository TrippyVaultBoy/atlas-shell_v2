#include "main.h"

/**
 * find_executable - looks for executable commands
 *
 * @cmd: command
 *
 * Return: NULL
 */
char *find_executable(const char *cmd)
{
	if (*cmd == '/')
	{
		if (access(cmd, X_OK) == 0)
		{
			return (_strdup(cmd));
		}
	}

	char *path = get_custom_env("PATH");
	char *token;
	size_t cmd_len = _strlen(cmd);
	char *full_path = malloc(128 + cmd_len + 2);

	token = strtok(path, ":");
	while (token != NULL)
	{
		_strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		token = strtok(NULL, ":");
	}

	free(full_path);
	return (NULL);
}


/**
 * execute_command - executes the commands
 *
 * @tokens: tokens
 * @prev_dir: previous directory
 * @curr_dir: current directory
 */
void execute_command(char **tokens)
{
	char *command = _strdup(tokens[0]);

	if (*tokens[0] == '/')
	{
		parse_command(tokens);
	}
	else
	{
		char *full_path = find_executable(tokens[0]);

		if (full_path != NULL)
		{
			tokens[0] = full_path;
			parse_command(tokens);
			free(full_path);
		}
		else
		{
			fprintf(stderr, "hsh: %s: not found\n", tokens[0]);
		}
	}
	char **pipe_commands = tokens;

	while (*pipe_commands != NULL)
	{
		if (_strcmp(*pipe_commands, "|") == 0)
		{
			*pipe_commands = NULL; /* Null terminate before the pipe */
			execute_pipe(pipe_commands + 1); /* Start executing from after the pipe */
			break;
		}
		pipe_commands++;
	}

	if (*tokens == NULL || _strcmp(*tokens, ";") == 0)
	{
		return;
	}
	else if (_strcmp(*tokens, "&&") == 0)
	{
		and_operator(tokens + 1);
	}
	else if (_strcmp(*tokens, "||") == 0)
	{
		or_operator(tokens + 1);
	}

	handle_redirection(*tokens, command);
	free(command);
}
