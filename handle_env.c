#include "main.h"

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
