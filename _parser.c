#include "main.h"

/**
 * parsecmd - parses cmd command line
 * @cmdline: null-terminated string of shell commands
 * @delim: null-terminated delimiter string
 * Return: tokenized array of commands (success), NULL(fail)
 */
char **parsecmd(char *cmdline, char *delim)
{
	char **cmd_arg;
	unsigned int narg = 0;
	int i;
	char *token;

	/* Get the number of delimited cmdline strings*/
	narg = _ndelim(cmdline, delim) + 1;
	/* Set a dynamic memory that fits the number of delimited strings*/
	cmd_arg = malloc(sizeof(char *) * narg);
	/*Set the last index of cmd_arg to NULL*/

	if (cmd_arg == NULL)
		return (NULL);

	i = 0;
	token = _strtok(cmdline, delim);
	/*Push each tokenized string into cmd_arg*/
	while (token != NULL)
	{
		cmd_arg[i++] = token;
		token = _strtok(NULL, delim);
	}

	return (cmd_arg);
}
