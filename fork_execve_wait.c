#include "shell.h"

/**
* make_fork - forks a child process to do tasks
* @cmd: refers to the command input
* Return: returns nothing
*/

void make_fork(char *lineptr)
{
	pid_t child_pid;

	char *newenviron[] = { NULL };
	int status = 0;
	char **argv = NULL;
	int i = 0, n = 0;

	/* check how many spaces within the line */
	while (lineptr[i] != '\0')
	{	
		if (lineptr[i] == ' ')
			n++;
		i++;
	}
	argv = malloc(sizeof(char *) * (n + 3));
	if (n > 0)
	{
		argv[0] = strtok(lineptr, " ");
		printf("%s\n", argv[0]);
		for(i = 0; i <= n; i++)
		{
			argv[i + 1] = strtok(NULL, " ");
			printf("%s\n", argv[i+1]);
		}
		argv[n + 1] = NULL;
	}
	else
	{
		argv[0] = strtok(lineptr, "\n");
		argv[1] = NULL;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		/* exe */
		if (execve(argv[0], argv, newenviron) == -1)
		{
			perror("Error:");
		}

	}
	else
	{
		wait(&status);
	}
	free(argv);
	return;
}
