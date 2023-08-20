#include "_puttypes.h"

/**
 * _putchar - prints a character
 * @c: character
 * Return: if null return 0, else 1
 */
int _putchar(char c)
{
	write(1, &c, 1);
	if (c == '\0')
		return (0);
	return (1);
}

/**
 * _putstr - prints a character
 * @str: string to print
 * Return: lenght of string
 */
int _putstr(char *str)
{
	int i;
	int len = 0;

	for (i = 0; str != NULL && str[i] != '\0'; i++)
		len += _putchar(str[i]);

	return (len);
}
