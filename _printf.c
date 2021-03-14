#include "holberton.h"

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

        if (args == NULL)
                return (-1);
        /* loop through format byte by byte until we find a null byte */
        for (indexf = 0; format[indexf] != '\0'; indexf++)
        {
                /* if there is a % i need to find what it is specifying */
                /*  i need to print what was before the specifier */
                if (format[indexf] == '%')
                {
                        indexf++;

                        if (format[indexf] == '\0')
                        {
                                return (-1);
                        }

        /* i need to continue looking through the arguements if there is a space */
                        while (format[indexf] == ' ')
                                indexf++;
                        /* fufill the specifiying need from above  */
                        operator = print_format(format[indexf]);

                        if (operator == NULL)
                        {
                                _write(format[indexf]);
                        /* wasn't sure if i needed to increment count */
                        }
                        else
                                count += operator(args);
                }
        /* if there isn't a % print what is on the stack */
                else
                {
                        _write(format[indexf]);
                        count++;
                }
        }
va_end (args);
return (count);
}
/* array struct that returns the matched argument specified */
int (*print_format(const char format))(va_list)
{
        unsigned int i;

        specifier_t type[] = {
        {"c", print_char},
        {"s", print_string},
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
