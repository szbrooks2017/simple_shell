#include "shell.h"

char *deal_with_path(char *lineptr)
{
/*get the path
dup the lineptr->lineptr_dup
split the path into strings and save them into char **arg
switch dir to check if cmd exist, chandedir() and stat()
strcat() the address with lineptr_dup if it exist
return the full lineptr_dup with address*/

	char* path = NULL;
	int i = 0;

	while (environ[i] != '\0')
	{
		if(strncmp(environ[i], _strlen('PATH')) == 0)
		{
		path = strdup(environ[i];
			printf("full path %s\n", environ[i]);
		}
	}
return (path);
}
		
