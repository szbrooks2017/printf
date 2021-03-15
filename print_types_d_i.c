#include "holberton.h"
#include <stdarg.h>
/**
 *print_int - prints integers
 *@args: type to check against
 *
 *Return: 1
 */
int print_int(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}
/**
 *print_d_type_int - prints integers
 *@args: type to check against
 *
 *Return: 1
 */
int print_d_type_int(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}

