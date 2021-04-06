#include "shell.h"

char *getline()
{
	size_t n = 100;
	ssize_t command;
	char ptr = NULL;
		ptr = malloc(n);
                if (ptr == NULL)
                {
                        return (NULL);
                }
                        command = getline(&ptr, &n, stdin);
                        if (command == EOF)
                        {
                                exit(0);
                        }
	return(ptr);

}

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *ptr, *token, *cmd;
	size_t n;
	pid_t child_pid;
	char delim[] = " ";
	char **av = NULL;
	int command, status, i = 0;

	do
	{
		/* print prompt */
		write(1, "$ ", 2);
		/*getline, read from the cmd line, return the char * pointer*/
		cmd = getline();
			/* split input 
			token = strtok(ptr, delim);
			av[0] = token;
			while (av[i + 1] != NULL)
			{
				av[i + 1] = strtok(NULL, delim);
				i++;
			}

			av[i + 1] = NULL; */
		/* call children */
		/*
                child_pid = fork();
                if (child_pid == -1)
                {
                        perror("Error:");
                        return (1);
                }
                if (child_pid == 0)
                {
			if (execve(av[0], av, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
		 wait 
		wait(&status);
		} */
	/* free */
	} while(1);
	return (0);
}
