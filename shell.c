#include "shell.h"
/**
* print_prompt - prints what is displayed before the $
*/

void print_prompt(void)
{
	write(1, "#cisfun$ ", 9);
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
/**
* check_space - checks if there is a space in the command input
* @lineptr: refers to the command input
* Return: returns 0
*/

int check_space(char *lineptr)
{
	int i = 0;

	while (lineptr[i] != '\n')
	{
		if (lineptr[i] == ' ')
			return (1);
		i++;
	}
	return (0);

}

/**
* split_cmd - splits the command input by the space found
* @lineptr: refers to the command input
* Return: returns the line pointing to the command input
*/

char *split_cmd(char *lineptr)
{
	/* check if there is a space in the line */
	if (check_space(lineptr) == 1)
		return (_strtok(lineptr, " \n"));
	return (lineptr);
}

/**
* check_cmd_avi - checks to see if the command is available
* @cmd: refers to the command input
* Return: returns the command input with the stat command
*/

int check_cmd_avi(char *cmd)
{
	struct stat sb;

	cmd = _strtok(cmd, "\n");
	return (stat(cmd, &sb));
}

/**
* main - is the main shell loop
* @argc: is an unused command count
* @argv: is the amount of arguments
* Return: returns 0 for success.
*/
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *lineptr, *cmd, *lineptr_dup, *lineptr_builtin;

	do {
		lineptr = NULL;
		signal(SIGINT, signal_id);
		/* print prompt */
		if (isatty(STDIN_FILENO))
		{
			print_prompt();
		}
		/* read line */
		read_cmd(&lineptr);

		if (!lineptr)
		{
			exit(EXIT_SUCCESS);

		}

		if (*lineptr == '\0' || *lineptr == '\n')
		{
			free(lineptr);
			continue;
		}

		if (_strcmp(lineptr, "exit\n") == 1)
		{
			free(lineptr);
			break;
		}

		lineptr_builtin = _strdup(lineptr);

		if (find_builtin(lineptr_builtin) == 1)
		{
			free(lineptr_builtin);
			free(lineptr);
			continue;
		}

		if (lineptr[0] != '/')
			lineptr = deal_with_path(lineptr);
		lineptr_dup = _strdup(lineptr);
		cmd = split_cmd(lineptr);
		/* check the cmd availability */
		if (check_cmd_avi(cmd) == -1)
			write(1, "./shell: No such file or directory\n", 35);
		else
		make_fork(lineptr_dup);
		free(lineptr_builtin);
		free(lineptr_dup);
		free(lineptr);
			lineptr = NULL;
		fflush(stdin);

	} while (1);

	return (0);
}








