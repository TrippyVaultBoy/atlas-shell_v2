#include "main.h"


/**
 * handle_cd - func to handle the 'cd' builtin
 *
 * @directory: Directory
 * @prev_dir: previous directory
 * @curr_dir: current directory
 *
 */
void handle_cd(char *directory, char *prev_dir, char *curr_dir)
{
	if (directory == NULL || _strcmp(directory, "~") == 0)
	{
		chdir(getenv("HOME"));
	}
	else if (_strcmp(directory, "-") == 0)
	{
		chdir(prev_dir);
	}
	else
	{
		struct stat sb;

		if (stat(directory, &sb) == 0 && S_ISDIR(sb.st_mode))
		{
			if (chdir(directory) != 0)
			{
				perror("cd");
			}
		}
		else
		{
			fprintf(stderr, "cd: %s: Not a directory\n", directory);
		}
	}

	strcpy(prev_dir, curr_dir);
	if (getcwd(curr_dir, 100) == NULL)
	{
		perror("getcwd");
	}
}


/**
 * handle_env - handles the env builtin
 *
 * Return: success
 */
int handle_env(void)
{
	char **env_var;

	for (env_var = environ; *env_var != NULL; env_var++)
	{
		printf("%s\n", *env_var);
	}

	return (0);
}


/**
 * print_cwd - prints current working directory
 */
void print_cwd(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("getcwd");
	}
}
