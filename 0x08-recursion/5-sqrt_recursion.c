#include "main.h"

/**
 * helper - finds sqrt
 * @n: number
 * @i: iterator
 *
 * Return: sqrt or -1
 */
int helper(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns natural sqrt
 * @n: number
 *
 * Return: sqrt or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (helper(n, 0));
}
