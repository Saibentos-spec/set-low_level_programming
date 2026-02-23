#include <stdio.h>

/**
 * main - Prints numbers 0-9 and letters a-f in lowercase
 *
 * Return: Always 0
 */
int main(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
		putchar(c);
	for (c = 'a'; c <= 'f'; c++)
		putchar(c);
	putchar('\n');

	return (0);
}
