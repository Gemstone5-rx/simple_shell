#include "shell.h"

/**
 * search_in_path - Search for a command in the PATH environment variable
 * @command: Command to find the full path for
 *
 * Return: Full path of the command if found, NULL otherwise
 */
char *search_in_path(const char *command)
{
	char *path = my_getenv("PATH");
	char *dir;
	char *full_path = NULL;
	int found = 0;

	dir = _strtok(path, ":");
	while (dir != NULL)
	{
		full_path = build_full_path(dir, command);
		if (access(full_path, X_OK) == 0)
		{
			found = 1;
			break;
		}
		free(full_path);
		dir = _strtok(NULL, ":");
	}

	if (!found)
	{
		printf("%s: command not found\n", command);
		free(full_path);
		full_path = NULL;
	}

	return (full_path);
}

