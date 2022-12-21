#include "main.h"

/**
 * main - Main shell program
 * @ac: argument count
 * @av: argument list
 * Return: 0 (success), otherwise (fail)
 */
int main(__attribute__((unused)) int ac, char **av)
{
	size_t len;
	char *cmdline;
	char **cmd_arg = av;
	int nread;

	len = 0, nread = 0;
	init_sig_handler();
	do {
		if (nread > 0 && cmdline != NULL)
		{
			cmd_arg = parsecmd(cmdline, SPACE_STR);
			if (process_input(av, cmd_arg, cmdline) == -1)
			{
				print_prompt();
				continue;
			}
		}
		wait(0);
		print_prompt();
	} while ((nread = _getline(&cmdline, &len, stdin)) != -1);
	exit(EXIT_SUCCESS);
}

/**
 * process_input - Processes the command line input
 * @av: program argument list
 * @cmd_arg: custom commandline argument list
 * @cmdline: commandline null-terminated string
 * Return: 1 (success), -1 (fail)
 */
int process_input(char **av, char **cmd_arg, char *cmdline)
{
	char **env = environ;
	int i;

	if (cmd_arg == NULL)
		panic(av[0], cmdline);
	if (strcmp("cd", cmd_arg[0]) == 0)
	{
		if (cmd_arg[1] != NULL)
			chdir(cmd_arg[1]);
		return (-1);
	}

	if (strcmp("env", cmd_arg[0]) == 0)
	{
		i = 0;
		while (*(env + i) != NULL)
			printf("%s\n", *(env + i++));
		return (-1);
	}

	if (strcmp("exit", cmd_arg[0]) == 0)
	{
		free(cmd_arg), free(cmdline);
		exit(EXIT_SUCCESS);
	}

	if (fork1(av[0]) == 0)
	{
		cmd_arg[0] = _which(cmd_arg[0]);
		if (cmd_arg[0] != NULL)
			runcmd(cmd_arg);
		panic(av[0], cmd_arg[0]);
	}
	free(cmd_arg);
	if (cmdline != NULL)
		free(cmdline);

	return (1);
}


/**
 * fork1 - forks a new child process
 * @pg: parent program
 * Return: pid (success), exit (fail)
 */
int fork1(char *pg)
{
	pid_t pid = fork();

	if (pid == -1)
		panic(pg, "fork");

	return (pid);
}

/**
 * panic - displays an error message and exits the program
 * @prog: Program name
 * @cmd: null-terminated command string
 */
void panic(char *prog, __attribute__((unused)) char *cmd)
{
	fprintf(stderr, "%s: %s\n", prog, strerror(errno));
	exit(1);
}

/**
 * runcmd - Runs a shell command
 * @cmd_arg: NULL-terminated array of pointers to char
 * Return: void
 */
void runcmd(char **cmd_arg)
{
	char **env = environ;
	char *args[2];

	args[0] = cmd_arg[0],
	args[1] = NULL;

	execve(cmd_arg[0], args, env);
}
