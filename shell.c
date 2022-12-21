#include "main.h"

/**
 * main - Main shell program
 * @ac: argument count
 * @av: argument list
 * Return: 0 (success), otherwise (fail)
 */
int main(int ac, char **av)
{
	size_t len, nread;
	char *prompt, *cmdline, path[BUFFER_SIZE], *program_path;
	char **cmd_arg = av;
	int wstatus, w;

	len = 0, nread = 0, prompt = "#cisfun$ ";
	init_sig_handler();
	do {
		if (nread > 0 && cmdline != NULL)
		{
			cmd_arg = parsecmd(cmdline, SPACE_STR);
			if (cmd_arg == NULL)
				panic(av[0], cmdline);
			if (strcmp("cd", cmd_arg[0]) == 0)
			{
				if (cmd_arg[1] != NULL)
					chdir(cmd_arg[1]);
				printf("%s", prompt);
				continue;
			}
			if (strcmp("exit", cmd_arg[0]) == 0)
			{ /* Exit and clean up if the exit command was entered */
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
		}
		w = wait(0);
		printf("%s", prompt);
	} while ((nread = _getline(&cmdline, &len, stdin)) != -1);
	exit(EXIT_SUCCESS);
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
void panic(char *prog, char *cmd)
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

	execve(cmd_arg[0], cmd_arg, env);
}
