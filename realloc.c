#include "shell.h"

/**
 * _realloc - re-allocate the memory.
 * @ptr: the string needs to be re-allocated.
 * @size: the new size.
 * @old_size: the old size.
 * Return: void.
 */

void *_realloc(void *ptr, size_t size, size_t old_size)
{
	void *new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		ptr = malloc(size);
		return (ptr);
	}

	new_ptr = malloc(size);
	if (new_ptr != NULL)
	{
		_memset(new_ptr, 0, size);
		_memcpy(new_ptr, ptr, old_size);

		free(ptr);
	}

	return (new_ptr);
}
