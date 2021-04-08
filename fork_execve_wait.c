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
	const char *delim = " \n"; 

	/* check how many spaces within the line */
	while (lineptr[i] != '\0')
	{	
		if (lineptr[i] == ' ')
			n++;
		i++;
	}
	argv = (char **)malloc(sizeof(char *) * (n + 3));
	argv[0] = strtok(lineptr, delim);
	for(i = 0; i < n; i++)
		argv[i + 1] = strtok(NULL, delim);
	argv[n + 1] = NULL;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, newenviron) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
	}
/*	while(n)
	{
		free(argv[n]);
		argv[n] = NULL;
		n--;
	}*/
	free(argv);
	return;
}
