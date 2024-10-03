#include "main.h"

/**
 * parse_command - func to parse the command
 *
 * @args: command
 */
void parse_command(char *args[])
{
	int status;

	if (args[0] == NULL)
	{
		perror("parse_command: No arguments");
		return;
	}

	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork failed");
		return;
	}
	else if (pid == 0)
	{
		char *path = find_executable(args[0]);

		if (path == NULL)
		{
			fprintf(stderr, "hsh: %s: not found\n", args[0]);
			exit(127);
		}

		/* printf("Executing command: %s\n", path); */
		execve(path, args, environ);
		perror("execve error");
		free(path);
		exit(127);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
