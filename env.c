#include "shell.h"

/**
 * _getenv - Function that divides the string into tokens.
 * @strg: Pointer to the string that should be divided.
 *
 * Return: string
 */

char *_getenv(char *strg)
{
	int i = 0;
	char *del = "=";
	char *token;
	char **temp = NULL;
	size_t sub_string = 0;
	char *str = NULL;

	string_array_cp(&temp, environ);
	while (temp[i])
	{
		token = strtok(temp[i], del);
		if (_strcmp(token, strg) == 0)
		{
			token = strtok(NULL, del);
			sub_string = _strlen(token) + 1;
			str = malloc(sizeof(char) * sub_string);
			_strcpy(str, token);
			break;
		}
		i++;
	}
	free_array_of_strings(temp);

	return (str);
}
