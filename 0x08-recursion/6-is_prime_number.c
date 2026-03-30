#include "main.h"

/**
 * check_prime - checks if prime
 * @n: number
 * @i: divisor
 *
 * Return: 1 or 0
 */
int check_prime(int n, int i)
{
	if (i == n)
		return (1);

	if (n % i == 0)
		return (0);

	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - checks if prime
 * @n: number
 *
 * Return: 1 or 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (check_prime(n, 2));
}
