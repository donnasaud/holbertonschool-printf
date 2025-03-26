#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - Prints a character.
 * @args: Argument list containing the character to print.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @args: Argument list containing the string to print.
 *
 * Return: Number of characters printed.
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int counter = 0;

    if (!str)
        str = "(null)";
    while (*str)
    {
        counter += write(1, str++, 1);
    }

    return (counter);
}

/**
 * print_number - Prints an integer (for d and i specifiers).
 * @args: Argument list containing the integer to print.
 *
 * Return: Number of characters printed.
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
 * _printf - Custom implementation of printf function.
 * @format: Format string containing the characters and specifiers.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, counter = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '\0')   
                return (-1);
            if (format[i + 1] == 'c')
                counter += print_char(args);
            else if (format[i + 1] == 's')
                counter += print_string(args);
            else if (format[i + 1] == 'd' || format[i + 1] == 'i')
                counter += print_number(args);
            else if (format[i + 1] == '%')
                counter += write(1, "%", 1);
            else
            {
                counter += write(1, "%", 1);
                counter += write(1, &format[i + 1], 1);
            }
            i++;
        }
        else
            counter += write(1, &format[i], 1);
    }

    va_end(args);
    return (counter);
}
