#include "shell.h"
/**
 * Exit - exits the shell
 * @buffer: pointer to a sturct
 * Return: an arguments passed or 0 for success
 */
int Exit(char *buffer)
{
	int stat;
	char *val1, *val2;

	if (!buffer)
		perror("error making a copy");
	val1 = _strtok(buffer, " ");
	val2 = _strtok(NULL, " ");
	if (val1 && val2)
	{
		stat = _atoi(val2);
		if (!_strcmp(val1, "exit"))
		{
			/*print("Exited successfully\n", NULL);*/
			free(buffer); /* which was allocated by getline */
			exit(stat);
		}
	}
	if (val1 && !val2)
	{
		if (!_strcmp(val1, "exit"))
		{
			print("Exited successfully\n", NULL);
			free(buffer); /* which was allocated by getline */
			exit(EXIT_SUCCESS);
		}
	}
	return (-1);
}
