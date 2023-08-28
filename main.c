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
		print("($) ", NULL);
		while (getline(&line, &len, stdin) != -1)
		{
			if (isatty(STDIN_FILENO))
			{/* start interactive mode */
				line[_strcspn(line, "\n")] = '\0';
				look(line);
				print("($) ", NULL);
				continue;
			}
			else
			{/* start non-interactive mode */
				line[_strcspn(line, "\n")] = '\0';
				print(line, "\n", NULL);
				if (access(line, F_OK | X_OK) == 0)
					look(line);
				else
					continue;
			}
			break;
		}
		if (getline(&line, &len, stdin) == -1)
		{/* both fail exit */
			free(line);
			exit(EXIT_SUCCESS);
		}
	}
	free(line);
	return (0);
}
