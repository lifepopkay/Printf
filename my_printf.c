#include "main.h"
#include <stdio.h>

/**
 * print_character - takes the format
 * to print character
 * @list: character to print
 */

void print_character(va_list *list)
{
	_putchar(va_arg(*list, int));
}
/**
 * print_string - takes the format to
 * print a string
 * @list: string to print
 */
void print_string(va_list *list)
{
	char *s = va_arg(*list, char *);

	s = s == NULL ? "(null)" : s;
	while (*s)
	{
		_putchar(*s);
		s++;
	}
}

/**
 * print_percent - takes the format to
 * print percent
 * @list: character to print
 */

void print_percent(va_list *list __attribute__ ((unused)))
{
	_putchar(37);
	_putchar(37);
}

/**
 * _printf - prints a format
 * @format: the format to print
 * Return: returns integer
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0;
	va_list list;

	opr to_p[] = {
		{'c', print_character},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	va_start(list, format);

	while (format[i] && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			while (format[i + 1] == ' ')
				i++;
			if (format[i + 1] == to_p[j].type)
			{
				to_p[j].print(&list);
				j++;
				i++;
				break;
			}
			else
				_putchar(format[i]);
		}
		else
			_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (0);
}
