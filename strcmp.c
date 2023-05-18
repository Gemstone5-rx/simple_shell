#include "shell.h"

/**
 * _strcmp - Function that compare two strings
 * @s1: First pointer to string
 * @s2: Second pointer to string
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int i, result;

	i = 0;
	result = 0;

	while (result == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
			break;
		result = *(s1 + i) - *(s2 + i);
		i++;
	}

	return (result);
}
