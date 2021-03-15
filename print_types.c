#include "holberton.h"

/**
* print_char - prints a string
* @args: is the argument checked
* Return: returns the character printed
*/

int print_char(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}

/**
* print_string - prints a string
* @args: is the argument checked
* Return: returns the character printed
*/

int print_string(va_list args)
{
	char *arg = va_arg(args, char*);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i]);
			i++;
		}
		return (i);
	}
	_write('\0');
	return (1);
}
