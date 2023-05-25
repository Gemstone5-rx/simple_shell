#include "shell.h"

/**
 * write_char - Function that returns a written string.
 * @fd: the number of lines.
 * @buffer: the string.
 * @length: the number of characters.
 * Return: a string..
 */

int write_char(int fd, const char *buffer, size_t length)
{
	return (write(fd, buffer, length));
}
