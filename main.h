#ifndef MY_MAIN_FILE
#define MY_MAIN_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdarg.h>
#include <limits.h> /*Maximum length of path*/

/*custom Macros*/
#define ARGS 5
/*function prototypes*/
void _prompt(char **argv, char **environ);
char *path(char *buffer);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *s);
char *_strdup(const char *str);
char *_strcat(char *s, const char *ap);
char *_strcpy(char *copy, char *original);
int _atoi(char *s);
int proc(void);
int eXit(char *buffer);
int _check_path(char *path);
void _exec(char *filepath, char **argv, char **environ);
char *_getenv(char *string);
ssize_t print_a_str(const char *buff, ...);
int print_a_char(char a);
#endif
