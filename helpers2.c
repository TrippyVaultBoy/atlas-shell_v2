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
 * _strncmp - Compares the first n characters of two strings.
 *
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * @n: Maximum number of characters to compare.
 *
 * Return: Negative if s1 < s2, zero if s1 == s2, positive if s1 > s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
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
