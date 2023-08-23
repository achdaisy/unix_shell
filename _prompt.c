#include "main.h"
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
	ssize_t chars_read; /*checks from the getline*/
	int i;

	for (;;)/*To run the infinity loop*/
	{
		print_a_str("shell  ", NULL);
		chars_read = getline(&buffer, &n, stdin);
		if (chars_read == -1)
		{
			free(buffer);
			exit(98);
		}
		buffer[_strlen(buffer) - 1] = '\0';
		buffer2 = _strdup(buffer);
		arg[0] = strtok(buffer, delim); /*start tokenizing string*/
		i = 1;
		while (i < ARGS)
		{
			arg[i] = strtok(NULL, delim); /*keep track of all the options*/
			i++;
		}
		if (eXit(buffer2))
		{
			free(buffer);
			free(buffer2);
			break; /*Exit the loop*/
		} /*exit from the shell*/
		filepath = path(buffer); /*copy over the correct path*/
		if (!filepath)
		{
			print_a_str(argv[0], " : ", buffer, " command not found\n", NULL);
			free(buffer);
			continue;
		}
		_exec(filepath, arg, penviron);
	}
	free(filepath);
}
