#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
* find_builtin - searches for shell builtin functions
* @lineptr: refers to the command input
* Return: returns the match for true
*/

int find_builtin(char *lineptr)
{
	int counter, size;

builtinType builtin[] = {
	{"env", builtEnv},
	{"cd", builtCd},
	{"help", builtHelp},
	{'\0', NULL},
	};

	size = (sizeof(builtin) / sizeof(builtinType));
	counter = 0;
	lineptr = strtok(lineptr, "\n");
	if (lineptr != NULL)
	{
	printf("what lineptr in builtin is : %s\n", lineptr);
		while (counter < (size - 1))
		{
			if (strcmp(builtin[counter].builtinName, lineptr) == 0)
			{
				builtin[counter].function();
				return (1);
			}
				counter++;
		}
	}
	return (0);
}

