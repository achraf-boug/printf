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
	 * len: calculating output lenght
	 * argv: getting arguments
	 */
	int i = 0; 
	int len = 0;
	va_list argv;

	/* if format is NULL, no need to run the code.*/
	if (format == NULL)
		return (len);

	/**
	 * This is where the fun starts.
	 * We start by initiating a list of pointers to given arguments.
	 * Using while loop, we will be printing characters until
	 * we find our delimiter '%', execute the necessary and keep
	 * printing.
	 */
	va_start(argv, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			/**
			 * Each time '%' is found, we skip the character => i++
			 */
			i++;
			switch (format[i])
			{
				case ('c'):
					// print character and increment lenght
					len += _putchar(va_arg(argv, int));
					break;
				case ('s'):
					// print strings and increment lenght
					len += _putstr(va_arg(argv, char *);
					break;
				case ('%'):
					// if a second '%' found, we print it as it is
					len += _putchar('%');
					break;
				default:
					// if anything else, do nothing
					break;
			}
		}
		else
			len += _putchar(format[i]);
		i++;
	}
	// free our argv list of pointers
	va_end(argv);
	return (len);
}
