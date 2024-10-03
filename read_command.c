#include "main.h"

/**
 * read_command - command to read user input
 *
 * @command: command being input
 * @is_interactive: interactive mode flag
 * @exit_flag: exit flag
 */
void read_command(char *command, int is_interactive, int *exit_flag)
{
	if (is_interactive)
	{
		printf("shellv2: ");
		fflush(stdout);
	}

	if (fgets(command, sizeof(command), stdin) == NULL)
	{
		if (!is_interactive)
		{
			*exit_flag = 1;
		}
	}

	command[_strcspn(command, "\n")] = 0;
}
