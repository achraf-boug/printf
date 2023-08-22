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
		len += _putchar(digits[--i]);

	return (len);
}

/**
 * putHexa - prints unsigned integer as Hexa
 * @number: unsigned integer
 * @isUpper: flag for %x or %X
 * Return: lenght of hexa
*/
int putHexa(unsigned int number, int isUpper)
{
	char digits[20];
	int len = 0, i = 0;
	int digit;

	if (number == 0)
		return (_putchar('0'));
	while (number > 0)
	{
		digit = number & 0xF;
		if (digit < 10)
			digits[i++] = '0' + digit;
		else
			digits[i++] = (isUpper ? 'A' : 'a') + (digit - 10);
		number = number >> 4;
	}

	while (i > 0)
		len += _putchar(digits[--i]);

	return (len);
}

/**
 * putPointer - prints pointer value as hexa
 * @pointer: address to be printed
 * Return: return lenght of address
 */
int putPointer(void *pointer)
{
	uintptr_t address = (uintptr_t) pointer;

	return (putHexa(address, 0));
}
