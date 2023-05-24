#include "shell.h"

/**
 * _strncmp - Compare two strings up to a given number of characters
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 * @n: Number of characters to compare
 *
 * Return:
 *   - 0 if the strings are equal up to the given number of characters
 *   - a negative value if the first differing
 *   character in s1 is less than s2
 *   - a positive value if the first differing character
 *   in s1 is greater than s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);

	while (*s1 && *s2 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

