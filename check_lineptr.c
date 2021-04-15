#include "shell.h"
/**
* check_lineptr - has null checks and exit checks
* @lineptr: is the current input
* Return: returns vary
*/
int check_lineptr(char *lineptr)
{

	if (!lineptr)
		return (2);
	else if (*lineptr == '\0' || *lineptr == '\n')
	{
		free(lineptr);
		return (3);
	}
	if (_strncmp(lineptr, "exit", 4) == 0)
	{
		/*free(lineptr);*/
		return (4);
	}
return (0);
}
