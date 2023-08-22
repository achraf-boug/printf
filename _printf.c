#include "main.h"

/**
 * check_format - checks format for unhandled cases
 * @format: string
 * Return: 0 if OK, -1 if KO
 */
int check_format(const char *format)
{
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	return (0);
}

/**
 * flush_buffer - flush the buffer from its content
 * @buffer: list of char
 * @buf_index: index of last element
 * @format : output string
 * @i: index of format
 * Return: if done return 1, else 0
 */
int flush_buffer(char *buffer, int *buf_index, const char *format, int *i)
{
	if (*buf_index > BUFFER_SIZE || format[*i + 1] != '\0')
	{
		buffer[*buf_index] = '\0';
		_putstr(buffer, 0);
		*buf_index = 0;
		(*i)++;
		return (1);
	}
	return (0);
}

/**
 * _printf - function that produces output according to a format
 * @format: string to be printed
 * Return: output lenght
 */

int _printf(const char *format, ...)
{
	/**
	 * i: indexing elements of format
	 * len: calculating the lenght of final output
	 * argv: getting arguments
	 */
	int i, len = 0, buf_index = 0;
	va_list argv;
	char buffer[BUFFER_SIZE];

	if (check_format(format) == -1) return (-1);

	/*Let's get arguments using va_start*/
	va_start(argv, format);

	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		/*Using for loop, we print characters and handle specifiers*/
		/*while incrementing the lenght*/
		if (format[i] != '%')
		{
			/* Save elements in buffer*/
			buffer[buf_index++] = format[i];
			len++;
			flush_buffer(buffer, &buf_index, format, &i);
		}
		else
		{
			if (!flush_buffer(buffer, &buf_index, format, &i))
			{
				i++;
				handle_specifier(format[i], &len, argv);
			}
		}
	}

	/* print remaining elements in Buffer */
	flush_buffer(buffer, &buf_index, format, &i);

	va_end(argv);
	return (len);
}
