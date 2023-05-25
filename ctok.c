#include "shell.h"

/**
 * num_of_tok - Function that counts the number of tokens.
 * @command: the string that should be divided into tokens.
 * @del: the delimeter for the token.
 * Return: the number of tokens.
 */

int num_of_tok(char *command, char *del)
{
	char *command_cpy = NULL;
	char *token;
	size_t cnt = 0;
	int m = 0, n = 0;

	while (command[n])
	{
		n++;
	}

	cnt = n + 1;
	command_cpy = malloc(sizeof(char) * cnt);
	_strcpy(command_cpy, command);
	token = strtok(command_cpy, del);
	while (token)
	{
		m++;
		token = strtok(NULL, del);
	}

	free(command_cpy);
	return (m);
}
