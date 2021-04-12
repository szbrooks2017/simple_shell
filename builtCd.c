#include "shell.h"
#include <unistd.h>
/**
* builtCd - calls custom change directory command
* Return: chdir returns 0
*
*/

int builtCd(char *path)
{
	/*printf("in builtCd lineptr is : %s", lineptr);
	return (chdir(lineptr)); */
return (chdir(path));
/*	if (chdir(path) < 0)
	{
		perror("cd error:");
	}
	return (chdir(path));
*/
}
