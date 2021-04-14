#include "shell.h"

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
	size_t n = 0;
	ssize_t command = 0;
	int u = 0;

	while (1)
	{
		lineptr = NULL;
		signal(SIGINT, signal_id);
		if (isatty(STDIN_FILENO))
			print_prompt();
		command = getline(&lineptr, &n, stdin);
		if (command == EOF)
			break;
		if (check_lineptr(lineptr) == 2)
			continue;
		if (check_lineptr(lineptr) == 3)
			continue;
		u = check_lineptr(lineptr);
		if (u == 4)
			break;
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
		if (check_cmd_avi(cmd) == -1)
			write(1, "./shell: No such file or directory\n", 35);
		else
			make_fork(lineptr_dup);
		free_main(lineptr_builtin, lineptr_dup, lineptr);
	}
	return (0);
}








