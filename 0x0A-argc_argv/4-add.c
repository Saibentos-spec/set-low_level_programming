#include <unistd.h>

/**
 * is_number - checks if string is digit
 * @s: string
 * Return: 1 if valid, 0 otherwise
 */
int is_number(char *s)
{
	int i = 0;

	for (; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - converts string to int
 * @s: string
 * Return: int
 */
int _atoi(char *s)
{
	int i = 0, num = 0;

	for (; s[i]; i++)
		num = num * 10 + (s[i] - '0');

	return (num);
}

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
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		write(1, "0\n", 2);
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		sum += _atoi(argv[i]);
	}

	print_number(sum);
	write(1, "\n", 1);

	return (0);
}
