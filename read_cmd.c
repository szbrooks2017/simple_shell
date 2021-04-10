#include "shell.h"

/**
 * read_cmd - gathers input from the loop with EOF exit checks
 * @lineptr: is the string
 * Return: returns the command string back
 */

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
	return (lineptr);

}

