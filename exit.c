#include "main.h"
#include <stdlib.h>
/**
 * eXit - simple command to exit the shell
 * @buffer: arguments passed from the shell input
 * Return: 0 if successful
 */
int  eXit(const char *buffer)
{
	if (!strcmp(buffer, "exit"))
	{
		printf("Bye!!\n");
		exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
}
