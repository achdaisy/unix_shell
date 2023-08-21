#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _check_path - checks if the path is valid
 * @path: paths of a file
 * Return: 0 if valid path found else -1
 */
int _check_path(char *path)
{
	static char *local_path;

	local_path = _strdup(path);

	if (access(local_path, F_OK | X_OK) == 0)
	{
		free(local_path);
		return (0);
	}
	else
	{
		/*printf("shell: can't execute the command %s\n", local_path);*/
		free(local_path);
		return (-1);
	}
}
