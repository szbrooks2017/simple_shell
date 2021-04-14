#include "shell.h"
#include <unistd.h>
/**
* builtCd - calls custom change directory command
* @path: is the lineptr
* Return: chdir returns 0
*
*/

int builtCd(char *path)
{
return (chdir(path));
}
