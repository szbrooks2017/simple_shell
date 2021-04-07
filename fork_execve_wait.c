#include "shell.h"

/**
* make_fork - forks a child process to do tasks
* @cmd: refers to the command input
* Return: returns nothing
*/

void make_fork(char *cmd)
{
	pid_t child_pid;
	char *newenviron[] = { NULL };
	int status = 0;
	char *argv[2] = { NULL};

	argv[0] = cmd;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		/* exe */
		if (execve(cmd, argv, newenviron) == -1)
		{
			perror("Error:");
		}

	}
	else
	{
		wait(&status);
	}
	return;
}
