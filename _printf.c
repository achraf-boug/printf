#include "main.h"

#define BUFFER_SIZE 1024

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

	if (check_format(format) == -1)
		return (-1);

	/*Let's get arguments using va_start*/
	va_start(argv, format);

	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		/*Using for loop, we print characters and handle specifiers*/
		if (buf_index > BUFFER_SIZE || format[i] != '\n')
		{
			buffer[buf_index] = '\0';
			_putstr(buffer);
			buf_index = 0;
		}
		/*while incrementing the lenght*/
		if (format[i] != '%')
		{
			/* Save elements in buffer*/
			buffer[buf_index++] = format[i];
			len++;
		}
		else
		{
			if (format[i + 1] != '\0')
			/* Making sure we are not at the end*/
				i++;

			handle_specifier(format[i], &len, argv);
		}
	}

	/* print remaining elements in Buffer */
	if (buf_index > 0)
	{
		buffer[buf_index] = '\0';
		_putstr(buffer);
	}

	va_end(argv);
	return (len);
}
