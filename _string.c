#include "main.h"

/**
 * _strcpy - makes a copy of a string
 * @src: source string
 * Return: null-terminated string buffer (success), NULL (fail)
 */
char *_strcpy(char *src)
{
	unsigned int len;
	char *buf = NULL;

	if (src != NULL)
	{
		len = _strlen(src);
		buf = malloc(len);

		if (buf != NULL)
		{
			for (len = 0; src[len] != '\0'; ++len)
			{
				buf[len] = src[len];
			}
			buf[len] = '\0';
		}
	}

	return (buf);
}

/**
 * _strlen - returns the length of the string
 * @s: null-terminated character array
 * Return: int
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	if (s != NULL)
		while (s[len] != '\0')
		{
			len++;
		}

	return (len);
}

/**
 * _ndelim - returns the number of the string separated
 * by delimiter string
 * @str: null-terminated string
 * @delim: null-terminated delimiter string
 * Return: int
 */
unsigned int _ndelim(const char *str, const char *delim)
{
	const char *c;
	unsigned int len = 0, i;

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			for (c = delim; *c != '\0'; c++)
			{
				if (str[i] == *c)
				{
					++len;
				}
			}
		}
	}
	return (len);
}

/**
 * _nullify - add a NULL element to a buffer
 * The return values is a dynamically allocated memory heap space
 * Therefore, it should be freed by the calling program
 * @s: null-terminated string
 * Return: NULL terminated buffer (success), NULL (fail)
 */
char **_nullify(char *s)
{
	char **buf;

	buf = malloc(sizeof(char *) * 2);

	if (buf != NULL)
	{
		buf[0] = s;
		buf[1] = NULL;

		return (buf);
	}
	return (NULL);
}
