#include "shell.h"

/**
 * build_full_path - Build the full path of a command
 * using a directory and command name
 * @dir: Directory to prepend to the command name
 * @command: Command name
 *
 * Return: Full path of the command
 */
char *build_full_path(const char *dir, const char *command)
{
	char *full_path = malloc(strlen(dir) + strlen(command) + 2);

	if (!full_path)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	strcpy(full_path, dir);
	strcat(full_path, "/");
	strcat(full_path, command);

	return (full_path);
}

