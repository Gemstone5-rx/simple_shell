#ifndef _SHELL_
#define _SHELL_

#include <limits.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>

#define INITIAL_BUFFER_SIZE 100
#define STR_SIZE 2

extern char **environ;

/**
 * struct DynamicString - contains dynamic strings and functions
 * @str:pointer to character
 * @len:size_t variable
 * @capacity:size_t variable
 * @append_char: a function that appends character
 * @append_string: a function that appends string
 * @free: a function that sets the string to free
 * @clear: a function that clears the memory.
 */
typedef struct DynamicString
{
	char *str;
	size_t len;
	size_t capacity;

	void (*append_char)(struct DynamicString *, char);
	void (*append_string)(struct DynamicString *, const char *);
	void (*free)(struct DynamicString *);
	void (*clear)(struct DynamicString *);
} DynamicString;

/**
 * struct memory - a struct representing a change in memory
 *
 * @command: a pointer string representing the name of the command
 * @agv: a string pointer represents the arguments
 * @env: a string pointer represents the arguments
 * @command_number: an integer
 * @program_args: a string for arguments
 * @program_arg_count: an integer that counts the args.
 * struct built_in - a struct representing a built_in function
 * @builtIn: a built_in struct
 * @current_process_id: represents the pid
 * @last_exit_code: represents the exit code.
 * @current_status_code: represents the exit code.
 * @current_command: the current command.
 * @command_count: the command count.
 * @commands: the command.
 */
typedef struct memory
{
	char *command;
	char *current_command;
	int command_count;
	char **agv;
	char **commands;
	int command_number;
	int current_status_code;
	char **program_args;
	char **env;
	int program_arg_count;
	struct built_in *builtIn;
	pid_t current_process_id;
	int last_exit_code;
} memory;

/**
 * struct built_in - a struct representing a built-in command
 *
 * @command: a string representing the name of the command
 * @handler: a function pointer to the handler function for the command
 */

typedef struct built_in
{
	char *command;
	void (*handler)(struct memory *m);
} built_in;

/**
 * struct ArgsHandler - a struct representing arguments handlers
 * @name: name of the argument
 * struct handler - a struct representing arguments
 * @handler: a function pointer to the handler function for the     command
 */
typedef struct ArgsHandler
{
	char *name;
	void (*handler)(struct memory *m, int i);
} ArgsHandler;

/**shell_helpers**/
int num_of_tok(char *command, char *del);
char **arr_of_tokens(char *command, char *del);
void string_array_cp(char ***des, char **src);
void int_to_string(int number, char *str);

void append_string(DynamicString *ds, const char *str);
void append_char(DynamicString *ds, char ch);
void free_ds(DynamicString *ds);
void clear(DynamicString *ds);
void init_dynamic_string(DynamicString *ds, char *init);

/*error handler*/
void print_string(char *s);
void print_array_of_strings(char **s);

/*Strings and arrays*/
int write_char(int fd, const char *buffer, size_t length);
void free_array_of_strings(char **array);
char *concat_string(char *str1, char *str2);

char *_getenv(char *strg);

int execute_commandV(memory *m);
int handle_built_in(struct memory *m);
int handle_args(memory *m);

void sigintHandler(int signal);
int check_command_exit(char **args);
int check_built_ins(char **args);

/*String Helpers*/
size_t _strlen(char *s);
char *_strcpy(char *m, char *n);
int _strcmp(char *s1, char *s2);
char *_strncpy_size(char *dest, const char *src, size_t num);
int _atoi_with_error(char *s);

/*Memory Handlers*/
void _memcpy(void *destination, void *src, size_t number_of_bytes);
void *_memset(void *ptr, int value, size_t num);
void *_realloc(void *ptr, size_t size, size_t old_size);

void handle_hash(struct memory *m, int i);
void handle_double_dollar(struct memory *m, int i);
void handle_double_mark(struct memory *m, int i);

/**handle_build_in**/
void handle_exit(struct memory *m);
void handle_env(struct memory *m);

/**_getline.c**/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
size_t get(char *buf, char **lineptr, size_t *n, size_t buf_s, FILE *stream);

/**multi_commands**/
void remove_spaces(char *str);
int execute_multi_command(memory *m);

#endif
