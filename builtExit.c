#include "shell.h"

/**
* builtExit - terminates the calling process immediately.
* @status: is the status value returned to the parent process
*
*/

int builtExit(void)
{

	exit(errno);
	return (0);

}
