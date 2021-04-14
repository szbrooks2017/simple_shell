![](https://cdn.nikospapagiannopoulos.com/wp-content/uploads/2008/01/linux-shell-command-line.jpg)
# Simple Shell Project
## Introduction
#### 	As students of Holberton School. This Simple Shell Project is the final project of the first trimester of the first year. The goal of this project is to utilizing the skills we have learned over the last 3 months regarding Linux-shell and C language. The simple shell will be coded by language C and student should have a deep understanding about how the shell parse, execute the command and display the information the users need. At the same time, knowing how the files and streams could be reached in a shell.
## The main concepts in C language used in this project
**- Loop**
- 	for loop
- 	while loop
- 	do...while loop
**- Array**
- 	Array of pointers
**- Pointers**
- 	pointers of string (char *)
- 	pointers of pointers (char **)
- 	function pointers
**- File I/O**
- 	POSIX standard
**- Memory manipulation**
- 	Malloc()
- 	Free()
## The functions from C standard library used
- chdir (man 2 chdir)
- execve (man 2 execve)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- malloc (man 3 malloc)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- write (man 2 write)
## The fuctions/prototypes we created for this project
- void print_prompt(void);
- char ***read_cmd(char **lineptr);
- int check_space(char *lineptr);
- char *split_cmd(char *lineptr);
- int check_cmd_avi(char *cmd);
- void make_fork(char *cmd);
- char *deal_with_path(char *lineptr);
- char *_getenv(char *name);
- char *_strcat_w_slash(char *a, char *b);
- void signal_id(int sig);
- int find_builtin(char *lineptr);
- int builtExit(char *lineptr);
- int builtEnv(void);
- int builtCd(char *path);
- int _strcmp(char *lineptr, char *str);
- int _strlen(char *s);
- char *_strdup(char *str);
- size_t _strspn(char *s1, const char *s2);
- size_t _strcspn(char *s1, const char *s2);
- char *_strtok(char *s1, const char *s2);
- int _strncmp(char *s1, char *s2, size_t n);
## Launch
#### This project is created under ubuntu ver.14.04 and gcc as the compiler
#### The gcc command is:
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell`         
	`$ ./shell`
## Examples of use
#### For runing the programe:
- 	Interactive mode

	`cisfun# ls -l /tmp`         
#### The terminal will return "no command is found" if so.
- 	Non-interactive mode      
	`$ echo "ls -l /tmp" | ./shell`       
#### The terminal will not print the prompt and exit after runing this line.
- 	builtin functions       
	`cisfun# env`         
	`cisfun# exit`
## Sources:
- https://brennan.io/2015/01/16/write-a-shell-in-c/
- https://github.com/kamalmarhubi/shell-workshop
- https://danishpraka.sh/2018/01/15/write-a-shell.html
- https://cs.wellesley.edu/~cs240/f15/assignments/shell/shell.html
- https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
- http://cs.brown.edu/courses/cs033/shell1/
- https://github.com/tokenrove/build-your-own-shell
- https://nickolasteixeira.medium.com/want-to-build-a-simple-shell-heres-how-you-do-it-75890647bae8
- https://www.cs.cornell.edu/courses/cs414/2004su/homework/shell/shell.html

## Authors
- Stratton Brooks Github ID: szbrooks2017
- Simon Sun Github ID: ssun97
## Especially thanks our turiors who provided us great help on the project
- Carlos Esquievl
- Aleia Mcnaney Devore


