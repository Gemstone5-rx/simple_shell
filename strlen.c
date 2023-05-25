#include "shell.h"
/**/
/**
 * _strlen - function that returns the length of a string.
 * @s: the string that should be measured.
 * Return: the length of string.
 */

size_t _strlen(char *s)
{
	size_t counter = 0;

	while (s[counter] != '\0')
	{
		counter++;
	}

	return (counter);
}
