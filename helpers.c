#include "main.h"

/**
 * _strcmp - function that compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: success
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}


/**
 * _strcpy - Copies a string from source to destination.
 *
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to original destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while ((*dest++ = *src++) != '\0')
	{
		;
	}

	return (original_dest);
}


/**
 * _strcspn - Counts characters in s not present in reject.
 *
 * @s: String to scan.
 * @reject: String containing characters to reject.
 *
 * Return: Count of characters not in reject.
 */
size_t _strcspn(const char *s, const char *reject)
{
	const char *p;
	const char *r;
	size_t count = 0;

	for (p = s; *p != '\0'; p++)
	{
		for (r = reject; *r != '\0'; r++)
		{
			if (*p == *r)
			{
				return (count);
			}
		}
		count++;
	}
	return (count);
}


/**
 * _strlen - returns the length of a string
 * @s: parameter
 * Return: Always 0
 */
int _strlen(const char *s)
{
	int i;
	int length = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return (length);
}
