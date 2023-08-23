#include "main.h"
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

	val1 = strtok(buffer, " ");
	val2 = strtok(NULL, " ");
	if (val1 && val2)
	{
		stat = _atoi(val2);
		if (!_strcmp(val1, "exit"))
		{
			fprintf(stdout, "bye!!\n");
			exit(stat);
			return (1);
		}
	}
	if (!val2)
	{
		if (!_strcmp(val1, "exit"))
		{
			fprintf(stdout, "bye!!\n");
			exit(EXIT_SUCCESS);
			return (1);
		}
	}
	return (0);
}
