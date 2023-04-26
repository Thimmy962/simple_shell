#include "main.h"

/**
* main - the main function for this project
* @argc: number of cli arguments
* @argv: the cli arguments
* Return: int
*/

int main(int argc, char **argv)
{
	char *token, *pro = "$", *buff, *buff_copy = NULL;
	const char *delim = " ";
	size_t no = 0;
	ssize_t exit;
	int num, i;

	(void)argc;
	while (2)
	{
	printf("%s  ", pro);
	exit = getline(&buff, &no, stdin);
	if (exit_shell(exit, buff) == -1)
	{
		return (-1);
	}
		buff_copy = malloc(sizeof(char) * exit);
		if (buff_copy == NULL)
			return (-1);
		strcpy(buff_copy, buff);
		token = strtok(buff_copy, delim);
		num = token_num(token, delim);
		argv = malloc(sizeof(char *) * num);
		token = strtok(buff, delim);
		for (i = 0; token != NULL; i++)
		{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
		free(argv);
		free(buff_copy);
	}
return (0);
}

/**
* exit_shell - exits the shell
* @exit: an int exit
* @buff: what the user typed in the cli
* Return: an int
*/

int exit_shell(ssize_t exit, char *buff)
{
	if (exit == -1 || strcmp(buff, "exit\n") == 0)
	{
		free(buff);
		return (-1);
	}
return (0);
}

/**
* token_num - the number of token
* @token: the string token passed as an input
* @delim: stands for delimiter that marks the end of a string in a token
* Return: an int
*/
int token_num(char *token, const char *delim)
{
	int number = 0;

	while (token != NULL)
	{
		number++;
		token = strtok(NULL, delim);
	}
return (number++);
}

