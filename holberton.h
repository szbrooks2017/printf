#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h>
#include <stdarg.h>

/**
* struct specifier - is a new type defining a converter struct.
* @specifier: represents a conversion specifier
* @f: a pointer to a function according to the specifier
*/

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list);

} specifier_t;

int _write(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int (*print_format(const char format))(va_list);
int print_int(va_list args);
int print_d_type_int(va_list args);
int print_percent(va_list args);
int print_rot(va_list args);
int rev_string(va_list args);

#endif
