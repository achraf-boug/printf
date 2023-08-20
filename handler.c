#include "main.h"

/**
 * handle_specifier - execute put function according to specifier
 * @specifier: specifies which put function to use
 * @len: increment the argument lenght into the initial output
 * @argv: get argument from _printf
 * Return: void
 */

void handle_specifier(char specifier, int *len, va_list argv)
{
	if (specifier == 'c')
		(*len) += _putchar(va_arg(argv, int));
	else if (specifier == 's')
		(*len) += _putstr(va_arg(argv, char *));
	else if (specifier == 'd' || specifier == 'i')
		(*len) += _putint(va_arg(argv, int));
	else
		(*len) += _putchar(specifier);
}
