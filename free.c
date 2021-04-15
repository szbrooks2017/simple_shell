#include "shell.h"
/**
 * free_3 - free the memoru
 * @p1: char *
 * @p2: char *
 * @p3: char *
 */
void free_3(char *p1, char *p2, char *p3)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	if (p3)
		free(p3);
}

/**
 * free_3_double - free the memoru
 * @p1: char *
 * @p2: char *
 * @p3: char **
 */
void free_3_double(char *p1,char *p2, char **p3)
{
	free(p1);
	free(p2);
	free(p3);
}
/**
 * free_2 - free the memoru
 * @p1: char *
 * @p2: char *
 */
void free_2(char *p1, char *p2)
{
	free(p1);
	free(p2);
}
/**
 * free_4 - free the memoru
 * @p1: char *
 * @p2: char *
 * @p3: char *
 * @p4: char **
 */
void free_4(char *p1, char *p2, char *p3, char **p4)
{
	free(p1);
	free(p2);
	free(p3);
	free(p4);
}
/**
 * free_5 - free the memoru
 * @p1: char *
 * @p2: char *
 * @p3: char *
 * @p4: char *
 * @p5: char **
 */
void free_5(char *p1, char *p2, char *p3, char *p4, char **p5)
{
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
}
