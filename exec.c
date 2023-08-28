#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
/**
 * Exec - will make a command execution
 * @cmd: custom struct
 * @buf: command passed
 * Retrun: void
 */
void Exec(shell *cmd, char *buf)
{
	pid_t proc = fork();
	int status;

	if (proc == 0)
	{
		if (execvp(cmd->argv[0], cmd->argv) < 0)
		{
			print(cmd->argv[0], "Command not found\n", DKWHT, NULL);
			free(buf);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
