#include "shell.h"

/**
* builtEnv - calls the built in env variable
* Return: returns 0 for success
*/

int builtEnv(void)
{
	int counter = 0;

	while (environ[counter] != NULL)
	{
		write(1, environ[counter], _strlen(environ[counter]));
		write(1, "\n", 1);
		counter++;
	}


return (0);
}
