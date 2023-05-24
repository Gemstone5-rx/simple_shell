#include "shell.h"

/**
 * get_full_path - Get the full path of a command
 * @command: Command to find the full path for
 *
 * Return: Full path of the command if found, NULL otherwise
 */
char *get_full_path(const char *command)
{
	char *full_path = NULL;

	if (command[0] == '/')
	{
		full_path = get_direct_path(command);
	}
	else
	{
		full_path = search_in_path(command);
	}

	return (full_path);
}

