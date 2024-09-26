#include "main.h"

/**
 * read_command - command to read user input
 *
 * @command: command being input
 */

void read_command(char *command)
{
	printf("shellv2: ");

	fgets(command, 100, stdin);
	command[strcspn(command, "\n")] = 0;
}
