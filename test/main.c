#include "main.h"

int main(void)
{
	_printf("Char: %c\n", 'A');
	_printf("String: %s\n", "Hello, world!");
	_printf("Percent: %%\n");
        _printf("Number: %d\n", 123);
        _printf("Negative: %i\n", -456);
        _printf("Zero: %d\n", 0);
        _printf("Multiple numbers: %d, %i, %d\n", 98, -76, 1024);
	return (0);
}

