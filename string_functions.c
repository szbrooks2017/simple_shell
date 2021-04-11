#include "shell.h"

/**
* _strcmp - compares two strings
* @lineptr: is the first string
* @str: is the second string
* Return: returns 0 for success
*/

int _strcmp(char *lineptr, char *str)
{
	int i = 0;

	for (i = 0; lineptr[i] == str[i]; i++)
	{
		if (lineptr[i] == '\n' && str[i] == '\n')
			return (1);
	}
	return (0);

}
/**
* _strdup - duplicates the string and considers malloc
* @str: is the string input
* Return: returns the duplicated string
*/
char *_strdup(char *str)
{
	int index = 0, len = 1;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	dup_str = malloc((sizeof(char) * len) + 1);

	if (dup_str == NULL)
		return (NULL);

	while (index < len)
	{
		dup_str[index] = str[index];
		index++;
	}

	dup_str[index] = '\0';
	return (dup_str);
}

/**
* _strlen - finds the length of the string
* @s: is the string to find the length of
* Return: returns the string length
*/
int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;
	return (c);
}
int _strncmp(char *s1, char *s2, size_t n)
{
	for(; 0 < n; ++s1, ++s2, --n)
	{
		if (*s1 != *s2)
			return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
		else if (*s1 == '\0')
			return (0);
	}

	return (0);
}




