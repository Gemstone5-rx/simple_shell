#include "shell.h"

/**
 * _strtok - Function that breaks a string to tokens
 * @str: Pointer to the string to be tokenized
 * @delimiters: The delimeter Character
 *
 * Return: A pointer
*/

char *_strtok(char *str, const char *delimiters)
{
	static char *next_token;
	char *token_start;
	int token_len = 0, i;
	int delim_len = strlen(delimiters);

	if (str != NULL)
	{
		next_token = str;
	}
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	token_start = next_token;

	while (*next_token != '\0')
	{
		int is_delim = 0;

		for (i = 0; i < delim_len; i++)
		{
			if (*next_token == delimiters[i])
			{
				is_delim = 1;
				break;
			}
		}

		if (is_delim)
		{
			*next_token = '\0';
			next_token++;
			break;
		}
		next_token++;
		token_len++;
	}
	return (token_start);
}

