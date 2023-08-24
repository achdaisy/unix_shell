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
	char *buffer = NULL, *buffer2 = NULL, *delim = " ", *arg[ARGS] = {NULL};
	char *filepath;
	size_t n = 0;
	int i;

	for (;;)/*To run the infinity loop*/
	{
		print_a_str("shell  ", NULL);
		if (getline(&buffer, &n, stdin) == -1)
		{
			perror("getline failed");
		}
		buffer[_strlen(buffer) - 1] = '\0';
		if (buffer)
		{
			buffer2 = _strdup(buffer);
			if (!buffer2)
			{
				free(buffer);
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
		}
		arg[0] = strtok(buffer, delim); /* start tokenizing string */
		i = 1;
		while (i < ARGS)
		{
			arg[i] = strtok(NULL, delim); /*keep track of all the options*/
			i++;
		}
		if (eXit(buffer2))
		{
			free(buffer2);
			free(buffer);
			break; /*Exit the loop*/
		} /*exit from the shell*/
		filepath = look(buffer); /*copy over the correct path*/
		if (!filepath)
		{
			print_a_str(argv[0], " : ", buffer, " command not found\n", NULL);
			continue;
		}
		_exec(filepath, arg, penviron);
		free(filepath);
	}
	free(buffer);
}
