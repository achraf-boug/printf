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

	/*Let's get arguments using va_start*/
	va_start(argv, format);

	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		/*Using for loop, we print characters and handle specifiers*/
		/*while incrementing the lenght*/
		if (format[i] != '%')
			len += _putchar(format[i]);
		else
		{
			if (format[i + 1] != '\0')
			/* Making sure we are not at the end*/
				i++;

			handle_specifier(format[i], &len, argv);
		}
	}

	va_end(argv);
	return (len);
}
