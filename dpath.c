#include "shell.h"

/**
 * _strdup - Duplicate a string
 * @str: String to duplicate
 *
 * Return: Pointer to the newly allocated duplicated string,
 *         or NULL if insufficient memory is available
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	_strcpy(dup, str);

	return (dup);
}

/**
 * get_direct_path - Get the full path of a command specified with a slash
 * @command: Command to find the full path for
 *
 * Return: Full path of the command if found, NULL otherwise
 */
char *get_direct_path(const char *command)
{
	char *full_path = NULL;

	if (access(command, X_OK) == 0)
	{
		full_path = _strdup(command);
		if (!full_path)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("error");
	}

	return (full_path);
}

