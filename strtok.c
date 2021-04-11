#include "shell.h"
/*
 * _strcspn - find index of first s1[i] that matches no s2[]
 * @s1: char *
 * @s2: char *
 * Return: size_t integer
*/
size_t _strspn(char *s1, const char *s2)
{
	char *sc1;
	const char *sc2;

	for (sc1 = s1; *sc1 != '\0'; ++sc1)
	{
		for (sc2 = s2; ; ++sc2)
			if (*sc2 == '\0')
				return (sc1 - s1);
			else if (*s1 == *s2)
				break;
	}
	return (sc1 - s1);
}
/*
 * _strcspn - find index of first s1[i] that matches any s2[] 
 * @s1: char *
 * @s2: char *
 * Return: size_t integer
*/
size_t _strcspn(char *s1, const char *s2)
{
	char *sc1;
	const char *sc2;

	for (sc1 = s1; *sc1 != '\0'; ++sc1)
	{
		for (sc2 = s2; *sc2 != '\0'; ++sc2)
			if (*sc1 == *sc2)
				return (sc1 - s1);
	}
	return (sc1 - s1);
}
/*
 * _strtok - split a NULL terminated string into tokens with NULL terminated
 * @s1: char *
 * @s2: char *
 * Return: size_t integer
*/


char *_strtok(char *s1, const char *s2)
{
	static char *s_save = "";/* set s_save as a empty string */
	char *s_begin = NULL, *s_end = NULL;

	/*if s1 is not NULL, s_begin = s1, otherwise s_save) */
	s_begin = s1 ? s1 : s_save;
	/*s_begin move forward n steps, n is index of first s1[i] that matches no s2[] */
	s_begin = s_begin + _strspn(s_begin, s2);
	/* if s_begin meets '\0' byte, return. the last token is NULL*/
	if (*s_begin == '\0')
	{
		s_save = "";
		return (NULL);
	}
	/* set s_end equals s_begin move n steps, n is index of first s1[i] that matches any s2[] */
	s_end = s_begin + _strcspn(s_begin, s2);
	if (*s_end != '\0')
		*s_end++ = '\0'; /*set delimeter to NULL byte */
	/*set s_save to s_end for the next round using, next s_begin will start from here */
	s_save = s_end;
	return (s_begin); 
}
