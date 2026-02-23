#include <stdio.h>

/**
 * main - Prints numbers 0-9 without using char variable
 *
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
		putchar(i + 48);
	putchar('\n');

	return (0);
}
