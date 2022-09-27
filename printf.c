#include "holberton.h"

/**
 * _printf - Kiren & Alexa's implementation of printf
 * @format: The format string for which to print
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	spec_t specs[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_int},
		{"d", print_dec},
		{NULL, NULL}
	};
	int final, i, j;
	int *sum;
	va_list args;

	sum = malloc(sizeof(int));
	if (sum == NULL)
		return (0);
	*sum = 0;
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; specs[j].spec != NULL; j++)
			{
				if (*(specs[j].spec) == format[i + 1])
				{
					sum = specs[j].print_func(args, sum);
					i++;
				}
			}
			if (format[i + 1] == '%')
			{
				sum = print_per(sum);
				i++;
			}
		}
		else
			sum = print_ord_char(format[i], sum);
	}
	final = *sum;
	free(sum);
	return (final);
}
