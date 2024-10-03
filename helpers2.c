#include "main.h"


/**
 * _strdup - Creates a duplicate of a string.
 * @s: String to duplicate.
 *
 * Return: Pointer to the duplicated string.
 */
char *_strdup(const char *s)
{
	char *new_string = malloc(_strlen(s) + 1);

	if (new_string == NULL)
	{
		return (NULL);
	}

	_strcpy(new_string, s);
	return (new_string);
}


/**
 * get_custom_env - Custom implementation of getenv()
 * @var: Variable name to search for
 *
 * Return: Value of the environment variable if found, NULL otherwise
 */
char *get_custom_env(const char *var)
{
	char **env_var;

	for (env_var = environ; *env_var != NULL; env_var++)
	{
		char *equals = strchr(*env_var, '=');

		if (equals && _strncmp(*env_var, var, equals - *env_var) == 0)
		{
			return (equals + 1);
		}
	}
	return (NULL);
}
