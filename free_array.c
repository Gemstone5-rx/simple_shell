#include "shell.h"

/**
 * free_array_of_strings - Function that frees array of string.
 * @array: the string should be freed.
 * Return: the string.
 */

void free_array_of_strings(char **array)
{
	char **as = array;

	while (*array)
	{
		free(*array);
		array++;
	}
	free(as);
}
