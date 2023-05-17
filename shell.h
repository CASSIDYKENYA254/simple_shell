#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
#include <fnctl.h>
#include "shell_macros.h"

typedef struct built_in { char *type; int (*func)(info_t *); built_in_table;
int run_command(info_t *, char **);
int _putchar(char);
int string_strcmp(char *, char *);
int string_strlen(char *);
int error_putsfd(cha *str, int fd);
int error_putchar(char);
int loop_cmd(char **);
int is_known_cmd(info_t *, char *);
int find_built_in(info_t *);
int run_command(info_t *, char **);
int free_block(void **);
int interactive(info_t *);
int is_delim(char, char *);
int _myhistory(info_t *);
int _myhelp(info_t *);
int _mycd(info_t *);
int _myexit(info_t *);
int _erratoi(char *);
int _atoi(char *);
int _isalpha(int);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int replace_string(char **, char *);
int replace_vars(info_t *);
int is_chain(info_t *, char *, size_t *);
int delete_node_at_index(list_t **, unsigned int);
int renumber_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int read_history(info_t *info);
int write_history(info_t *info);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);
int populate_env_list(info_t *);
int _myunsetenv(info_t *);
int _mysetenv(info_t *);
int _myenv(info_t *);
int _getline(info_t *, char **, size_t *);
int print_d(int, int);
int _myalias(info_t *);

char *copy_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
char **list_to_strings(list_t *);
char *get_history_file(info_t *info);
char **get_environ(info_t *);
char *getenv(info_t *, const char *);
char *convert_number(long int, int, int);
char *_memset(char *, char, unsigned int);
char **strtow2(char *, char);
char **strtow(char *, char *);
char *exit_strchr(char *, char);
char *exit_strncat(char *, char *, int);
char *exit_strncpy(char *, char *, int);
char *string_dupy(const char *);
char *string_cpy(char *, char *);
char *string_strcat(char *, char *);
char *string_prefix_equal(const char *, const char *);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
list_t *node_string_prefix_equal(list_t *, char *, char);

void check_chain(info_t *, char *, size_t *, size_t, size_t);
void free_list(list_t **);
void free_info(info_t *, int);
void set_info(info_t *, char **);
void clear_info(info_t *);
void sigintHandler(int);
void remove_comments(char *);
void print_error(info_t *, char *);
void *_realloc(void *, unsigned int, unsigned int);
void deallocate(char **);
void _puts(char *);
void error_puts(char *);
void fork_cmd(info_t *);
void find_cmd(info_t *);

size_t list_len(const list_t *);
size_t print_list_str(const list_t *);
size_t print_list(const list_t*);

ssize_t get_input(info_t *);
ssize_t read_buf(info_t *info, char *buf, size_t *len);
ssize_t get_node_index(list_t *, list_t *);
ssize_t input_buf(info_t *info, char **buf, size_t *len);

#endif


