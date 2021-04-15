#include "shell.h"

/**
* _strcmp - compares two strings
* @lineptr: is the first string
* @str: is the second string
* Return: returns 0 for success
*/

int _strcmp(char *s1, char *s2)
{
	char i = 0;

	while (*(s1 + i) == *(s2 + i))
	{
		if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
			break;
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
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
/**
* _strncmp - compares the n bytes of s1 to s2
* @s1: first string to compare
* @s2: second string to compare
* @n: size of s1 to compare to s2
* Return: returns true
*/

int _strncmp(char *s1, char *s2, size_t len)
{
	unsigned int position = 0;
	int diff = 0;
	
	while (position < len)
	{
		if (s1[position] == s2[position])
		{
			position++;
			continue;
		}
		else
		{
			diff = s1[position] - s2[position];	
			break;
		}
		position++;
		
	}
	return (diff);
}




