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

/*global var*/
extern char **environ;

/* prototypes */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv);
void print_prompt(void);
char **read_cmd(char **lineptr);
int check_space(char *lineptr);
char *split_cmd(char *lineptr);
int check_cmd_avi(char *cmd);
void make_fork(char *cmd);
int _strcmp(char *lineptr, char *str);
#endif
