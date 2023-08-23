#include "main.h"

/**
 * main - simple custom shell
 * @argv: number of arguments passed
 * @argc: number of arguments passed
 * @penviron: pointer to an array of arrays
 * Return: 0 successful
 */
int main(int argc, char *argv[], char *penviron[])
{
	if (argc > 2)
	{
		perror("Unknown command\n");
		exit(98);
	}
	_prompt(argv, penviron);
	return (0);
}
