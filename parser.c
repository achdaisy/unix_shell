#include "shell.h"
/**
 * parseBuiltin - checks the type of commands passed
 * @cmdline: list of argument passed
 * Return: enum value according to the command passed
 */
enum builtin_val parseBuiltin(shell *cmdline)
{
	if (!_strcmp(cmdline->argv[0], "exit"))
	{
		return (-EXIT);
	}
	else
	{
		return (NONE);
	}
}
/**
 * parser - tokenize the string of chars passed
 * @buf: list of arguments
 * @command: pointer to a struct
 * Return: int value later decide which command to execute
 */
int parser(char *buf, shell *command)
{
	static char local[MAXARGS]; /*same a argv */
	char delim[1] = " "; /*only the space as delimiter in our case */
	char *st_ptr = local; /* a copy as the same of argv */
	char *token, *endline;

	if (!buf)
		perror("Command line is NULL");
	/*copy over the content over the local declared variable st_ptr */
	(void) strncpy(st_ptr, buf, MAXARGS);
	endline = st_ptr + _strlen(st_ptr); /*point to the end of the string */
	command->argc = 0;/*setting the starting point */
	while (st_ptr < endline)
	{/*tokenizing process */
		/*skip all trailing white spaces */
		st_ptr = st_ptr + _strspn(st_ptr, delim);
		/*check if we have reached the end */
		if (st_ptr >= endline)
			break;
		/*update st_ptr */
		token = st_ptr + _strcspn(st_ptr, delim);
		/*tokenize st_ptr */
		*token = '\0';
		/*record and handle multiple arguments */
		command->argv[command->argc++] = st_ptr;
		/*check if we have reach MAXARGS */
		if (command->argc >= MAXARGS - 1)
			break;
		/*move the pointer to the next available char in the string */
		st_ptr = token + 1;
	}
	/*update the command list with a null terminator */
	command->argv[command->argc] = NULL;
	/*if nothing was passed */
	if (command->argc == 0)
		return (1);
	command->builtin = parseBuiltin(command); /* check which command was given */
	return (command->builtin); /*everything works out fine */
}
