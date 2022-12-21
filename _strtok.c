/*_strtok.c*/

#include "main.h"

/**
 * _strtok - splits a string using a delimiter string
 * @str: null-terminated string
 * @delim: delimiter string
 * Return: Array of split string (success), NULL (fail)
 */
char *_strtok(char *str, const char *delim)
{
	static char *input;
	char *output = NULL;
	char *p;

	if (str != NULL)
	{
		input = str;
	}

	if (input != NULL)
		output = input;

	p = _stripstr(input, delim);

	if (p != NULL)
	{
		*p = '\0';
		input = p + 1;
	}
	else
	{
		input = NULL;
	}

	return (output);
}

/**
 * _stripstr - returns next string after delimiter string
 * @str: null-terminated string
 * @delim: delimiter string
 * Return: pointer position of next string (success), NULL (fail)
 */
char *_stripstr(const char *str, const char *delim)
{
	const char *c;

	if (str != NULL)
	{
		for (; *str != '\0'; str++)
		{
			for (c = delim; *c != '\0'; c++)
			{
				if (*str == *c)
				{
					return ((char *)str);
				}
			}
		}
	}
	return (NULL);
}
