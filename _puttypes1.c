#include "_puttypes.h"

/**
 * putUnsignedInt - prints Unsigned Int
 * @number: Unsigned Int
 * Return: lenght of number
 */
int putUnsignedInt(unsigned int number)
{
	if (number < 10)
		return (_putchar(number + '0'));
	else
		return (putUnsignedInt(number / 10) + putUnsignedInt(number % 10));
}

/**
 * putOctal - prints unsigned integer as octal
 * @number: unsigned integer
 * Return: lenght of octal
*/
int putOctal(unsigned int number)
{
	char digits[20];
	int len = 0, i = 0;

	if (number == 0)
		return (_putchar('0'));
	while (number > 0)
	{
		digits[i++] = '0' + (number & 7);
		number = number >> 3;
	}

	while (i > 0)
		len += _putchar(_putchar(digits[--i]));

	return (len);
}

