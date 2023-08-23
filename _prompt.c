#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _prompt - displays a prompt and executes the input
 * @argv: list of arguments passed
 * @penviron: the environment
 * Return: nothing
 */
void _prompt(char **argv, char **penviron)
{
	char *buffer = NULL, *delim = " ", *arg[ARGS] = {NULL};
	char *filepath = NULL;
	size_t n = 0;
	ssize_t chars_read; /*checks from the getline*/
	int i;

	for (;;)/*To run the infinity loop*/
	{
		fprintf(stdout, "shell  ");
		chars_read = getline(&buffer, &n, stdin);
		if (chars_read == -1)
		{
			perror("Error reading user input");
			free(buffer);
			exit(98);
		}
		buffer[_strlen(buffer) - 1] = '\0';
		argv[0] = delim;
		arg[0] = strtok(buffer, delim); /*start tokenizing string*/
		i = 1;
		while (i < ARGS)
		{
			arg[i] = strtok(NULL, delim); /*keep track of all the options*/
			i++;
		}
		if (eXit(buffer))
		{
			free(buffer);
			break; /*Exit the loop*/
		} /*exit from the shell*/
		filepath = path(buffer); /*copy over the correct path*/
		if (!filepath)
		{
			printf("%s: %s command not found\n", argv[0], buffer);
			free(buffer);
			continue;
		}
		_exec(filepath, arg, penviron);
	}
	free(filepath);
}
