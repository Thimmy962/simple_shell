#include "main.h"

/**
* execmd - executed a command
* @argv: takes an array of strings typed by user on cli as input
*/

void execmd(char **argv)
{
	char *cmd = NULL;
	char *path = "/usr/bin/";
	char *full_cmd;

	if (argv)
	{
		cmd = argv[0];
		full_cmd = malloc(strlen(cmd) + strlen(path) + 1);
		strcpy(full_cmd, path);
		strcat(full_cmd, cmd);
		if ((execve(full_cmd, argv,  NULL)) == -1)
			perror("Error:");
	}
	free(full_cmd);
}

