#include "main.h"
#include <sys/wait.h>

/**
* execmd - executed a command
* @argv: takes an array of strings typed by user on cli as input
*/

void execmd(char **argv)
{
	pid_t pid;
	char *cmd, *path, *full_cmd;

	pid = fork();
	if (pid == 0)
	{
	cmd = NULL;
	path = "/usr/bin/";

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
	exit(0);
	}
	else if (pid == -1)
		perror("fork");
	else
		wait(NULL);
}

