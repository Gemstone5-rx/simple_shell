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
		char *full_path = get_full_path(command);

		if (full_path)
		{
			if (execve(full_path, args, environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}

		free(full_path);
		exit(EXIT_FAILURE);
	}

	wait(NULL);
}

