#include "shell.h"

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
int check_cmd_avi(char *cmd)
{
	struct stat sb;

	cmd = strtok(cmd, "\n");	
	return (stat(cmd, &sb));
}
void make_fork(char *cmd)
{
	pid_t child_pid;
	char *newenviron[] = { NULL };
	int status = 0;
	char *argv[2] = { NULL};

	argv[0] = cmd;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		/* exe */
		if (execve(cmd, argv, newenviron) == -1)
		{
			perror("Error:");
		}

	}
	else
	{
		wait(&status);
	}
	return;
}

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *lineptr, *cmd;

	do
	{
		lineptr = NULL;
		/* print prompt */
		print_prompt();
		/* read line */
			read_cmd(&lineptr);
	/*	printf("%s\n", lineptr); */
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
		/* check the cmd availability */
		if (check_cmd_avi(cmd) == -1)
		{
			write(1, "./shell: No such file or directory\n", 35);
			continue;			
		}
		else
		{
			/* call execve() */
			printf("We are creating folk\n");
			make_fork(cmd);
			continue;
		}
		free(lineptr);
			lineptr = NULL;
		fflush(stdin);
	}while(1);

	return (0);
}
