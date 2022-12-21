#include "main.h"

/**
 * _getline - Reads an entire line from stream
 * storing the address of the buffer containing the text into *lineptr
 * @line_ptr: NULL-terminated buffer
 * @n: size of line_ptr buffer
 * @stream: stream to read from
 * Return: length of read string
 */
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream)
{
	char c;
	size_t len = 0;

	if (*n == 0)
		*n = BUFFER_SIZE;

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (!len)
		{
			*line_ptr = malloc(sizeof(char) * (*n));

			if (*line_ptr == NULL)
			{
				return (-1);
			}
		}
		/*Reallocate buffer size*/
		if (len >= *n)
		{
			*n += BUFFER_SIZE;
			*line_ptr = realloc(*line_ptr, *n);
			if (*line_ptr == NULL)
			{
				return (-1);
			}
		}
		(*line_ptr)[len++] = (char)c;
	}

	if (c == EOF)
	{
		_exit(0);
	}

	if (len > 0)
		(*line_ptr)[len] = '\0';

	return (len);
}
