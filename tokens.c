#include "shell.h"

/**
 * arr_of_tokens - copies the tokens into array of strings.
 * @command: the string should be divided into tokens.
 * @del: the separator.
 * Return: the array of strings..
 */

char **arr_of_tokens(char *command, char *del)
{
	char *token;
	size_t count = 0;
	char *command_cpy = NULL;
	char **arr_str;
	int i = 0;
	char *temp;

	count = _strlen(command) + 1;
	command_cpy = malloc(sizeof(char) * count);
	_strcpy(command_cpy, command);

	arr_str = malloc(sizeof(char *) * (num_of_tok(command, del) + 1));

	token = strtok(command_cpy, del);
	while (token)
	{
		temp = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(temp, token);
		arr_str[i] = temp;
		token = strtok(NULL, del);
		i++;
	}
	if (i == 0)
	{
		free(arr_str);
		free(command_cpy);
		return (NULL);
	}

	arr_str[i] = NULL;
	free(command_cpy);
	return (arr_str);
}

/**
 * string_array_cp - Function that copies the array of string.
 * @des: the string should be copied to.
 * @src: the string should be copied from.
 * Return: nothing
 */

void string_array_cp(char ***des, char **src)
{
	size_t cnt = 0;
	char **temp = src;
	size_t sub_string_len = 0, num = 0;
	int i = 0;

	while (*temp++)
		cnt++;

	cnt++;
	(*des) = malloc(sizeof(char *) * cnt);

	temp = src;
	while (*temp)
	{
		num = _strlen(*temp);
		sub_string_len = num + 1;
		(*des)[i] = malloc(sizeof(char) * sub_string_len);
		_strcpy((*des)[i], *temp);
		i++;
		temp++;
	}

	(*des)[i] = NULL;
}
