#include "shell.h"

/**
 * _strcpy - Function that copies string from one pointer to another.
 *
 * @s1: Pointer to the string should be copied to.
 * @s2: Pointer to the string should be copied from.
 * Return: the new string.
 */

char *_strcpy(char *s1, char *s2)
{
	size_t i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';

	return (s1);
}
