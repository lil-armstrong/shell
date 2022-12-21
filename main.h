#ifndef MAIN_H
#define MAIN_H

#include <errno.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define ON 1
#define OFF 0
#define BUFFER_SIZE 1024
#define TESTING 1
#define DIR_L -1
#define DIR_C 0
#define DIR_R 1
#define _CRTDBG_MAP_ALLOC
#define PROMPT "#cisfun$ "
#define SPACE_STR " "
#define PIPE_STR "|"

extern char **environ;

/* _getline */
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream);
void print_prompt(void);

/* _strtok */
char *_strtok(char *str, const char *delim);
char *_stripstr(const char *str, const char *delim);

/* _string */
unsigned int _strlen(char *s);
unsigned int _ndelim(const char *s, const char *delim);
int str_join(int dir, char *dest, ...);
char *_strcpy(char *src);
char **_nullify(char *argv);

/* _which */
char *_which(char *path);

/* shell */
void runcmd(char **cmd_arg);
char **parsecmd(char *cmdline, char *delim);
void panic(char *pg, char *s);
int fork1(char *pg);
int process_input(char **av, char **cmd_arg, char *cmdline);

/* sign_handler */
void signal_handler(int signo);
void init_sig_handler(void);

#endif
