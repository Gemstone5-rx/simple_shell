#include "shell.h"
/**
 * _strcpy - Copy a string
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src)
		*ptr++ = *src++;

	*ptr = '\0';

	return dest;
}

