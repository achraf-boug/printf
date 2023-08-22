#include "_puttypes.h"
/**
 * convertSpecialChar - converts special chars to hexa and prints
 * @str: string
 * Return: lenght of string
 */
int convertSpecialChar(char *str)
{
        int i = 0, len = 0, elem;

        while (str[i] != '\0')
        {
                elem = (unsigned int) str[i++];
                if (elem < 32 || elem >= 127)
                {
                        len += _putchar('\\');
                        len += _putchar('x');
                        len += putHexa(elem, 1);
                }
                else
                        len += _putchar(elem);
        }
        return (len);
}
