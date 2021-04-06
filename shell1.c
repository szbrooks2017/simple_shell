#include "shell.h"

char **read_cmd(char **lineptr)
{
	ssize_t command;
	size_t n = 0;

	command = getline(lineptr, &n, stdin);
		if (command == EOF)
		{
			free(lineptr);
			exit(0);
		}
	return(lineptr);

}

void print_prompt()
{
	write(1, "#cisfun$ ", 9);
}
int _strcmp(char *lineptr, char * str)
{
	int i = 0;

	for(i = 0; lineptr[i] == str[i]; i++)
	{
		if (lineptr[i] == '\n' && str[i] == '\n')
			return (1);
	}
	return (0);

}
int check_space(char *lineptr)
{
	int i = 0;

	while(lineptr[i] != '\n')
	{
		if (lineptr[i] == ' ')
			return (1);
		i++;
	}
	return (0);

}
char *split_cmd(char *lineptr)
{
	/* check if there is a space in the line */
	if (check_space(lineptr) == 1)
		return (strtok(lineptr, " "));
	return (lineptr);
	
}
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *lineptr = NULL, *cmd;

	while(1)
	{
		/* print prompt */
		print_prompt();
		/* read line */
		read_cmd(&lineptr);
		printf("%s\n", lineptr);
		if(!lineptr)
		{
			exit(EXIT_SUCCESS);

		}
		if(*lineptr == '\0' || *lineptr == '\n')
		{
			free(lineptr);
			continue;
		}
		if(_strcmp(lineptr, "exit\n") == 1)
		{
			free(lineptr);
			break;
		}
		/* split the cmd */
		cmd = split_cmd(lineptr);
		printf("%s\n", cmd);

		
		free(lineptr);
			lineptr = NULL;
		fflush(stdin);
	}

	return (0);
}
