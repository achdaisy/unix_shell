#include "main.h"
/**
 * _prompt - displays a prompt and executes the input
 * @argv: list of input parameters
 * @environ: the environment
 *
 * Return: nothing */ void _prompt(char **argv, char **environ)
{
	char *buffer, *buffer2, *filepath, *delim = " ";
	size_t n = 0;
	int exec_return, status, i = 0;
	char *arg[] = {NULL, NULL};
	pid_t new_process;

	for (;;)/*To run the infinity loop*/
	{
		printf("cisfun$ ");
		if (getline(&buffer, &n, stdin) == -1)
			perror("getline failed");
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
		while (i < ARGS && arg[i - 1] == NULL)
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
			free(buffer2);
			continue;
		}
		new_process = proc();
		if (new_process == -1)
		{
			perror("Error forking");
			exit(98);
		}
		if (new_process == 0)
		{
			exec_return = execve(filepath, arg, environ);
			if (exec_return == -1)
			{
				printf("%s: No such file or directory\n", filepath);
				free(filepath);
			}
			free(filepath);
		}
		else
		{
			wait(&status);
		}
		free(filepath);
		free(buffer2);
	}
	free(buffer);
}
