#include "shell.h"

char **read_cmd(char **lineptr)
{
	ssize_t command;
	size_t n = 0;

	command = getline(lineptr, &n, stdin);
		if (command == EOF)
		{
			free(lineptr);
			exit(0);
		}
	return(lineptr);

}

