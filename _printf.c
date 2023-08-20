#include "main.h"

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
	int i, len = 0;
	va_list argv;
	/**
	 * This is where the fun starts.
	 * We start by initiating a list of pointers to given arguments.
	 * Using while loop, we will be printing characters until
	 * we find our delimiter '%', execute the necessary and keep
	 * printing.
	 */
	va_start(argv, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++; /* Each time '%' is found, we skip the character */
			if (format[i] == '%')
				len += _putchar('%');
			else
				handle_specifier(format[i], &len, argv);
		}
		else
			len += _putchar(format[i]);
	}
	/* free our argv list of pointers */
	va_end(argv);
	return (len);
}
