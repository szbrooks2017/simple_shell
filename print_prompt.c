#include "shell.h"
/**
* print_prompt - prints what is displayed before the $
*/

void print_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
/**
* signal_id - sets a signal handler as sig
* @sig: sig is set to sigint (signal interrupt)
*
*/
void signal_id(int sig)
{
	if (sig == SIGINT)
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
}
