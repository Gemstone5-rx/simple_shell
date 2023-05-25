#include "shell.h"

/**
 * concat_string - Function that concatenates two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: A pointer to string or NULL if failed
 */
char *concat_string(char *str1, char *str2)
{
	char *concat = NULL;
	int len1 = 0, len2 = 0, i = 0, j = 0;
	int length;

	while (str1[len1])
	{
		len1++;
	}

	while (str2[len2])
	{
		len2++;
	}

	length = len1 + len2 + 1;
	concat = malloc(sizeof(char) * length);

	while (i < len1)
	{
		concat[i] = str1[i];
		i++;
	}
	while (j < len2)
	{
		concat[i] = str2[j];
		j++;
		i++;
	}
	concat[i] = '\0';

	return (concat);
}
