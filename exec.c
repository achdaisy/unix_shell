#include "main.h"
#include <signal.h>
/**
 * _exec - will make a command execution
 * @filepath: correct file path of the executable file
 * @argv: command line arguments
 * @penviron: custom envrionment
 * Retrun: void
 */
void _exec(char *filepath, char **ar, char **penviron)
{
	pid_t new_proc = proc();
	int exec_return, status;

	if (new_proc == 0)
	{
		exec_return = execve(filepath, ar, penviron);
		if (exec_return == -1)
		{
			perror("exec_failed");
			free(filepath);
			exit(EXIT_FAILURE);
		}
		free(filepath);
	}
	else
	{
		wait(&status);
	}
	/*free(filepath);*/
}
