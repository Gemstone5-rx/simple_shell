#include "shell.h"

/**
 * execute_command - Function to execute shell commands
 * @command: Pointer to command to execute
 * @args: Command argument to execute
 *
 * Return: Nothing
 */

void execute_command(const char *command, char *args[])
{
	if (fork() == 0)
	{
		char *path = getenv("PATH");
		char *dir;
		char full_path[MAX_PATH_LENGTH];
		int found = 0;

		dir = _strtok(path, ":");
		while (dir != NULL)
		{
			_strcpy(full_path, dir);
			_strcat(full_path, "/");
			_strcat(full_path, command);
			if (access(full_path, X_OK) == 0)
			{
				found = 1;
				break;
			}
			dir = _strtok(NULL, ":");
		}

		if (found)
		{
			if (execve(full_path, args, environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			printf("%s: command not found\n", command);
			exit(EXIT_FAILURE);
		}
	}
	wait(NULL);
}

