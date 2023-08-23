#include <iso646.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * path - checks for the corresponding path to the variable.
 * @buffer: the argument passed
 * Return: void
 */
char *path(char *buffer)
{
	char *path, *parsed_path = NULL, *token, *path_dup;
	char *c_path = malloc(PATH_MAX);/* allocate memory according to Path length*/

	path = _getenv("PATH");
	if (!path)
	{
		perror("Invalid path");
		exit(EXIT_FAILURE);
	}
	path_dup = _strdup(path);
	if (!path_dup)
	{
		perror("Error while making a duplicate");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_dup, ":");

	while (token)
	{
		if (!c_path)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		_strcpy(c_path, token);
		_strcat(c_path, "/");
		_strcat(c_path, buffer);
		parsed_path = _strdup(c_path);
		if (parsed_path && (_check_path(parsed_path) == 0))
		{
			return (parsed_path);
		}
		token = strtok(NULL, ":");
	}
	free(path_dup);
	return (NULL);
}
