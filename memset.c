#include "shell.h"

/**
 * _memset - fill a block of memory with a specific value.
 * @value: the value.
 * @num: number of bytes.
 * @ptr: the strings needs to be filled.
 * Return: a string.
 */

void *_memset(void *ptr, int value, size_t num)
{
	unsigned char *p = (unsigned char *)ptr;
	size_t i;
	unsigned char val = (unsigned char)value;

	for (i = 0; i < num; i++)
	{
		p[i] = val;
	}

	return (ptr);
}
