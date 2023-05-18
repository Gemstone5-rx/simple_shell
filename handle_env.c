#include "shell.h"

/**
 * handle_env - Function to print environment variable
 *
 * Return: Nothing
*/

void handle_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
