#include "holberton.h"
#include <stdlib.h>
#include <string.h>
char *_strdup(char *str);

/**
* print_rot - rotated by 13
* @args: is the va list
* Return: returns the count
*/

int print_rot(va_list args)
{
	char *str;
	int i;
	int n;
	char *alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	 str = va_arg(args, char *);

	if (str == NULL)
		str = "(ahyy)";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (n = 0; alph[n] != '\0'; n++)
		{
			if (str[i] == alph[n])
			{
				_write(rot[n]);
				break;
			}
		}
		if (!alph[n])
		{
			_write(str[i]);
		}
	}
	return (1);
}

/**
* rev_string - reverses a string
* @args: is the va list
* Return: returns the count
*/


int rev_string(va_list args)
{
	int count = 0;
	int length = 0;
	char *reverse = va_arg(args, char *);

	if (reverse == NULL)
	{
		_write('(');
		_write('n');
		_write('u');
		_write('l');
		_write('l');
		_write(')');
		return (6);
	}

	while (reverse[length])
	{
		length++;
		count++;
	}
	length--;

	while (length >= 0)
	{
		_write(reverse[length]);
		length--;
	}

	return (count);
}

/**
* *_strdup - duplicate a string
* @str: the string to duplicate
* Return: the string duplicated
*
*/

char *_strdup(char *str)
{
	int len = 0, a = 0;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	while (str[len])
	{
		len++;
	}

	duplicate = malloc(sizeof(char) * len + 1);

	if (duplicate == NULL)
		return (NULL);

	while (a < len)
	{
		duplicate[a] = str[a];

		a++;
	}
	duplicate[a] = '\0';

return (duplicate);
}
