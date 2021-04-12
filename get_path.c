#include "shell.h"

/**
* _getenv - finds a path in the environ global variable
* @name: is the name of the variable, entered
* Return: returns the full path of the variable searched or NULL
*/

char *_getenv(char *name)
{
	int i = 0;
	size_t l = _strlen(name);

	if (!environ || !*name)
		return (NULL);
	/* index i thru environ variable until it matches the name*/
		/*inputted or the full path doesn't = =*/
	while (environ[i] && (_strncmp(name, environ[i], l) || environ[i][l] != '='))
	{
		i++;
	}
	if (environ[i])
		return (environ[i] + l + 1);

	return (NULL);
}

/**
* _strcat_w_slash - concatenates teh string with a slash
* @a: source string
* @b: string that appends
* Return: returns the string
*/
char *_strcat_w_slash(char *a, char *b)
{
	char *str = NULL;
	int i = 0, j = 0, z = 0;

	str = malloc(_strlen(a) + 1 + _strlen(b) + 2);
	for (i = 0; i < _strlen(a); i++)
	{
		str[i] = a[i];
	}
	str[i] = '/';
	for (j = i + 1, z = 0; j <= i + 1 + _strlen(b); j++, z++)
		str[j] = b[z];
	return (str);
}
/**
* deal_with_path - duplicates the lineptr, splits the path into strings
*	saves them into a char **arg, switch dir to check if cmd exist
*	changedir, stat, strcat, to append the address if it exists
* @lineptr: is the command input
* Return: returns the full lineptr_dup with address
*/

char *deal_with_path(char *lineptr)
	{

	char *path = NULL, *free_p = NULL, *argv_p = NULL;
	char **argv = NULL;
	int i = 0, n = 0;
	const char *delim = ":\n";
	char *lineptr_dup = NULL, *cmd = NULL, *str_w_dir = NULL;
	struct stat sb;
	/*get the path */
	path = _strdup(_getenv("PATH"));
	/* split the path into strings and save them into char **arg*/
	/* check how many colons within the line */
	while (path[i] != '\0')
	{
		if (path[i] == ':')
			n++;
		i++;
	}
	lineptr_dup = _strdup(lineptr);
	cmd = split_cmd(lineptr);
	cmd = _strtok(cmd, "\n");
	argv = (char **)malloc(sizeof(char *) * (n + 3));
	argv[0] = _strtok(path, delim);
	str_w_dir = _strcat_w_slash(argv[0], cmd);
	if (stat(str_w_dir, &sb) == 0)
	{
		free(str_w_dir);
		free(cmd);
		free(path);
		argv_p = argv[0];
		free_p = _strcat_w_slash(argv_p, lineptr_dup);
		free(lineptr_dup);
		free(argv);
		return (free_p);
	}
	for (i = 1; i < (n + 1); i++)
	{
		free(str_w_dir);
			str_w_dir = NULL;
		argv[i] = _strtok(NULL, delim);
		str_w_dir = _strcat_w_slash(argv[i], cmd);
		if (stat(str_w_dir, &sb) == 0)
		{
			free(cmd);
			free(str_w_dir);
			free(path);
			argv_p = argv[i];
			free_p = _strcat_w_slash(argv_p, lineptr_dup);
			free(lineptr_dup);
			free(argv);
			return (free_p);
		}
	}
	free(cmd);
	free(path);
	free(str_w_dir);
	free(argv);
	return (lineptr_dup);
}

