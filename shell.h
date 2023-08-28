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
/*light colors*/
#define DKRED "\x1B[1;31m"
#define DKGRN "\x1B[1;32m"
#define DKYEL "\x1B[1;33m"
#define DKBLU "\x1B[1;34m"
#define DKMAG "\x1B[1;35m"
#define DKCYN "\x1B[1;36m"
#define DKWHT "\x1B[1;37m"
/*Dark colors*/
#define BRRED "\x1B[0;31m"
#define BRGRN "\x1B[0;32m"
#define BRYEL "\x1B[0;33m"
#define BRBLU "\x1B[0;34m"
#define BRMAG "\x1B[0;35m"
#define BRCYN "\x1B[0;36m"
#define BRWHT "\x1B[0;37m"

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
