#include "shell.h"
#include <string.h>
#include <stdlib.h>

/*
typedef struct builtinType
{
	char *builtinName
	int (*function)(void);
}builtinType
*/
int find_builtin(char *lineptr)
{
	int counter, size;

builtinType builtin[] = {
	{"env", builtEnv},
	{'\0', NULL},
	};

	size = (sizeof(builtin) / sizeof(builtinType));
	counter = 0;
	lineptr = strtok(lineptr, "\n");
	if(lineptr != NULL)
	{
		while (counter < (size - 1))
		{
			if(strcmp(builtin[counter].builtinName, lineptr) == 0)
			{
				builtin[counter].function();
				return (1);
			}
				counter++;
		}
	}
	return (0);
}
