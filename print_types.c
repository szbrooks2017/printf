#include "holberton.h"
int print_percent(va_list args);
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
* print_percent - prints a percent
* @args: is the argument checked
* Return: returns the character printed
*/

int print_percent(va_list __attribute__((unused)) args)
{
	_write('%');
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
