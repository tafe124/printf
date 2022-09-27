#include "holberton.h"

/**
 * print_ord_char - Prints an ordinary char
 * @c: The char to print
 * @sum: The address of the current sum
 *
 * Return: A pointer to the updated sum
 */

int *print_ord_char(char c, int *sum)
{
	write(1, &c, sizeof(char));
	*sum = *sum + 1;
	return (sum);
}

/**
 * print_per - Prints a percent char
 * @sum: The address of the current sum
 *
 * Return: A pointer to the updated sum
 */

int *print_per(int *sum)
{
	return (print_ord_char('%', sum));
}
