#include "main.h"


/**
 * execute_pipe - func to handle the '|' operator
 *
 * @commands: commands
 */
void execute_pipe(char **commands)
{
	int pipe_fd[2];
	pid_t pid;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		close(pipe_fd[0]); /* Close unused read end */
		dup2(pipe_fd[1], STDOUT_FILENO); /* Redirect stdout to write end of pipe */
		close(pipe_fd[1]);

		execvp(commands[0], commands);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipe_fd[1]); /* Close unused write end */
		dup2(pipe_fd[0], STDIN_FILENO); /* Redirect stdin to read end of pipe */
		close(pipe_fd[0]);

		waitpid(pid, NULL, 0);

		/* Execute next command in pipeline */
		next_command(commands);
	}
}


/**
 * next_command - executes the next command in the pipeline
 *
 * @commands: commands
 */
void next_command(char **commands)
{
	while (*commands != NULL)
	{
		if (**commands == '|')
		{
			commands++;
			execute_pipe(commands);
			break;
		}
		else
		{
			parse_command(commands);
			break;
		}
	}
}
