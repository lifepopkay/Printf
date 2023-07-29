#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int _putchar (char c);


/**
 * struct printing - points to format
 * and prints
 * @type: format type
 * @print: function to printing
 */

typedef struct printing
{
	char type;
	void (*print)(va_list *list);
} opr;

int _printf(const char *format, ...);

int printer(char i, va_list args);
int _strlen(char *str);
char *num_to_string(int num, char *str);

#endif
