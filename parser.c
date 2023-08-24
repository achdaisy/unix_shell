#include <linux/limits.h>
#include <stdlib.h>
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

	if (!c_path)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	path = _getenv("PATH");
	if (!path)
	{
		perror("Invalid path");
		free(c_path);
		return (NULL);
	}
	path_dup = _strdup(path);
	token = strtok(path_dup, ":");
	print_a_str(token, NULL);

	while (token)
	{
		_strcpy(c_path, token);
		_strcat(c_path, "/");
		_strcat(c_path, buffer);
		parsed_path = _strdup(c_path);
		if (!parsed_path)
		{
			perror("Failed");
			free(path_dup);
			free(c_path);
			return (NULL);
		}
		if ((_check_path(parsed_path) == 0))
		{
			free(path_dup);
			free(c_path);
			return (parsed_path);
		}
		free(parsed_path);
		token = strtok(NULL, ":");
	}
	free(path_dup);
	free(c_path);
	return (NULL);
}
