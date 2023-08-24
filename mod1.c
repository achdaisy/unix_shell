#include "main.h"

/**
 * _prompt - displays a prompt and executes the input
 * @argv: list of input parameters
 * @environ: the environment
 *
 * Return: nothing
 */

void _prompt(char **argv, char **environ)
{
	char *buffer;
	size_t n = 0;
	ssize_t chars_read;
	int exec_return, status;
	char *arg[] = {NULL, NULL};
	pid_t new_process;

	for (;;)/*To run the infinity loop*/
	{
		printf("cisfun$ ");
		chars_read = getline(&buffer, &n, stdin);
		if (chars_read == -1)
		{
			perror("Error reading user input");
			free(buffer);
			exit(98);
		}
		if (chars_read > 0 && buffer[chars_read - 1] == '\n')
		{
			buffer[chars_read - 1] = '\0';
		}
		arg[0] = buffer;
		new_process = fork();
		if (new_process == -1)
		{
			perror("Error forking");
			exit(98);
		}
		if (new_process == 0)
		{
			exec_return = execve(arg[0], arg, environ);
			if (exec_return == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
		{
			wait(&status);
		}
	}
	free(buffer);
}


