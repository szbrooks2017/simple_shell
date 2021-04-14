/**
* check_lineptr - has null checks and exit checks
* @lineptr: is the current input
* Return: returns vary
*/
int check_lineptr(*char lineptr)
{
	if (!lineptr)
		return (2);
	if (*lineptr == '\0' || *lineptr == '\n')
	{
		free(lineptr);
		return (3);
	}
	if (_strcmp(lineptr, "exit\n") == 1)
	{
		free(lineptr);
		return (-1);
	}
return (0);
}
