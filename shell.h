#ifndef SHELL_H
#define SHELL_H

/* Defined Library */
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* for the mean time */
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdarg.h>
#include <limits.h> /*Maximum length of path*/
#include <stdarg.h>

/* Define Macros */
#define MAXARGS 100

/* Struct */
typedef struct command
{
	int argc; /*argument count */
	char *argv[MAXARGS]; /*command line argument */
	enum builtin_val /*flags for which command to execute */
	{
		NONE,
		EXIT = -1
	}builtin;
}shell;

/* Define Prototypes */
void look(char *); /* handling NULL commands */
void Exec(shell *cmdline, char *cmd);
void *MALLOC_CHECK(void *ptr); /* check for malloc allocation */
int parser(char *buf, shell *cmdline);
int Exit(char *cmd); /* responsible for exit command */
void runCheckcommand(shell *cmdline, char *);
/*enum builtin_val parseBuiltin(shell *cmdline);*/

/* Strings functions */
size_t _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *copy, const char *original);
int _atoi(char *str);
int _putchar(char x);
ssize_t print(const char *buf, ...);
unsigned int _strspn(char *s, char *accept);
unsigned int _strcspn(char *s, char *rejects);
char *_strtok(char *s, char *delim);


#endif
