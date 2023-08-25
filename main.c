#include "shell.h"
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - simple entrance to the shell
 * @argv: list of arguments passed
 * @argc: length of the list of arguments passed
 * Return: 0 successful
 */
int main(int argc, char **argv) /* leave space for the env */
{
	char *line = NULL;
	size_t len = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		print("xshell$ ", NULL);
		while (getline(&line, &len, stdin) != -1)
		{
			line[_strcspn(line, "\n")] = '\0';
			printf("%s\n", line);
			look(line);
			print("xshell$ ", NULL);
		}
		if (getline(&line, &len, stdin) == -1)
			exit(0);
	}
	free(line);
	return (0);
}
