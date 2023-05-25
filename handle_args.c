#include "shell.h"

/**
 * handle_args - handles the argguments.
 * @m: the string.
 *
 * Return: description.
 */

int handle_args(memory *m)
{
	int i = 0;
	int j = 0;

	ArgsHandler h[] = {
	    {"#", handle_hash},
	    {"$$", handle_double_dollar},
	    {"$?", handle_double_mark},
	    {NULL, NULL}};

	while ((h + i)->name)
	{
		while (m->agv[j])
		{
			if (m->agv[j][0] == '#' && (h + i)->name[0] == '#')
			{
				(h + i)->handler(m, j);
			}
			else if (_strcmp((h + i)->name, m->agv[j]) == 0)
			{
				(h + i)->handler(m, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
