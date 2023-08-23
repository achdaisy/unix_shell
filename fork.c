#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * proc - creates a new process
 * Return: void
 */
int proc(void)
{
	int new_proc;

	new_proc = fork();

	if (new_proc == -1)
	{
		perror("Failed to create a new process");
		exit(EXIT_FAILURE);
	}
	return (new_proc);
}
