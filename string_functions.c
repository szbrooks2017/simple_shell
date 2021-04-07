#include "shell.h"

/**
* _strcmp - compares two strings
* @lineptr: is the first string
* @str: is the second string
* Return: returns 0 for success
*/

int _strcmp(char *lineptr, char *str)
{
	int i = 0;

	for (i = 0; lineptr[i] == str[i]; i++)
	{
		if (lineptr[i] == '\n' && str[i] == '\n')
			return (1);
	}
	return (0);

}
