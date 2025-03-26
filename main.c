#include "main.h"

int main(void)
{
    _printf("Printing an integer: %d\n", 1024);
    _printf("Another integer: %i\n", -2048);
    _printf("Printing a number without specifier: %s\n", "This should not be printed");
    return (0);
}
