#include "shell.h"
void free_main(char *p1, char *p2, char *p3)
{

	/*if (!p1) */
		free(p1);
	/*if (!p2) */
                free(p2);
	/*if (!p3) */
                free(p3);
	return;
}
