#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * eXit - simple command to exit the shell
 * @buffer: arguments passed from the shell input
 * Return: 0 if successful
 */
int eXit(char *buffer)
{
	int stat;
	char *val1, *val2;

	if (!buffer)
	{
		return (1);
	}
	val1 = strtok(buffer, " ");
	val2 = strtok(NULL, " ");
	if (val1 && val2)
	{
		stat = _atoi(val2);
		if (!strcmp(val1, "exit"))
		{
			print_a_str("exited successfully\n", NULL);
			exit(stat);
		}
	}
	if (val1 && !val2)
	{
		if (!strcmp(val1, "exit"))
		{
			print_a_str("exited successfully\n", NULL);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
