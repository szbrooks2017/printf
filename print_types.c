#include "holberton.h"
int print_char(va_list args)
{
        _write(va_arg(args, int));
        return (1);
}

/* arguement to print a string*/
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
