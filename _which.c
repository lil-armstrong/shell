#include "main.h"

/**
 * _which - Searches the $PATH env for the existence of file directory
 * @pathname: executable file path
 * Return: directory path (success), NULL (fail)
 */
char *_which(char *pathname)
{
	char *env_paths, *segment, path[1024], *token;
	struct stat st;

	segment = path;

	/* Check if the current file exist */
	if (access(pathname, F_OK) == 0)
		return (pathname);

	env_paths = strdup(getenv("PATH"));

	if (env_paths == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		return (NULL);
	}

	token = strtok(env_paths, ":");

	while (token != NULL)
	{
		strcpy(segment, token);
		strcat(segment, "/");
		strcat(segment, pathname);

		if (access(path, F_OK) == 0)
		{
			free(env_paths);
			return (strdup(path));
		}
		token = strtok(NULL, ":");
	}

	free(env_paths);
	return (NULL);
}
