#include "main.h"

/**
 * handle_format - Handles format specifiers
 * @format: The format character
 * @args: The argument list
 * Return: Number of characters printed
 */
int handle_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(args));
	else if (format == 's')
		return (print_string(args));
	else if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (format == 'd' || format == 'i')
		return (print_number(args));
	{
		write(1, "%", 1);
		write(1, &format, 1);
		return (2);
	}
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			count += handle_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
