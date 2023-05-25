#include "shell.h"

/**
 * removeLeadingSpaces - remove the leading space.
 * @str: the string.
 * Return: void.
 */

void remove_spaces(char *str)
{
	int i = 0;
	int j = 0;

	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}

	while (str[i] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}

	str[j] = '\0';
}
