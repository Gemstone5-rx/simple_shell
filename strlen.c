#include "shell.h"
/**
 * _strlen - Calculate the length of a string
 * @str: Pointer to the string
 *
 * Return: Length of the string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}
