#include "main.h"
#include <stdlib.h>
/**
 * _prompt - displays a prompt and executes the input
 * @argv: arguments passed in the shell
 * @environ: the environment
 * Return: nothing
 */
void _prompt(char **argv, char **environ)
{
	char *buffer = NULL, *delim = " ", *arg[ARGS] = {NULL};
	char *filepath = NULL;
	size_t n = 0;
	ssize_t chars_read; /*checks from the getline*/
	int exec_return, status, i;
	pid_t new_process; /*store the process id*/

	for (;;)/*To run the infinity loop*/
	{
		printf("shell  ");
		chars_read = getline(&buffer, &n, stdin);
		if (chars_read == -1)
		{
			perror("Error reading user input");
			free(buffer);
			exit(98);
		}
		buffer[_strlen(buffer) - 1] = '\0';
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
			printf("%s: %s command not found\n",argv[0], buffer);
			free(buffer);
			continue;
		}
		new_process = proc(); /*make a new process for execve*/
		if (new_process == 0)
		{
			exec_return = execve(filepath, arg, environ);
			if (exec_return == -1)
			{
				printf("Not a valid command %s\n", argv[1]);
				free(filepath);
				exit(EXIT_FAILURE);
			}
			free(filepath);
		}
		else
		{
			wait(&status);
		}
	}
	free(filepath);
}
