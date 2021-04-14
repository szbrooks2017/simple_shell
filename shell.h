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
int check_lineptr(char *lineptr);
void free_3(char *p1, char *p2, char *p3);
void free_2(char *p1, char *p2);
void free_4(char *p1, char *p2, char *p3, char **p4);
void free_5(char *p1, char *p2, char *p3, char *p4, char **p5);
void check_slash(char *lineptr);
/*builtin functions */
int find_builtin(char *lineptr);
int builtExit(char *lineptr);
int builtEnv(void);
int builtCd(char *path);
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
