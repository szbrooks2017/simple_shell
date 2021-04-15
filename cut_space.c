#include "shell.h"
char *cut_space(char *p)
{
	while (*p)
	{
		if (*p == ' ')
			p++;
		else
			return (p);

	}
	return (p);

}
