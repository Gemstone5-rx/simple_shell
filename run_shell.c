#include "shell.h"

/**
 * run_shell - Function to run the shell command
 *
 * Return: Nothing
*/

void run_shell(void)
{
	char *line = NULL, *args[MAX_ARGUMENTS + 1], *token = NULL;
	size_t line_size = 0;
	ssize_t read_size;
	int i;

	while (1)
	{
		printf("$ ");
		read_size = getline(&line, &line_size, stdin);
		if (read_size == -1)
		{
			printf("\n");
			break;
		}
		line[_strcspn(line, "\n")] = '\0';
		token = _strtok(line, " ");
		i = 0;
		while (token != NULL && i < MAX_ARGUMENTS)
		{
			args[i] = token;
			token = _strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			else if (_strcmp(args[0], "env") == 0)
				handle_env();
			execute_command(args[0], args);
		}
	}
	free(line);
}

