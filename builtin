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
int (*find_builtin(char *lineptr))()
{
	int counter = 0;
	lineptr = strtok(lineptr, "\n");

builtinType builtin[] = {
	{"env", builtEnv},
	{NULL, NULL}
	};

	if(lineptr != NULL)
	{
		while (counter < 2)
		{
			if(strcmp(builtin[counter].builtinName, lineptr) == 0)
				return(builtin[counter].function);
				counter++;
		}
	}
	return (0);
}
