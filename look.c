#include "main.h"
#include <stdlib.h>

/**
 * look - will check for path present if not will move to the next one
 * @cmd: the command passed
 * Return: an executable file
 */
char *look(char *cmd)
{
	static char *filepath;
	char *found = _strstr(cmd, "/bin/");

	if (found)
	{
		if (_check_path(found) == 0)
		{
			print_a_str(found, "\n", NULL);
			return (found);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		filepath = path(cmd);
		return (filepath);
	}
}
