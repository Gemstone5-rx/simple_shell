#include "shell.h"

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
		full_path = strdup(command);
		if (!full_path)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("%s: command not found\n", command);
	}

	return (full_path);
}

