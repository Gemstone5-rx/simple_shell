#include "shell.h"

/**
 * _strncpy_size - Function that copy string.
 * @dest: the string to be copied to.
 * @src: the string to be copied from.
 * @num: the length of the string.
 * Return: dest.
 */

char *_strncpy_size(char *dest, const char *src, size_t num)
{
	size_t i;

	for (i = 0; i < num && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < num; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
