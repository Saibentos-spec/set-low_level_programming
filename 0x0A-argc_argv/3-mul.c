#include <unistd.h>

/**
 * _atoi - converts string to int
 * @s: string
 * Return: int
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; s[i]; i++)
		num = num * 10 + (s[i] - '0');

	return (num * sign);
}

/**
 * print_number - prints integer
 * @n: number
 */
void print_number(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}

	if (n > 9)
		print_number(n / 10);

	c = (n % 10) + '0';
	write(1, &c, 1);
}

/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	int result;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	result = _atoi(argv[1]) * _atoi(argv[2]);
	print_number(result);
	write(1, "\n", 1);

	return (0);
}
