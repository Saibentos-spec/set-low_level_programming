#include <unistd.h>

/**
 * print_number - prints integer
 * @n: number
 */
void print_number(int n)
{
	char c;

	if (n > 9)
		print_number(n / 10);

	c = (n % 10) + '0';
	write(1, &c, 1);
}

/**
 * main - prints number of arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argv;

	print_number(argc - 1);
	write(1, "\n", 1);

	return (0);
}
