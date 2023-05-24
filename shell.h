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
char *my_getenv(const char *name);

size_t _strcspn(const char *str, const char *reject);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
size_t _strlen(const char *str);
void exit_shell(int status);

/*Execute Command*/
char *get_full_path(const char *command);
char *get_direct_path(const char *command);
char *search_in_path(const char *command);
char *build_full_path(const char *dir, const char *command);


#endif /* SHELL_H */

