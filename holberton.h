#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h>
#include <stdarg.h>

typedef struct specifier
{
        char* specifier;
        int(*f)(va_list);
} specifier_t;

int _write(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int (*print_format(const char format))(va_list);
#endif
