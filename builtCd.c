#include "shell.h"
#include <unistd.h>
/**
* builtCd - calls custom change directory command
* Return: chdir returns 0
*
*/

int builtCd(void)
{
	/*printf("in builtCd lineptr is : %s", lineptr);
	return (chdir(lineptr)); */

	const char *pwd;
	char lineptr[100];

/*ath_pwd =_getenv('PATH');*/
	pwd = getcwd(lineptr, 100);
	printf("in CD - before chdir pwd is %s\n", pwd);
	chdir(pwd);
	printf("in CD - after chdir pwd is %s\n", pwd);
	printf("in CD - before chdir path_pwd %s\n", path_pwd);
	chdir(path_pwd);

return (1);
/*	if (chdir(path) < 0)
	{
		perror("cd error:");
	}
	return (chdir(path));
*/
}
