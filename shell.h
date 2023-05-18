#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
extern char **environ;

void execute_command(const char *command, char *args[]);
void handle_env(void);
void run_shell(void);

/*strtok Function*/
char *_strtok(char *str, const char *delimiters);

size_t _strcspn(const char *str, const char *reject);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);

#endif /* SHELL_H */
