#include "shell.h"

int main(__attribute__((unused))int argc, char **argv)
{
	char *ptr, *token;
	size_t n = 0;
	pid_t child_pid;
	char delim[] = " ";
	char **av = NULL;
	int command, status, i = 0;

	while (1)
	{
	/* print prompt */
		write(1, "$ ", 2);
	/* call children */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
		/*getline*/
			command = getline(&ptr, &n, stdin);
			if (command == EOF)
			{
				exit(0);
			}
			/* split input */
			token = strtok(ptr, delim);
			av[0] = token;
			while (av[i + 1] != NULL)
			{
				av[i + 1] = strtok(NULL, delim);
				i++;
			}

			av[i + 1] = NULL;
			if (execve(av[0], av, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
		/* wait */
		wait(&status);
		}
	/* free */
	}
}
