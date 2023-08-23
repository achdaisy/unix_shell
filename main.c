#include "main.h"

/**
 * main - simple custom shell
 * @argc: number of arguments passed
 * @argv: array of arrays mostly commands
 * @environ: pointer to an array of arrays
 * Return: 0 successful
 */
int main(int argc, char *argv[], char *environ[])
{
	if (argc > 2)
	{
		perror("Unknown command\n");
		exit(98);
	}
	_prompt(argv, environ);
	return (0);

}
