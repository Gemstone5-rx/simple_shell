#include "shell.h"

/**
 * execute_multi_command - execute the multi commands.
 * @m: a struct object.
 * Return: int.
 */

int execute_multi_command(memory *m)
{
	char **commands = arr_of_tokens(m->command, ";");
	char **s = commands;

	m->commands = commands;
	m->current_command = m->command;

	while (*s)
	{
		m->command_count++;
		s++;
	}
	s = commands;
	while (*s)
	{
		remove_spaces(*s);
		m->command = (*s);
		execute_commandV(m);
		s++;
	}
	m->command = m->current_command;
	free_array_of_strings(commands);

	return (0);
}
