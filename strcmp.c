#include "shell.h"

/**
 * _strcmp - Function that compares two strings
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * Return: 0 on Success
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int l_of_s1 = _strlen(s1);
	int l_of_s2 = _strlen(s2);

	if (l_of_s1 != l_of_s2)
		return (-1);

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);

		i++;
	}
	return (0);
}
