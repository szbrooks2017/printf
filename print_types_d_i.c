#include "holberton.h"
#include <stdarg.h>
void recursive(int num);
/**
 *print_int - prints integers
 *@args: type to check against
 *
 *Return: 1
 */
int print_int(va_list args)
{
	int number = (va_arg(args, int));

	if (number != 0)
		recursive((unsigned int)number);
	else
		_write('0');
	return (1);
}

/**
 *recursive - outputs digits recursively
 *@num: number to print
 *
 *Return: void
 */
void recursive(int num)
{
	int n;

	n = num;
	if (n < 0)
	{
		_write('-');
		n = -n;
	}
	if (n / 10 != 0)
	{
		recursive(n / 10);
		_write(n % 10 + '0');
	}
	else
		_write(n + '0');
}
