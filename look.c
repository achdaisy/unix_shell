#include "shell.h"
/**
 * look - solve all the issues of user input
 * @cmd: list of arguments passed
 * Return: void
 */
void look(char *cmd)
{
	int rt; /* which type of command was passed */
	shell xcmd; /* copy of the struct */


	rt = parser(cmd, &xcmd); /* handle path and argument passed */
	if (rt == -1)
		return; /* parser failed */

	if (xcmd.argv[0] == NULL)
		return; /* check if no arguments passed */
	if (xcmd.builtin == NONE)
	{
		Exec(&xcmd, cmd);
	}
	/* if builtin is equal to NONE a normal command */
	else
		Exit(cmd);
		/* runCheckcommand(&xcmd, cmd); */
}
/* avoid this at the moment */
/**
 * runCheckcommand - checks for all the invalid commands
 * @cmdline: pointer to the struct
 * @command: command passed values
 * Return: void
 */
void runCheckcommand(shell *cmdline, char *command)
{
	switch (cmdline->builtin)
	{
		case EXIT:
			Exit(command);
			break;
		default:
			perror("Unknown command\n");
			break;
	}
}
