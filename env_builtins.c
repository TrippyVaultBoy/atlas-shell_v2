#include "main.h"


/**
 * setenv_builtin - sets an environment variable
 *
 * @var: variable
 * @value: value
 */
void setenv_builtin(char *var, char *value)
{
	char *new_env_var = NULL;
	size_t var_len = _strlen(var);
	size_t value_len = _strlen(value);

	if (var == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Invalid arguments\n");
		return;
	}

	/* Allocate memory for the new environment variable */
	new_env_var = malloc(var_len + value_len + 2);  /* +2 for '=' and '\0' */

	if (new_env_var == NULL)
	{
		perror("malloc");
		return;
	}

	/* Copy var and value into the new string */
	_strcpy(new_env_var, var);
	_strcat(new_env_var, "=");
	_strcat(new_env_var, value);

	/* Find the existing variable or add a new one */
	char **env_var = environ;
	int found = 0;

	while (*env_var != NULL)
	{
		char *equals = _strchr(*env_var, '=');

		if (equals && _strncmp(*env_var, var, equals - *env_var) == 0)
		{
			free(*env_var);
			*env_var = new_env_var;
			found = 1;
			break;
		}
		env_var++;
	}

	if (!found)
	{
		/* Add a new environment variable */
		size_t env_size = 0;

		while (environ[env_size] != NULL)
			env_size++;

		environ = realloc(environ, sizeof(char *) * (env_size + 2));

		if (environ == NULL)
		{
			perror("realloc");
			free(new_env_var);
			return;
		}

		environ[env_size] = new_env_var;
		environ[env_size + 1] = NULL;
	}
}


/**
 * unsetenv_builtin - unsets an environment variable
 *
 * @var: variable
 */
void unsetenv_builtin(char *var)
{
	char **env_var = environ;
	int found = 0;

	while (*env_var != NULL && !found)
	{
		char *equals = _strchr(*env_var, '=');

		if (equals && _strncmp(*env_var, var, equals - *env_var) == 0)
		{
			free(*env_var);
			found = 1;
		}
		else
		{
			env_var++;
		}
	}

	if (!found)
	{
		fprintf(stderr, "unsetenv: Variable not found\n");
		return;
	}

	/* Shift all subsequent environment variables down */
	while (*env_var != NULL)
	{
		*env_var = *(env_var + 1);
		env_var++;
	}
}
