#ifndef SHELL_H
#define SHELL_H

/*libraries*/
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

/*global var*/
extern char **environ;

/*builtin struct */
/**
* struct builtinType - old variable used as a new variable
* @builtinName: is the operator of the struct
* @function: is the function called
*/
typedef struct builtinType
{
	char *builtinName;
	int (*function)();
} builtinType;


/* prototypes */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv);
void print_prompt(void);
char **read_cmd(char **lineptr);
int check_space(char *lineptr);
char *split_cmd(char *lineptr);
int check_cmd_avi(char *cmd);
void make_fork(char *cmd);
char *deal_with_path(char *lineptr);
char *_getenv(char *name);
char *_strcat_w_slash(char *a, char *b);
void signal_id(int sig);
/*builtin functions */
int find_builtin(char *lineptr);
int builtExit(char *lineptr);
int builtEnv(void);
int builtCd(void);
int builtHelp(void);
/*string prototypes*/
int _strcmp(char *lineptr, char *str);
int _strlen(char *s);
char *_strdup(char *str);
size_t _strspn(char *s1, const char *s2);
size_t _strcspn(char *s1, const char *s2);
char *_strtok(char *s1, const char *s2);
int _strncmp(char *s1, char *s2, size_t n);
#endif
