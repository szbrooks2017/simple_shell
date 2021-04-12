#include "shell.h"

/**
* builtExit - terminates the calling process immediately.
* @status: is the status value returned to the parent process
*
*/

int builtExit(char *lineptr)
{
	free(lineptr);
/*xit(errno);*/
	return (0);

}
