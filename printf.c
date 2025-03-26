#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_number - Prints an integer
 * @args: The argument list containing the integer to print
 *
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

/**
 * _printf - Custom printf function
 * @format: The format string containing the characters and specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '\0')
                return (-1);
            if (format[i + 1] == 'd' || format[i + 1] == 'i')
                count += print_number(args);
            else
            {
                count += write(1, "%", 1);
                count += write(1, &format[i + 1], 1);
            }
            i++;
        }
        else
            count += write(1, &format[i], 1);
    }

    va_end(args);
    return (count);
}
