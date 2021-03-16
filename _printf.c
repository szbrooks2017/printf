#include "holberton.h"

/**
* _printf - Outputs a formatted string.
* @format: Character string to print
* Return: the number of characters printed.
*
*/

int _printf(const char *format, ...)
{
	unsigned int indexf, count = 0;
	va_list args;

	int (*operator)(va_list);

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	for (indexf = 0; format[indexf] != '\0'; indexf++)
	{
		if (format[indexf] == '%')
		{
			indexf++;
			if (format[indexf] == '\0')
			{
				return (-1);
			}
			while (format[indexf] == ' ')
				indexf++;
			operator = print_format(format[indexf]);
			if (operator == NULL)
			{
				_write('%');
				_write(format[indexf]);
				count += 2;
			}
			else
				count += operator(args);
		}
		else
		{
			_write(format[indexf]);
			count++;
		}
	}
va_end(args);
return (count);
}
/**
* print_format - sifts through arguments to find a specifier
* @format: a character string that matches arguments with specifier
* Return: returns the specifier or returns null
*/

int (*print_format(const char format))(va_list)
{
	unsigned int i;

	specifier_t type[] = {
	{"c", print_char},
	{"%", print_percent},
	{"s", print_string},
	{"d", print_d_type_int},
	{"i", print_int},
	{NULL, NULL}
	};

	for (i = 0; type[i].specifier != NULL; i++)
	{
		if (format == *type[i].specifier)
		{
			return (type[i].f);
		}
	}
	return (NULL);
}
