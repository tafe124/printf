#include "holberton.h"

/**
 * print_str - Prints a string
 * @args: The va_list to get the next arg from
 * @sum: The address of the current sum
 *
 * Return: The address of the updated sum
 */

int *print_str(va_list args, int *sum)
{
	int i;
	char *ptr = va_arg(args, char *);
	char *null = "(null)";

	if (ptr == NULL)
	{
		for (i = 0; null[i]; i++)
		{
			write(1, &null[i], sizeof(char));
			*sum = *sum + 1;
		}
	}
	else
	{
		for (i = 0; ptr[i]; i++)
		{
			write(1, &ptr[i], sizeof(char));
			*sum = *sum + 1;
		}
	}
	return (sum);
}

/**
 * print_char - Prints a character
 * @args: The va_list to get the next arg from
 * @sum: The address of the current sum
 *
 * Return: The address of the updated sum
 */

int *print_char(va_list args, int *sum)
{
	char c = va_arg(args, int);

	write(1, &c, sizeof(char));
	*sum = *sum + 1;
	return (sum);
}

/**
 * print_dec - Prints a decimal integer
 * @args: The va_list to get the next arg from
 * @sum: The address of the current sum
 *
 * Return: The address of the updated sum
 */

int *print_dec(va_list args, int *sum)
{
	int i, n, original_n, min = 0, pow_10 = 1000000000;
	char hold, minus = '-';

	n = va_arg(args, int);
	original_n = n;
	if ((n > -2147483648) && (n < 0))
	{
		write(1, &minus, sizeof(char));
		*sum = *sum + 1;
		n *= -1; original_n = n;
	}
	else if (n == -2147483648)
	{
		min = 1;
		write(1, &minus, sizeof(char));
		*sum = *sum + 1;
		n = (n / 10) * -1; original_n = n;
	}
	for (i = 0; i < 10; i++)
	{
		if (n % pow_10 != original_n)
		{
			if (pow_10 == 1)
				hold = n + '0';
			else
				hold = (n / pow_10) + '0';
			write(1, &hold, sizeof(char));
			*sum = *sum + 1;
			n %= pow_10;
		}
		pow_10 /= 10;
	}
	if (min)
	{
		hold = 8 + '0';
		write(1, &hold, sizeof(char));
		*sum = *sum + 1;
	}
	return (sum);
}

/**
 * print_int - Prints an integer
 * @args: The va_list to get the next arg from
 * @sum: The address of the current sum
 *
 * Return: The address of the updated sum
 */

int *print_int(va_list args, int *sum)
{
	return (print_dec(args, sum));
}
