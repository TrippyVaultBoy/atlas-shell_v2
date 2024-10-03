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
			return (strdup(cmd));
		}
		else
		{
			return (NULL);
		}
	}


	char *path = getenv("PATH");
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
			printf("Found executable: %s\n", full_path);
			return (full_path);
		}

		token = strtok(NULL, ":");
	}

	free(full_path);
	return (NULL);
}
