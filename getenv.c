#include "shell.h"

/**
 * my_getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *my_getenv(const char *name)
{
	int i;

	if (name == NULL || _strlen(name) == 0)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], _strlen(name)) == 0 &&
				environ[i][_strlen(name)] == '=')
		{
			return (&(environ[i][_strlen(name) + 1]));
		}
	}

	return (NULL);
}

