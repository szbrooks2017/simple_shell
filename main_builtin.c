#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdarg.h>
#include <errno.h>
typedef struct builtinType
{
        char *builtinName;
        int (*function)();
}builtinType;

extern char **environ;

int builtEnv(void)
{
        int counter = 0;

        while (environ[counter] != NULL)
        {
                write(1, environ[counter], strlen(environ[counter]));
                write(1, "\n", 1);
                counter++;
        }


return (0);
}
int (*find_builtin(char *lineptr))()
{
        int counter;
builtinType builtin[] = {
        {"env", builtEnv},
        {NULL, NULL}
        };

	counter = 0;
	lineptr = strtok(lineptr, "\n");
 	printf("%s\n", builtin[0].builtinName); 
       if(lineptr != NULL)
        {
                while (counter < 1)
                {
                        if(strcmp(builtin[counter].builtinName, lineptr) == 0)
                                return(builtin[counter].function);
                                counter++;
                }
        }
        return (0);
}

int maini(void)
{
	find_builtin("env");

return (0);
}
