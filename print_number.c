#include "main.h"
#include <unistd.h>

/**
 * print_number - Prints an integer
 * @args: The argument list containing the integer
 * Return: Number of characters printed
 */
int print_number(va_list args)
{
    int num = va_arg(args, int);
    char buffer[20];
    int i = 0, count = 0;
    unsigned int n;

    if (num < 0)
    {
        write(1, "-", 1);
        count++;
        n = -num;
    }
    else
        n = num;

    do {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    while (i--)
        count += write(1, &buffer[i], 1);

    return (count);
}
