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
	char *home_dir;

	if (directory == NULL)
	{
		home_dir = getenv("HOME");

		if (chdir(home_dir) != 0)
		{
			printf("chdir home error\n");
		}

		setenv("PWD", home_dir, 1);
	}
	else if (_strcmp(directory, "-") == 0)
	{
		if (chdir(prev_dir) != 0)
		{
			printf("chdir - error\n");
		}

		setenv("PWD", prev_dir, 1);
	}
	else
	{
		if (chdir(directory) != 0)
		{
			printf("chdir error\n");
		}

		setenv("PWD", directory, 1);
	}

    _strcpy(prev_dir, curr_dir);
	if (getcwd(curr_dir, 100) == NULL) {
        perror("getcwd error");
    }
}
